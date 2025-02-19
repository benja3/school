# Exam 1

## In Class

Test lockdown browser before hand

No notesheet

application question: requires a good understanding of lecture material

covers slides 1-7 and HW 1

Question 1:
- AES vs RSA
- MAC vs DS
- Vulnerable HMACs
- Padding
- AES cipher models: ECB, CBC, CTR
- properties of good hash functions
- encrypt then MAC vs Encrypt and MAC vs MAC and Encrypt

Question 2: application


Exam questions:

Cryptographic doom principle: if you perform a crypto operation on a message before checking the MAC, you are doomed.

HMAC-SHA256: 1 key
SHA256: 1 key
AES: 1 key (one direction)
RSA: 2 keys

only one time pad is PROVEN to be secure

padding oracle attack comes from MAC then encrypt

Concatenate MAC onto message, and then encrypt M || MAC


sender authenticity implies message authenticity

be able to write equations

mallory has encrypted message sent to Adam; bot sends message back out with digital signature which comes from private key; application of the private key to the public key encrypted message will decrypt it

2^k = total number of combinations

## Question / Review

Stream cipher next bit

vignere cipher

ECB (not secure)

PKCS

Problems with MAC then encrypt

RSA Key generation

Diffie Hellman Man in the Middle  attack


## Lecture Notes 1 (Introduction)

### Mindset

Security is about studying computer systems when and adversary is present. The adversary is an intelligence that tries to break the system.

Attacker strategies:
- look for the weakest links that are easy to attack
- identify assumptions of Security and try to break them
- think outside the box

Defender strategies:
- identify assets to protect and rules to enforce
- know the attackers capabilities and motivations
- perform risk assessments: what are the weaknesses and what will it cost if the system is compromised?
- design and deploy countermeasures

### Security Policies

CIA:
- Confidentiality:
- Integrity
- Availability

AAA:
- Authenticity
- Anonymity
- Accountability

### Confidentiality

Information has not been disclosed in an unauthorized way

Attack: eavesdropping

Alice sends message to Bob, but Mallory intercepts it, reads it and forwards it to Alice unchanged

Countermeasure: encryption

### Integrity

Information has not been altered in any unauthorized way

Attack: spoofing

Mallory intercepts message and changes the content before forwarding it to Alice

Countermeasure: Message Authentication Code


### Availability

Systems work promptly and service is not denied to authorized users

Attack: denial of service

Countermeasure: Intrusion detection

### Terminology

Threat: any potential occurrence that could harm an asset

Vulnerability: weakness that makes a threat possible

Attack: action that exploits a Vulnerability or enacts a Threat

Passive vs Active: Listening to collect information vs changing information to do damage

Inside vs Outside: attacker is inside vs outside security

Attack surface: medium over which the attack takes place (Network, software, human, etc.)

### Why so many problems?

Buggy code. Lack of education, awareness, funding and care.

There are always Vulnerabilities being found and exploited

## Lecture Notes 2 (Cryptography)

### Intro to Cryptography

Cryptography is the core building block of security. Involves mathematical algorithms and codes to do things like encryption and hashing

Cryptography is a great tool for many security mechanisms. But is not the solution to all problems, and should not be done yourself, because must be done correctly to be reliable.

### Final Exam Cheating

Goal: communicate answers while taking the final exam. Alice wants to talk to Bob but Mallory is in between.

approach: send a message dependent message along with the original message

bob runs m' through a function to see if the result v' is obtained

Function properties:
- should generate consistent output
- one to one mapping between m and f(m)
- be unknown to Mallory

If Mallory wants to spoof the message authentication code, she basically has to guess

### Pseudo Random Function

any size input -> fixed size output

a random function determined by a lookup table of coin flips is secure because it is true random, but impractical because both sides have to know the huge table in advance

want set of functions that look random, but are practical
- looks random: small difference of one bit will produce very different outputs
- practical: computable and do not need to share all values in advance

start with large family of functions that are all known to Mallory, and select one based on a secret key that is only known to alice and bob

PseudoRandom Function: PRF

Depends on secret key, not knowledge of the system

Kerckhoff Principles

alice sends m and f(m) = v to bob. Bob calculates f(m') to see if it is v.

replay attack: mallory resends valid messages from an earlier exam

reordering attack: mallory sends the answer to question 1 after the answer to question 2

prevent these attacks by adding a sequence number to the messages, and using a different key each time

## Lecture Notes 3 (Message Integrity)

We do not know if PRF functions actually exist, but trust ones that have not yet been broken

### Message Authentication Codes

A message authentication code is essentially the same as a MAC

Current most populat: HMAC-SHA256

HMAC: Hash-Based Message Authentication Code

### Hash Functions

Good hash functions:
- have arbitrary input size and fixed output size
- are not based on a key
- collision resistant: different messages do not have the same hash
- preimage resistant: hard to find message y where f(x) = y
- second preimage resistant: ???

Do not use: SHA-1, MD5

Use: SHA-256, SHA-512, SHA-3

hash output should be at least 256 bits; key size should be at least 128 bits

Usages:
- downloadable files have checksums; hash the file and check to make sure it is the same as the checksum
- search for duplicate files on a hard drive
- passwords on the back end of a database

### MAC instead of Hash

Hashes do not have a strong pseudorandom nature

Hash functions vulnerable to length extension attack

## Lecture Notes 4 (Confidentiality)

### True Randomness

Output of a physical process that is inherently random:
- coin flips
- human behavior
- atomic decay
- thermal noise

slow and scarce

Keys need to be truly random. Approach is to gather true random information about the computer and use an algorithm to create something true random.

adversary can guess part of it if they know about the system

OS has an API for true random

### Message Confidentiality

Want to ensure only trusted parties can read the message

Alice Encrypts the plaintext with the secret key, sends the ciphertext to Bob, and then bob decrypts with the key

Caeser Cipher: easy
- can bruteforce by shifting and comparing letter count of message to frequency chart

### Vignere Cipher

complicated and weird: review later

### One Time Pad

involves the shared key with Alice and Bob

Alice XORs message with k to encrypt, and Bob XORs ciphertext with K to decrypt
- only theoretically secure

If the pad is reused, the adversary can recover part of the message (a XOR b)

### Stream Cipher

Use psuedorandom generator instead of truly random pad

PRG inputs k and outputs a stream that appears true random unless k is known

process:
1. start with shared key k
2. alice and bob share the PRG with k
3. to encrypt, alice XORs plaintext with her generator
4. to decrypt, bob XORs

*** If either the key or the output is reused, the sequence can be saved and repeats found

Use Salsa20

### Block Ciphers

encrypts fixed size blocks with a reusable key; inverse function decrypts with the same key

block functions are pseudorandom permutations

### Psuedorandom Permutations

inputs an n bit string (block) and outputs an n bit block

*** Review Lecture for this

### Confusion and Diffusion

confusion: each bit of cipher text should depend on several parts of the key to eliminate patterns and repetition in the plain text

diffusion: changing a single bit of plain text will change a lot (at least 50%) of the cipher bits

## Lecture Notes 05 (Confidentiality)

### Data Encryption Standard (DES)

56 bit key + 8 bit parity = 64 bits total

As compute power increased, 2^56 became too easy to brute force

### Advanced Encryption Standard (AES)

most common block cipher today

believed to be secure, but this cannot be proved

128 bit blocks with variable key size (128, 192, 256)

Designed for speed

AES construction:
- round based with 10 rounds
- k expanded into 10 subkeys
- A round of manipulation performed with each of the 10 subkeys
- non linear but invertible function

### AES Modes

nonce: number used once; one time random string that is typically derived from the key

Electronic CodeBook (ECB):
- encrypt each block individually
- c = E(p) for each block
- can reveal patterns in the plaintext
- DO NOT USE

Cipher Block Chaining (CBC):
- encrypt a block and then use the resulting ciphertext from this block instead of plaintext as the input to the next block
- use new initialization vector for each message

Counter (CTR):
- maintain a counter and set nonce = counter XOR key
- encrypt the nonce with AES and the key, then XOR the plaintext with that string
- can be easily parallelized
- use different nonce for each message

### Cryptographic Doom

USE ENCRYPT THEN MAC

Cryptographic doom principle: if you perform any cryptographic operation before verifying the MAC, you are doomed

Use Encrypt then MAC to enforce Confidentiality and Integrity
- if the any is changed, the MAC will catch it; the encrypted message cannot be read

## Lecture Notes 6 (Key Exchange)

### Symmetric Key Cryptography

So far, Alice and Bob have been sharing the key in advance off the air

Alice and Bob can actually have a public conversation and derive a shared key

### Diffie Hellman

1. Alice and Bob agree on public parameters
- p: a large "safe prime"
- g: small generator integer

2. Alice Generates random secret value A and Bob generates random secret value B

3. Alice sends g^A mod p to Bob, Bob sends g^b mod p to Alice

4. g^(a * b) mod p is key

WRITE OUT ON PAPER

### DH Man in the Middle



### Key Management

each key should have only one purpose

key vulnerability increases
- the more it is used
- the more places it is stored
- the longer it thas been around

forward secrecy: knowing an old key won't help an attacker learn a new one

Problem: these keys do not verify integrity. Solution: public key crypto

## Lecture Notes 7 (Public Key Cryptography)

### Public Key Cryptography

Also known as asymmetric cryptography

Idea: each party has a pair of keys (J and K)
- J is public key and K is the private key

Cannot compute K from J, but can compute J from K

### RSA

can be used for encryption and digital signature

way slower than AES

Review key generation

Alice and Bob know each other's public keys

Idea: Alice encrypts with Bobs public key so only Bob can decrypt it with his private key

Anyone who has Bob's public key can encrypt a message for him, but only he can decrypt it

### Digital Signature

Bob needs to know the message is coming from Alice because anyone can send a message to him

Idea: Alice encrypts (signs) with her private key and bob decrypts (verifies) with Alice's public key

Since only alice has her private key, the message must be from her

### Extras

RSA is needed to distribute the key for AES since Diffie Hellman key exchange fails with a man in the middle attacker

### RSA with Diffie Hellman

1. establish shared key k with diffie hellman without caring if mallory is on the channel
2. verify RSA signatures on k to check for man in the middle attacker; Bob and Alice prove that they are talking to each other (would fail if mallory was there due to RSA)
3. split k into 4 keys with PRG
4. encrypt with symmetric cipher and add MACs for integrity

### RSA without Diffie Hellman

1. Alice generates key k and encrypts it with Bob's public key and send it to Bob
2. Bob decrypts k with his private key
3. use RSA signatures on the ciphertext to prevent mallory from changing it
4. use k to create 4 keys
5. encrypt with symmetric cipher
