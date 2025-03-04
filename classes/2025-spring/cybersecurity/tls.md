# TLS

## TLS

Traditionaly, HTTP and other protocols used TCP which is a plaintext transport protocol

TCP provides phone call like semantics: dial, send/receive, data stream, hang up

TLS is a cryptographic protocol above TCP to provide a secure channel

SSL: Secure Socket Layer
- the predecessor to TLS
- broken because of weak cryptography

### Threat Model

Want to send from client to server across malicious network (the internet)

both server and client must run the same version of TLS

All internet traffic faces threat of:
- government influence and surveillance
- ISPs tracking and advertising
- compromised routers or wifi APs
- ARP spoofing, BGP route hijacking

ISPs have a lot of control over your internet experience

### Benefits and Limitations

provides Confidentiality and integrity protection for application data

How to obtain key? TLS handshake

client can authenticate server identity

does not protect against malware intrusion, phishing, denial of service or tracking by sites visited

Origin and destination sites not hidden

## Certificates

How does a client obtain the servers public key?

server presents a certificate to the browser that contains the servers public key

the certificate is signed by a certificate authority with a digital signature

CA is an entity trusted by clients to verify server identities and issue certificates

browsers trust a specific set of CAs as root CAs

there are redundant CAs in case one gets hacked

If a root CA goes rogue, it should be able to be shut down by the others

### X.509

specific format for certificates

see slides for example

fields:
- common name: subject or web server (www.google.com)
- expiration date
- subjects public key
- issuer
- issuer's signature

### Obtaining a Certificate

how does web browser Alice obtain Kbob? contained within certificate

REVIEW THIS MORE  

### Verification

To obtain a cert, server must prove its identity to the CA

Verification methods:
- email: bad if mailbox access compromised
- HTTP: place confirmation file at specific secure URL
- DNS: add record to DNS zone

### Certificate Chains

CA can delegate ability to generate certificates for certain names: intermediate CAs

### Certificate Warnings

If cert is expired, domain in URL does not match domains in cert, cert chain doesn't lead to trusted root, CA has revoked cert 
