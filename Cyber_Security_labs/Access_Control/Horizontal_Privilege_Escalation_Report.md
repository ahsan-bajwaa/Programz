# Horizontal Privilege Escalation: Lab Report

| | |
|---|---|
| Author | Ahsan Rehman |
| Date | 30 September 2026 |
| Platform | PortSwigger Web Security Academy labs |
| Category | Broken Access Control (OWASP Top 10, A01) |
| Tools | Burp Suite (Proxy, Repeater), browser view-source |
| Overall severity | High |

##  1. What is Horizontal Privilege Escalation?
    Horizontal Privilege Escalation means that normally user can access there own data from their account, but in this case if some can access the data from his account as well as for the other user account. Think like a example of studnet ERP, normally where each studnet have access to their own account, but they can't see grade of other classfellow, but if studnet A can see accound details of studnet B then it will be called Horizontal Privilege Escalation of Access Control.

##  2. My Findings

##  2.1 User ID controlled by request parameter:
    **What it is** Anyone can access other user account by changing the ID in URL to access all data of his.
    **Why it works** Developer thought everyone will login and forgot to add the check if he is a real user and entered crenditals or not.
    **Steps**
    Open a webiste with normally, URL is as:
    https://insecure-website.com/my-account?id=wiener
    Now there is another user name carlos, we can replace wiener with carlos to access it. Now crenditals required.
    **Fix** Add a check to verify that if the user entered the crenditals to login that specific account othewise don't allow it.

##  2.2 User ID controlled by request parameter, with unpredictable user IDs:
    **What it is** Username are written as it is, GUID(Globally Unique Identifier) are used instead so that no one can predict the name.
    **Why it works** If the webiste contain data of user like comment or review and there GUID can be scene and used to swtich account with login.
    **Steps**
    Open the blog of the user you want to bypass login, and copy the element to the account in the aspect view of page:
    <a href="/blogs?userId=4518e11a-5807-4bf8-a61b-b35519ad6afa">carlos</a>
    Now we can replace the GUID of carlos with current user.
    https://insecure-website.comt/my-account?id=12193c03-6a1c-48d1-af3c-84b16fbe238c
    **Fix** Don't just through the GUID in blog or any commnet, instead just show the name, that is enough and senstive things should be handled on server side.

##  2.3 User ID controlled by request parameter with data leakage in redirect:
    **What it is** User can see content of other user before redirect of page which contain other user data.
    **Why it works** When you tries to change the id from URL to switch user, server give two responses, one of them '302 error' and '/login' and webiste ignore first one without showing the '302 error' containing whole information of user. By using Burp Suite we can see all data.
    **Steps**
    Open the webiste and login as normal user in Burp Suite connected browser, capture the request and send it to repeter.
    https://insecure-website.com/my-account?id=wiener
    Change the username from wiener to carlos in GET request as this:
    GET /my-account?id=carlos HTTP/2
    **Fix** Instead of using tecneque of redirect, use the real check weather he is a logged in that account or not.




