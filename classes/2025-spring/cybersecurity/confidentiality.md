# Confidentiality

How to make sure eavesdroppers cannot read content of a message

a goal of Cryptography is approaching true randomness practically

random number generators uses OS provided API, how does this work?

### True Randomness

Physical processes that are inherently random (quantum)

Hard to find and use these

These processes are slow

### pseudorandom generator (PRG)

takes seed or key that is truly random and generates a long sequence of numbers that seem random

PRF (HMAC) vs PRG

### Sources of Randomness

Coin Flips

Human behavaior

atomic decay

thermal noise (temp of CPU)

electromagnetic noise

### Where to get randomness

key needs to be truly random

gather details about computer that the adversary will have trouble guessing, such as temperature, clock time, mouse position, etc.

If the adversary has access to some of components such as the mouse position, can get some predictability

Combine multiple sources of randomness for extra security

### message Confidentiality

plain text messages passed through encryption function before sent

### Caeser Cipher

shift message and compare to frequency distribution of letters

### Vigenere Cipher

1553

See Slides

### One Time Pad

take the plain text and xor it with the key

XOR: Are they different? yes (1) or no (0)

only mathematically proved secure encryption

Supposed to use true RNG

the key in this case is as long as the message (hit /dev/random for n bits)

sending two messages with the same key allows for some of both the first and second message to be seen

### Stream Cipher

Use PRNG instead

ni shi dou fu

Salsa20 is a secure stream cipher

Very fast encryption

### Block Cipher

slower than stream ciphers

allows for reusable key

### Confusion and Diffusion

Confusion: each bit of the cipher text should depend on several parts of the key to destroy features of the plain text

Diffusion: review

### Data Encryption Standard (DES)

key: 64 bit (56 bit key with 8 bit parity)

2 ^ 56 combinations

1 key per microsecond would take 1000+ years on old hardware

With parallel computing, would take a few months to brute force. With dedicated hardware, a few days. Now, a couple hours.

### Advanced Encryption Standard (AES)

Most common block cipher today

128, 192, 256 bit keys

128 bit blocks

field of post quantum Cryptography involves studying what will be broken and secure after quantum

no more efficient way to crack than brute force

designed to run fast in software

if message not large enough, add padding; padding technique is to make each byte of padding represent the number of bytes of data

do not do padding yourself you do not accidentally create a vulnerability

cipher modes: see slides for list
- ECB: same plain text will always encrypt to same cipher text: will not remove features properly
- CBC: cipher block chaining: each block depends on output of previous
- Counter: more like a stream cipher, cipher xor plaintext like one time pad

### How to enforce both Confidentiality and integrity?

option 1: create cipher text with encryption and append results of an HMAC to the end

cryptographic doom principle (on every exam): if you have to perform any cryptographic operation before verifying the MAC on a message, you are doomed

need 2 keys, one for Confidentiality and one for integrity

maintain different key pairs for each direction of communication

to make new keys, use a PRG
