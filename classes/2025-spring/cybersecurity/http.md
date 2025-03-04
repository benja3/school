# HTTPS

## HTTPS is very common now

users typically fail to notice when connections unsecure

HTTPS ensures authenticity through TLS and certs

## Why we need TLS

TLS provides Confidentiality and Integrity protection using symmetric cryptography

Use TLS handshake to get key

Client can authenticate server through certs

## TLS 1.3 Handshake

TLS sessions typically reset frequently for security, but can run indefinetly after the handshake occurs

### Step 1 negotiate crypto algorithms

client sends supported algorithms and server responds with the best one

key exchange: diffie hellman

signature: RSA with SHA256

why do we use RSA on the HASHED message for signatures? to reduce their size

symmetric crypto algorithm: AES-128 (because you don't want to use RSA more than you have to because its slow)

why versatility of algorithms: multiple cipher suites exist, makes it modular, IoT devices resource constrained, TLS used everywhere

the client assumes what will be used, and if wrong, another handshake must occur

### Step 2 establish secret shared key

Use diffie hellman to derive symmetric keys

client and server both send 28 byte random and their public keys

a more complicated diffie hellman called Elliptic Curve DH

### Step 3 authenticate server

server hashes all handshake messages and signs with private key, sends its signature and the cert chain to the client. Client verifies hash and signature

need the signature to be absolutely sure that the client is communicating with the server

## Fooling Users

### Homograph Attack

use a visually similar website to trick users (umich vs urnich)

attacker acquires a legit cert and sets up a phishing site

Attackers can also use internationalized pixels for perfect text match

Some browsers protect against this with machine learning

### CA Weaknesses

If an attacker can falsely convince a CA that they control a domain, they can obtain certificates

Example: getting a cert for clemson.edu
