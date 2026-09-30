# Vertical Access Control: Lab Report

| | |
|---|---|
| Author | Ahsan Rehman |
| Date | 30 September 2026 |
| Platform | PortSwigger Web Security Academy labs |
| Category | Broken Access Control (OWASP Top 10, A01) |
| Tools | Burp Suite (Proxy, Repeater), browser view-source |
| Overall severity | High |

## 1. Summary

This report covers the first type of access control, vertical access control, and the labs I did for it. I tested seven different ways a website can fail to protect its admin functions. In every lab I started as a normal user (or with no account) and ended up using admin features like the admin panel and deleting users. The report explains why each one works, how I did it, what damage it can cause and how to fix it.

## 2. Background

### What is access control?

Access control decides who is allowed to do what on a website. A simple way to think about it is a office building with key cards. The server room only opens for the tech team, the CCTV room only opens for security, and the manager's office only opens for the manager. A website works the same way: a normal customer, a seller and an admin should each only get the things that belong to their role.

It depends on three things working together:

1. **Authentication**: confirming who the user is (login).
2. **Session management**: knowing which later requests come from that same user.
3. **Access control**: deciding if that user is allowed to do the thing they are asking for.

Something I mixed up at first: making an account and logging in is authentication, not access control. Access control is what happens after the site already knows who you are.

### Types of access control

There are three main types: vertical, horizontal and context-dependent. This report only covers vertical.

### What is vertical access control?

Vertical access control limits sensitive functions to users with a higher privilege level. For example, an admin can delete users but a normal user can't. It supports two ideas: least privilege (users only get what they need) and separation of duties. A vertical access control failure means a lower-privileged user can reach something meant for a higher one, which is called vertical privilege escalation.

## 3. Findings

### 3.1 Unprotected admin functionality

**What it is:** The admin panel has no protection at all. Anyone who knows the URL can open it.

**Why it works:** The developer only assumed nobody would find the page. There is no server-side check for who is asking.

**Steps:**
1. Open the site as a normal user (or not logged in).
2. Go to `https://insecure-website.com/admin`.
3. The admin panel opens without asking for admin credentials.


**Impact:** Anyone can use admin features, including deleting accounts.

**Fix:** Every admin page must check on the server that the user is really an admin, and access should be denied by default.

### 3.2 Hidden admin URL leaked in robots.txt

**What it is:** The developer changed the admin URL to something less obvious, then listed it in `robots.txt`.

**Why it works:** `robots.txt` is a public text file in the root of the web server. It tells web crawlers which paths to skip. It does not block anyone from visiting those paths, and since anybody can read it, it actually shows attackers where the sensitive pages are. Hiding a page and hoping nobody finds it is called security through obscurity, and it is not real security.

**Steps:**
1. Open `https://insecure-website.com/robots.txt`.
2. Find the line `Disallow: /administrator-panel`.
3. Add that path to the site URL and the admin panel opens.

**Impact:** Same as 3.1, the admin panel is fully accessible.

**Fix:** Don't list sensitive paths in `robots.txt`, and protect them with real authentication and authorization.

### 3.3 Admin URL leaked in JavaScript

**What it is:** The developer used a hard-to-guess admin URL, like `/administrator-panel-yb556`, but the URL is inside JavaScript on the page.

**Why it works:** The script is sent to every visitor, not only to admins. Any user can open the page source and read the whole logic, including the secret URL. This is the code I found:

```html
<script>
    var isAdmin = false;
    if (isAdmin) {
        ...
        var adminPanelTag = document.createElement('a');
        adminPanelTag.setAttribute('href', 'https://insecure-website.com/administrator-panel-yb556');
        adminPanelTag.innerText = 'Admin panel';
        ...
    }
</script>
```

**Steps:**
1. Open the site and view the page source (or use the browser inspect tool).
2. Find the script and copy the admin URL.
3. Visit the URL directly. The admin panel opens.

**Impact:** The hidden admin panel is exposed to any visitor.

**Fix:** Never put sensitive URLs or access logic in client-side code. The server has to make the access decision.

### 3.4 Role controlled by a cookie

**What it is:** The site decides if you are an admin using a cookie value that the user can edit.

**Why it works:** Anything sent from the browser can be changed by the user. Burp Suite lets me capture the request and edit it before it goes out. When I opened the admin page normally, it said I need to be logged in as admin. In the captured request I found this cookie:

```
Cookie: Admin=false
```

**Steps:**
1. Log in as a normal user and try to open the admin page. Access is denied.
2. Capture the request in Burp Suite.
3. Change `Admin=false` to `Admin=true` and send it.
4. The admin panel opens.


**Impact:** Any user can make themselves admin just by editing one value.

**Fix:** Keep the user's role on the server (for example in the session) and never trust a role value that comes from the client.

### 3.5 Role changed through the profile update request

**What it is:** The site lets the user update their profile (for example the email), but it also accepts extra fields that the user was never supposed to change.

**Why it works:** The server takes the fields from the request and saves them without checking which ones the user is allowed to change. In this lab an admin has `roleid` 2 and normal users have 0 or 1. If the site's response shows the user data, we can see which fields exist. If it doesn't, extra field names can be guessed using Burp Repeater: a valid field goes through without an error and a wrong one gives an error.

**Steps:**
1. Log in as a normal user and send the "change email" request to Burp Repeater.
2. Look at the response and notice that it includes a `roleid` value.
3. Add `"roleid": 2` to the request body and send it.
4. My account is now admin and I can open the admin panel.

<!-- CHECK: I believe this lab sends JSON, not XML. Confirm in your Burp history and fix this line if needed. -->


**Impact:** A normal user can upgrade themselves to admin.

**Fix:** Only accept a fixed list of fields from users for each request. The role should only be changeable through an admin-only function.

### 3.6 Bypassing a front-end block with X-Original-Url

**What it is:** The front-end blocks normal requests to `/admin`, but the back-end supports a header that overrides the URL.

**Why it works:** The front-end system checks the URL in the request and blocks `/admin`. The back-end, however, reads the `X-Original-Url` header and uses that as the real path. So the two parts of the system see different URLs, and the block is skipped. I had to use Burp Suite for this because the browser won't let me set that header. The header only takes the path, so the query string stays in the normal request line.

The delete link on the admin page looks like this:

```html
<a href="/admin/delete?username=wiener">
```

**Steps:**
1. Request `/admin` normally. It is blocked.
2. In Burp Repeater send:

```
GET /?username=carlos HTTP/2
X-Original-Url: /admin/delete
```

3. The user `carlos` is deleted.


**Impact:** The admin restriction is bypassed and admin actions can be performed.

**Fix:** Turn off URL-override headers on the back-end, and do the access check in the application itself, not only in the front-end.

### 3.7 Bypassing the check by changing the HTTP method

**What it is:** The developer added an access check for one HTTP method (POST) but forgot the others.

**Why it works:** Only administrators are allowed to change other users' permissions. As a normal user, my POST request for this was rejected. When I changed the same request to GET, the server did the action anyway because the check was not applied to that method.

**Steps:**
1. As an admin, capture the request that changes a user's role.
2. Log in as a normal user and replay it. It is rejected.
3. In Burp Repeater, change the method from POST to GET (parameters stay the same) and send it.
4. The role change goes through.

<!-- CHECK: add the real endpoint name and parameters from your lab here -->


**Impact:** A normal user can change permissions, including their own.

**Fix:** Apply the same access check to every method (GET, POST, PUT and so on), and deny anything that isn't explicitly allowed.

## 4. What I did not test

- URL matching problems (for example uppercase paths, a trailing slash, or extra file endings on a protected path).

## 5. Overall recommendations

- Enforce access control on the server for every request.
- Deny by default, and only allow what is needed.
- Never trust anything the user can edit (cookies, parameters, headers, JSON fields, scripts).
- Don't rely on hidden URLs or `robots.txt` for protection.
- Check permissions the same way for all HTTP methods.
- Test each feature with every role, not only with the admin account.

## 6. What I learned

- Login (authentication) and permissions (access control) are different things, and I mixed them up at the beginning.
- Every failed defense had the same root cause: the site trusted the client or hoped it wouldn't be found. Hiding something is not the same as protecting it.
- Burp Suite matters a lot here, because a normal browser hides most of what I need to edit.
- Two systems that read the URL differently (like in 3.6) create a gap that attackers can use.

## 7. References

- PortSwigger Web Security Academy, Access control vulnerabilities and privilege escalation
- OWASP Top 10, A01 Broken Access Control
