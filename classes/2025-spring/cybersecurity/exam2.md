# Exam 2

Lecture notes 8-15 and homework 3

check email for accommodations

Potpourri:
- data injection attacks (SQL, XSS)
- SOP (Same Origin Policy): defense preventing one website from accessing data from another
- TLS properties
- TCP attacks (SYN flood, Reset, etc.)
- Certificate Authorities
- DNS
- Basic Linux shell commands (shell injection)

Part 2 HatGPT:

ChatGPT like web application with vulnerabilities like XSS, CSRF, SQL (2 of these)

Need to write basic HTML forms and JS

### How to Study

Review Videos and Slides

Midterm 2 review slide set

For each web attack, identify vulnerable code and be able to exploit it

known HTML:
- form
- p
- script
- input

to prevent SQL injection "prepared statement"

stored XSS involves writing to the data base

To prevent CSRF, use and verify secret values

### Review

HTTP Post (cross origin for CSRF attack)

almost all layers and protcols have checksums

TCP uses 16 bit checksum, which is not cryptographically secure

DNS is an application layer protocol

# Slides

## 8: Web Security

Confidentiality: Site A cannot access data from Site B

Integrity: Site A cannot affect the user session of Site B

Security Principle: Isolate websites in the browser

Web uses bolt on security: security was/is added as it is needed

### Two Sides

Client (Web Browser):
- attacks security weaknesses in the browser
- attempts to install malware, steal information

Server (Web App):
- system where the distributed web application is running

### Web Structure

DOM: document object model

URL format: scheme://host:port/path?query#fragment
- scheme: protocol to use (HTTPS)
- host: servers domain name or IP
- port: TCP port on the server
- path: identifies and locates resources on the server

### HTTP

Used for fetching resources from a server, like index.html

Structured as a sequence of requests and responses

client sends:
- method (GET or POST)
- path and query
- headers

GET retrieves data and should not change the server

POST submits data and does typically update the sever

server returns:
- response code (200 OK, 404 not found)
- headers
- content (arbitrary bytes)

### HTTP Cookies

Pieces of data that the server sends to the browser

Can be stored and/or send back to the server later

Uses:
- maintaining state
- personalization
- tracking

## 9: Web Security Part 2

### HTTP Cookies

Clients can manipulate cookie data with JavaScript

Can set cookies in an HTTP header

Secure use:
- make sure data is cryptographically protected
- use a cryptographically secure session ID tied to the server

### Browser Execution Model

Process for loading document:
1. Load content at URL
2. Parse HTML and run inline JavaScript
3. Fetch and render subresources like images, CSS

The LA times accesses resources from 270 external IPs

### Same Origin Policy

Security Question: When can one site access data contained in another

Separate content into different trust domains and restrict data flow between them

Sites isolated from all others

Simple version:
- browser associates web page elements with a given origin IP:port
- only scripts from that pages origin can access its elements

XSS breaks this

look for the src="https://ip:host" section

IF SCHEME AND PORT ARE DIFFERENT, ORIGIN IS DIFFERENT
- http is different from https
- website.com is different from www.website.com

the HTTP fetch works, but the script is prevented from executing by the browser

iFrames can introduce clickjacking attacks, when the iFrame is large and transparent, so the user's click interacts with the iFrame and not the host webpage

content in iFrames not prevented from loading because they have their own origin

if you have bank.com open in a separate tab and a malicous website loads chase.com in an iFrame, SOP will not prevent the iFrame instance from accessing your other tab

## 10: Web Attacks

### Authentication Cookies

Login's are HTTP posts with the username and password data. The site responds with an unguessable number which is the authentication token.

browser presents the cookie in later requests for validation

Cookies for a parent domain are set to subdomains automatically

Cookies for subdomains are not sent to parent domains unless they are directly requested by Domain = .bank.com

Cross origin images are not blocked by SOP

If you are on attacker.com and load an image from bank.com, the cookie from bank.com is set

### CSRF Attack

Tricking the user's browser to perform unwanted actions on a different site

exploits trust that site has in the user's browser

target state changing requests

on attacker.com, load the resource bank.com/transfer?to=attacker,amount=10000

SOP prevents reading the response, but bank.com still executes the command

Can be done with GET or POST

Attack relies on cookies being attached to any request to a domain. Need a way of validating requests before cookies are sent.

Referer validation:
- Includes the origin page URL in the HTTP request header
- authenticate each user action that originates from the site

Secret Token Validation:
- pages embed a secret value in each request, which the server validates

SameSite Cookies:
- Strict: cookie is not sent in any cross site context
- Lax: cookies only sent when navigating to the origin site

### XSS Attack

Cross Site Scripting

Client side injection attack

Inject JS code where regular inputs are expected

exploits sites that send untrusted inputs to browsers without proper validation

Malicious JS code is executed on victims browser

Reflected XSS: script effects the user who navigates to the malicious URL

URL routes take values from the URL and pass them into a function in the web application
- example: @app.route('/hello/John') -> hello("John")
- Can manipulate this by sending a script where a name is expected

Stored XSS: stores malicious code in the server
- example: user sets bio to JS script and anyone who views the user's profile and loads the bio executes the script
- much more dangerous than reflected

Defense:
- input validation
- output escaping
- content security policy: restrict execution of certain scripts

## 11: HTTPS

### Why TLS?

TCP is a plaintext transfer protocol and does not provide Confidentiality, Integrity or Authentication

TLS: Transport Layer Security

cryptographic protocol layered above TCP

HTTPS = HTTP over TLS

Any internet traffic is subject to man in the middle attacks or surveillance from government, ISP, etc.

The client can authenticate the server's identity with TLS

TLS does not protect against:
- intrustions on the client/server
- phishing
- tracking
- denial or service

### Certificates

How does a client obtain the server's public key

Server provides a certificate that includes the public key and other information

Certificates are signed by a Certificate Authority using digital signatures

There are several root CA's

security of the whole internet is as strong as the weakest CA

## 12: HTTPS Part 2

HTTPS is now ubiquitous; almost all websites use it

### TLS Handshake

1. Negotiate Crypto Algorithms
- select key exchange algorithm, signature algorithm, and symmetric crypto algorithm
- to save time, client guesses, and if it is wrong, starts a new handshake

2. Use Diffie Hellman to establish shared key
- client and server both generate parameters and share
- generate shared key from parameters
- diffie hellman used for forward secrecy (if the keys for this Handshake are found, a new handshake will have completely different keys)
- these keys used for all encryption and decryption of data

3. Authenticate server
- hash all handshake messages and sign with private key
- server sends the signature and the certificate to the client
- client verifies using the public key from the cert

### Homograph Attack

Attacker obtains a cert for a visually similar website and pretends to be the original

umich.edu vs urnich.edu , google.com vs gooogle.com

Can be done with international characters that appear identical to english ones

### Phishing

Many phishing sites have valid certs so HTTPS cannot prevent it

Google uses ML to identify phishing sites

### Other Attacks

Attackers can falsely convince a CA that they control a domain by creating a deceptive email or a man in the middle attack during the cert creation

CA's can get hacked

## 13: Networking 101

DNS is an application layer protocol, so is HTTP

all layers have some form of checksum

ARP broadcast: who has IP A

REVIEW: details of TCP connection establishment and termination

### DNS

turns a website name into an IP

Recursive process

Starts at root servers and cascades down

google.com: start at root and find com -> go to com and find google.com

DNS is a UDP protocol 
