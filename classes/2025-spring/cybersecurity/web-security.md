# Web Security

## Web Platform

collection of open standards that power websites and applications

Standardized by RFCs or open contracts

Standards: URLs, HTML, JavaScript, HTTP, TLS, etc.

### Security Goals

Protect uses from malicious sites and networks

Isolate websites that are open in different tabs; certain sites should not be able to access information from sites in other tabs

Integrity: Site A cannot affect users session on site B

Confidentiality: Site A cannot access data from Site B

## Two Tales

Client and Server side security

### Client

attacks browser security vulnerabilities

always keep browser up to date because vulnerabilities can be released in certain distributions

lots of browsers based on chromium engine

If a vulnerability is found in a popular browser, attackers can do a lot of damage

0 day vulnerability: issue in a newly released update that has not been found yet

browser attacks include:
- keyloggers and botnets
- document and data theft
- loss of private data

### Server

web servers run in data centers

background code written in PHP, JS, Python, Ruby, etc.

## History of the Web

example of bolt-on security: security was always an afterthought

the web was invented for physicists to share their research papers; only had text based web pages

Eventually, embedded images were added

Then, HTML/CSS/JavaScript was added

Modern websites are distributed applications

Web 3.0 applications are decentralized, private and secure

## Building Blocks

### HTML

HyperText Markup Language

tells the browser how to display a website

### JavaScript and DOM

JS enables the browser to read and modify page content

DOM: document object model

can reference javascript from a different page, which an attacker can use to start executing malware

### URLs

scheme: https or http

host: website address
- either mpese.com or the IP of the server machine
- DNS takes the name of the site and maps it to an IP address

port: tcp port (443 for HTTPS or 80 for HTTP)
- can usually omit

path: location of specific file on server

query: parameter string passed to server

fragment: parameter string visible only to client

### HTTP

HyperText Transfer Protocol

allows for fetching resources including but not limited to HTML

structured as a sequence of requests and responses

client sends method (get or post (submit data)), path, query and headers

server returns with a response code (200: good, 404: not found)

## Cookies

a little piece of data that a server sends to the browser

browser can store it and return it to the server later

can be used for personalization, authentication, tracking, shopping carts, etc.

clients can read, change or erase cookie data

to use cookies securely: store them cryptographically, and/or use a session identifier that is tied to a server side database

### Rules for Setting and Reading Cookies

setting a cookie: site can set a cookie for its own domain, subdomain or any public parent domain
- mpese.com can set cookies for cpsc4200.mpese.com

login.site.com can set cookies for login.site.com, site.com, test.login.site.com, but not other.site.com

same for reading

### When are Cookies Read?

other rules:
1. upper directory paths of parents can be read
2. upper directory paths of same domain can be read
3. identical paths of parent domains can be read

## Browser Execution Model

when loading a document, the browser:
1. loads content at URL
2. parses HTML and runs static inline JavaScript
3. Fetches and renders subresources (JavaScript, CSS, frames)

after loading, calls JavaScript functions in response to user input

documents can contain frames which display another HTML page inside the current one

Site A has a frame that displays Site B

Frames are isolated from the parent document

modern websites load tons of resources, which has security risks

## Same Origin Policy (SOP)

Essential Security Questions: When can one site access data from another site?

If you visit attacker.com, what stops it from reading your emails in the next tab? The Browser isolates tabs (unless they are from the same site)

What if attacker.com loads Gmail in a frame or runs Javascript from gmail.com?

SOP separates content into different trust domains and restricts data flow between them

the browser needs to make sure that JS scripts do not abuse their power

browser associates web page elements with a given origin such as https://mpese.com:443

only scripts received from an origin can access its elements

Only applies to JS scripts, does not apply to images or other static nature content

facebook can pull gmails script, but the browser will block it from running

will not be blocked in an iFrame because both have to be loaded for the page to function properly; SOP thinks its ok

clickjacking attack: hide button or in iFrame and trick user into clicking on things the don't mean to
