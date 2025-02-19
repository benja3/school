# Key Sharing

### Symmetric Key Cryptography

key used to encrypy/decrypt and calculate MACs (message authentication codes)

need a secure channel to exchange key

everyone wants to talk to everyone: N=62

total number of keys: N * (N - 1) / 2

high overhead for Symmetric key Cryptography

Amazing fact: can use a public conversation to negotiate a private key

### how to derive shared key

Relies on mathematical hardness assumption called discrete log problem

Diffie-Hellman

1. alice and bob agree on public parameters
- p: large safe prime number (p-1)/2 also prime
- g: generator: small integer

2. alice generates random secret value a where 0 < a < p, and bob generates 0 < b < p

3. two messages exchanged. Alice sends g^a mod p and Bob sends g^b mod p

4. Alice computes x = g^(b x a) mod p ; Bob computes x' = g^(a x b) mod p

5. Hash x and x'

you cannot easily reverse the parameters from the final combination


### Passive Eavesdropping vs DH

Eve knows 8 and 19 and thats it

Eve must do g^(a*b) mod p

### Man in the Middle Attack

mallory is manipulating the values exchanged

diffie hellman not secure against active man in the middle attackers during the key exchange

does not authenticate who is on the other end; alice and bob cannot tell if there is someone in the middle

Defense:
- two factor authentication
- physical contact with smart cards
- digital signatures

### key management

lots of security incidents come from improper management of secret keys

each key should only have one purpose

vulnerability of a key increases:
- the more you use it
- the more places it is stored
- the longer you have it

usually have a master key and derive session keys from it

keep keys far away from the attacker

modern computers have special secure hardware for secrets like keys

protect yourself from old keys that are potentially compromised

### forward secrecy

when you change passwords, there should be no logical connection

learning an old key should not help an adversary learn the new one

### problem: scaling

suppose people want to verify the integrity of data published by Alice; or Bob wants to receive data from a lot of people

solution: public key crypto
