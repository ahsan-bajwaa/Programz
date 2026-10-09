##  What is authentication:
When we talk about authentication then we have to understand two terms difference, says authentication vs authorization. Authorization mean checking that wheather user is allowed to perfrom the action. And this whole process is managed by authentication. Take a example of your university, when you enter the building then you use your key card to enter, and the tap machine checks that are you in the record of university as a studnet, this process is called authentication, and authroization is like you can enter in university but you can't enter the server room or touch any computer in there. Only the IT member are allowed to enter. 

## Brute forec:
For a website protal, brute force attack is a type of attack where you tries every possible combination that can be used to authenticate to be authorizated user. 

## Lab work:

## 1.1 Username enumeration via different responses:
It is very basic type of attck where we have to brute force the username to determine, usually webiste show `Invalid username or password`, but here webiste show that username is worng specfically, which is really bad, and it will lead to brute force it. In lab we were provided with a world list, we have to put it in Burp Suite Intruder and try to snipe out every possible combination of it. If we found any username as a correct, the server webiste will give us different result, and we will be keep our eye out to see the difference. When it was correct, it told use the password, long beore it was saying that username is wrong. Now we are sure exact username. Now we will do the same for the password, using the word list to find it out and hence we solved our lab that way...

## 1.2 Username enumeration via subtly different responses:
It was same as above attack, but instead of showing that username is wrong it have a slightly different response. When the username is wrong it say: `Invalid username or password.`, and when username is right, then it skips the last dot `.`. So it gives us the difference so we can brute force it easily, since we know the username by the tecnique, we can find the password, as right one will let us login in account.=
