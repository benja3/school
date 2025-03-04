# Web Attacks

## Authentication Cookie

upon successful login, server sends a cookie with an unguessable random value called the authentication token

server stores token, username and expiry time

another cookie rule: cookies set for a subdomain are not sent to the parent domain unless explicitly set with Domain=.bank.com

cookies sent by browser are determined by the domain of the resource being requested

if attacker.com loads image from bank.com, bank.com cookie loaded

if cross domain resources loaded, also loading the cookie for that resource

## CSRF Attack

Cross-Site Request Forgery

cause users browser to perform unwanted actions on a different site on a users behalf

browser things you are trying to load an image and sends a get request, but get request can be a URL with a command

## CSRF Defenses

rely on the fact that cookies are attached to any request in a domain

need some request authentication method

### Referer Validation

Referer HTTP request header contains URL of page making request so sites can identify where visitors come from

goal: authenticate that user actions come from our site

complication: referer not always sent
- attacker or browser can disable

### Secret Token Validation

every form contains a secret value or session token that the server validates

### SameSite Cookies

SameSite prevents browser from sending cookie in cross site request

strict: cookie isnt sent in any cross site context

lax: cookies not set on normal cross site subrequests

SameSite cookies are new default in Chrome since 2019

## Injection Attacks

exploit vulnerabilities that mistake untrusted data for code, allowing for specially crafted inputs to cause execution of malicious instructions

types:
- SQL injection
- cross site scripting
- shell injection
- control hijacking

## SQL Injection

occur when a program passes unsanitized inputs into SQL database statements

easy to avoid, but common and dangerous

see slides for examples

server side attack

### SQL Injection Prevention

need to separate code from data

can escape certain control characters that make the attacks possible

## Cross Site Scripting (XSS)

attackers malicious is executed on the victims browser

client side attack

Reflected XXS: echoes script back to the same user

Stored XXS: stores malware in a resource managed by the server where it can target multiple users

### Reflected XSS

vulnerability: site echoes inputs back to user without properly escaping them

exploitation: user follows malicious link to the site that executes the script, and sends data to the attacker

inserting code in a place where you should be putting static data like text

### Stored XXS

Javascript executes when site is rendered by the users browser

### defense

input validation: alpha numeric only, or don't allow certain characters

output escaping

Content Security Policy: 
