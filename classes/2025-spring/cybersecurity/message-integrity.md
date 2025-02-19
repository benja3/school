# Message Integrity

Confidentiality: prevents against eavesdroppers

Message Authentication codes: prevents against spoofing

Cryptography is a tool that can be used in different projects to add security

Cryptography is not the solution to all security problems

Use libraries to do Cryptography, do not try to do it yourself because its fun

Goal: learn to use cryptographic primitives correctly

treat primitives like black boxes and use libraries to work with them

always assume there is an adversary on an untrusted communication medium

Bob -> Mallory -> Alice

Mallory could either change the message, or do nothing and read it

### Countermeasures

Alice sends m and v, bob recieves m' and v' which may or may not have been spoofed

v is the output of shared function f(m)

Use shared function to check if f(m') == v'

function f should generate consistent output and needs to have a 1 to 1 mapping between m and f(m); two messages should not produce the same output ; function also must be unknown to mallory

this will only work if alice and bob can decide on the function off of the untrusted medium

function should handle any input size and output a fixed length output

longer output more secure because less of a chance to guess

pseudorandom function must be practical, not a massive look up table

start with a family of functions that are all known to mallory, and pick one depending on a secret key known only to Alice and Bob

there are only around 100 good hash functions, so assume mallory knows the function

can multiplex the message with the key before it is passed to f to make it near impossible to guess

smallest key size is 128 bits

### Kerckhoffs Principles

1. System must be practically indecipherable
2. Should not require secrecy

As long as the secret key is not leaked, any other part can be leaked

opposite of kerckhoff: hide everything (security by obscurity)
- reverse engineering can easily break this

### Multiple Messages

replay attack: resend earlier messages and replace current ones

reordering attack: switch the orders of messages

to prevent this, add a freshness value or a counter so the receiver knows when it was sent

can also use a different key each time, but this is not optimal

### More PRFs

no one can prove that a PRF is perfect

HMAC-SHA256 is the current best; no one has broken it yet

### Message Authentication Code (MAC)

lots of MACs out there

MAC is the same as a PRF essentially

HMAC: Hash based MAC

SHA256 is the function f

SHA256(key XOR constant CONCAT SHA256(key XOR constant CONCAT SHA256( ...)))

called SHA256 because: Secure Hash Algorithm with 256 bit output

### Good Hash Functions

Collision resistance: hard to find x and y such that h(x) = h(y)

Preimage resistance: given y, hard to find x such that f(x) = y

Second preimage resistance:

SHA-1 and MD5 functions have been broken

Merkle-Damgard functions susceptible to length extention attack (HW 1)
- SHA3 not MD

### Bad Hash Functions

Hash output should always be twice as large as recommended key size

salt: prepend data to the message before hashing

### Hash Function Examples

downloading software: hash the entire download to generate a hashsum, and compare the final download hash to check for corruption

de duplication: search for duplicate files on hard drive

password authentication security; passwords also salted before hash

HVAC used for integrity, hash function used for a bunch of other stuff
