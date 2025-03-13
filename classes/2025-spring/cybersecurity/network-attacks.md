# Network Attacks

## ARP

Find the MAC address of a device with a certain IP

Devices maintain an ARP cache of (IP, MAC)

Problem: no authentication, fastest responder wins

IPv6 uses NDP instead of ARP

ARP implementations are stateless: does not connect responses with requests
- any ARP responses received will be dumped to the cache; there does not even need to be a request

any computer on a network could claim to have a certain IP

### Man in the Middle with ARP Poisoning

Eve sends ARP replies (Bob IP, Eve MAC) to Alice and (Alice IP, Eve MAC) to Bob

Eve is now in between all traffic and can do anything

### Countermeasures

Restrict LANs to trusted users

Check for multiple occurences of the same MAC

Static ARP table manually set up by sys admin

## IP Spoofing

Cannot prove sender authenticity in an IP packet

Can overwrite the sender IP in a packet

countermeasure: border router can block packets whose source address appears to be from inside the subnetwork

## TCP Handshake Spoofing

TCP sequence numbers are not cryptographically secure, but initial sound be random

## TCP SYN Flooding

Attacker sends many connection requests from spoofed source addresses which overwhelms the receiver

## TCP Reset Attack

can an off path attacker reset an existing TCP connection

On path: knows details of the communication

Off path: more remote and does not know as many details

need to know 16 bit port numbers

## TCP Reflection Amplification

1. Attacker sends a SYN packet spoofed with victim address
2. Server at reflection address replies with SYN-ACK to victim
3. When victim does not respond with last ACK packets the server will continue to retransmit SYN-ACK

## TCP Session Hijacking

Spoof a packet with a valid TCP signature (src IP, dest IP, src port, dest port)

There is no way to tell if the packet is real or fake

Attacker still needs to predict sequence number

countermeasure: encrypt at the application layer with TLS

## DNS Caching

DNS responses are cached because looking it up is a pain

Cached data times out, all entries have a time to live (TTL)

Negative queries (no record) are also cached

users trust the host address provided by DNS

## DNS Cache Poisoning

Lifetime of cache entry determined by TTL

Entries can be evicted from cache due to limited memory

Early DNS implementations cached all responses

Two answers to questions: too hard or it doesn't work

what is glue record???

## DNS Spoofing Attack

First response wins. If Mallory responds with a spoofed IP before the DNS servers respond, her entry will be cached

What needs to be known to spoof a response

DNS uses port 53

### DNSSEC

Adds sender authenticity and message integrity to DNS

Authoritative DNS servers sign DNS responses using public key cryptography 
