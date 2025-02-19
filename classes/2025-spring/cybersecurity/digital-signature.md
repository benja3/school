# Digital Signatures

Symmetric key cryptography: Ek = Dk
- requires separate key shared with each person

new idea: each party has a pair of keys (K, K')

K is the public key that can be shared with anyone

K' is the private key and needs to be kept secret

Knowing K, it is computationally infeasible to calculate K'

Can easily calculate K from K', but not K' from K

### RSA

very slow compared to AES by a factor of 1000

message x must be smaller than N

keys are huge (4096 bits)

alice wants to send encrypted message to bob
- alice knows bobs pub key, bob knows alices pub key

Alice encrypts with KB and only Bob can decrypt with KB-1

How can Bob know who encrypted the message for him?
- Alice can had her digital signature into the message

Elliot uses private key to create a signature, and Bob uses Elliots public key to decrypt

Alice signs message with private key, bob decrypts and verifies with public key
- anyone can use the public key to check the signature

just assume the weird math works out
