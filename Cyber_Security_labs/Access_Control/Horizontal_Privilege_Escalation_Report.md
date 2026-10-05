# Horizontal Privilege Escalation: Lab Report

| | |
|---|---|
| Author | Ahsan Rehman |
| Date | 30 September 2026 |
| Platform | PortSwigger Web Security Academy labs |
| Category | Broken Access Control (OWASP Top 10, A01) |
| Tools | Burp Suite (Proxy, Repeater), browser view-source |
| Overall severity | High |

---

## 1. Introduction

### 1.1 What is Horizontal Privilege Escalation?

Horizontal privilege escalation happens when a user can access resources that belong to another user who has the same level of privilege.

Think of a student ERP as an example. Normally each student can only access their own account, and they can't see the grades of their classfellows. But if student A can see the account details of student B, then it is called Horizontal Privilege Escalation (a type of Access Control failure).

### 1.2 Scope and Tools

All testing was done on PortSwigger Web Security Academy labs. I used Burp Suite (Proxy and Repeater) to capture and change requests, and browser view-source to read the page code.

---

## 2. Summary of Findings

| # | Lab | Issue | Severity |
|---|-----|-------|----------|
| 3.1 | User ID controlled by request parameter | ID in URL can be changed to another user | High |
| 3.2 | Unpredictable user IDs | GUID leaked on blog pages | High |
| 3.3 | Data leakage in redirect | Other user's data inside the 302 response | High |
| 3.4 | Password disclosure | Password visible in page source | High |
| 3.5 | Insecure direct object references | Chat transcripts can be downloaded by changing file number | High |
| 3.6 | Multi-step process, no access control on one step | Second step skips the check | High |
| 3.7 | Referer-based access control | Referer header can be faked | High |

---

## 3. Detailed Findings

### Part A: User ID and Object Reference Issues

#### 3.1 User ID controlled by request parameter

**What it is**
Anyone can access another user's account by changing the ID in the URL, and get all of their data.

**Why it works**
The developer thought everyone will login properly and forgot to add a check that the logged in user is really the owner of that account.

**Steps**
1. Open the website normally. The URL looks like this:
   `https://insecure-website.com/my-account?id=wiener`
2. There is another user named carlos. Replace wiener with carlos in the URL.
3. The account of carlos opens. No credentials required.

**Fix**
Add a check on the server that the logged in user is the same user whose account is being requested. If not, don't allow it.

---

#### 3.2 User ID controlled by request parameter, with unpredictable user IDs

**What it is**
Usernames are not used in the URL. GUIDs (Globally Unique Identifier) are used instead, so that no one can predict the ID.

**Why it works**
If the website shows user data like comments or reviews, the GUID of that user can be seen there and then used to switch to that account.

**Steps**
1. Open a blog post written by the user you want to access.
2. Copy the user's GUID from the page code (view-source):
   `<a href="/blogs?userId=4518e11a-5807-4bf8-a61b-b35519ad6afa">carlos</a>`
3. Replace the GUID of the current user in the URL with the GUID of carlos:
   `https://insecure-website.com/my-account?id=12193c03-6a1c-48d1-af3c-84b16fbe238c`

**Fix**
Don't throw the GUID in blogs or comments, just show the name, that is enough. But hiding the GUID is not the real fix, sensitive things should be handled on the server side (check the logged in user on every request).

---

#### 3.3 User ID controlled by request parameter with data leakage in redirect

**What it is**
A user can see the content of another user inside the redirect response, before the page redirects. That response contains the other user's data.

**Why it works**
When you change the ID in the URL to switch user, the server gives two responses. The first one is a `302` redirect to `/login`, and the browser ignores it without showing it. But that `302` response already contains the whole information of the user. Using Burp Suite we can see all the data.

**Steps**
1. Open the website and login as a normal user in the Burp Suite connected browser.
2. Capture the request and send it to Repeater:
   `https://insecure-website.com/my-account?id=wiener`
3. Change the username from wiener to carlos in the GET request:
   `GET /my-account?id=carlos HTTP/2`
4. Check the response in Repeater, the data of carlos is inside the 302 response.

**Fix**
Don't depend on a redirect. Do the real check whether he is logged in to that account or not, and don't put user data in the response if the check fails.

---

#### 3.4 User ID controlled by request parameter with password disclosure

**What it is**
Anyone can see the saved credentials of another user in the page source and steal the account.

**Why it works**
When the ID in the URL is changed from a normal user to administrator, the page shows the account, and the password of that account is visible in the page code (inspect).

**Steps**
1. Open the website: `https://insecure-website.com/login`
2. Login as a normal user. The URL looks like this:
   `https://insecure-website.com/my-account?id=wiener`
3. Change the ID from wiener to administrator.
4. Open inspect / view-source, and the password of the account is there:
   `<input required="" type="password" name="password" value="jg1og3iigozm68hgdawv">`

**Fix**
Don't send the password back in the page when user logs in. Also add proper authentication before allowing a user to see the account details.

---

#### 3.5 Insecure direct object references (IDOR)

**What it is**
Live chat history reveals the sensitive information of other users.

**Why it works**
When anyone downloads the transcript, the website creates a new file with a number in the name, and the number just goes up. Using Burp Suite we can change the file we want to download.

**Steps**
1. Open the website and login as a normal user.
2. Go to live chat with the bot, send some messages and click on transcript.
3. It creates a file named `2.txt`, which means older data is in `1.txt`.
4. Using Burp Suite, change the request from 2 to 1:
   ```
   GET /download-transcript/2.txt HTTP/2
   Host: insecure-website.com
   ```
5. The response is the chat history of another user:
   ```
   You: Ok so my password is rfqoh31bdn60fodtae7y. Is that right?
   Hal Pline: Yes it is!
   ```

**Fix**
Don't expose server files directly like this, and add verification before downloading, so only the right user can download his own transcript.

---

### Part B: Multi-step and Header Based Access Control

#### 3.6 Multi-step process with no access control on one step

**What it is and what it can do**
The website adds two steps of verification before giving admin access. The issue is it validates the user in the first step, but in the second step it skips the verification. So anyone who has that request can change it and upgrade any user (even himself) without authorization.

**Steps**
1. Open the website and login using admin credentials.
2. Open Burp Suite and look at the HTTP request history in the Proxy section. The first request looks like this:
   `username=carlos&action=upgrade`
   The server checks here that the user is authenticated or not.
3. The second (confirmation) request does not check it:
   `action=upgrade&confirmed=true&username=wiener`
4. Send this second request again using the normal user session, and the user becomes admin.

**Fix**
Add authentication and authorization to both requests. The second request leads to unauthorized access that can make any user an admin.

---

#### 3.7 Referer-based access control

**What it is and what it can do**
The website relies on the `Referer` header to decide if the request is allowed. If anyone can edit it and set it to the admin page, then a normal user can act as admin and promote himself to admin.

**Steps**
1. By default the Referer header looks like this:
   `Referer: https://insecure-website.com`
2. Change the request so the Referer points to the admin page, and the user can be promoted:
   `GET /admin-roles?username=wiener&action=upgrade`

**Fix**
Don't rely on the Referer header, because the user controls it. Check the user's role on the server side for every admin action.

---

It is a last report of Access control..
