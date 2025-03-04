# Networking 101

## OSI Stack

Explicit structure allows for identification and relationship of complex system pieces

Can interchange parts of the system easily: if

## Protocol

Each protocol has:
- types of messages exchanged
- message syntax (bit fields)
- message semantics (meaning of information in fields)
- rules for how to process the information (state machine)

header contains information important to functionality of protocol

Think TCP state machine

Open protocols defined in internet RFCs (HTTP, TCP, etc.) contain nothing proprietary and are not for profit

## Encapsulation

packet consists of:
- header
- payload
- footer (sometimes)

footer sometimes includes metadata or checksum

payload of a packet encapsulates the packet from the higher level

## Layer 2

Describes how frames of bits are transferred over the physical layer

abstraction:
- source / destination
- data: frames
- link: ethernet, wireless
- addressing: MAC

Detects errors in the physical layer

### Ethernet

switched protocol, uses switches to connect devices across a large network

switches map what MACs are connected to what ports

### Address Resolution Protocol

How a layer 3 host figures out layer 2 address

Layer 2 works on a hop by hop basis

source and dest MACs in packets get updated as it travels

Broadcasts ARP request to everyone on the network asking who has an IP; That IP responds with its MAC

ARP Cache: save the MACs somewhere so you do not have to keep requesting

Security risk: another IP responds with its MAC

## Layer 3

How packets move between two hosts

Abtraction:
- Data: IP Packets
- IP addresses

Can easily spoof IP addresses

Best effort

## Layer 4

Solves the L3 Problem of unstable packet delivery

Solves the multiple applications problem with ports

Describes how to communicate between two applications

Abstractions:
- ports
- TCP/UDP Packets
- IP:port

TCP guarantees complete delivery in the correct order

UDP does quick delivery without guarantees

### TCP

Data from application layer is split into segments with MSS max segment size

bytes in application data stream numbered with 32 bit sequence number

4 TB files will cause sequence numbers to wrap around

Flow control: need to be sure sender does not send more than the receiver can handle

### Layer 5+

use transport layer to provide useful functions to the user

Examples:
- HTTP: web browsing over TCP
- SMTP: email over TCP
- SSL: encrypted TCP connections
- VoIP: voice over IP telephony using UDP
- DNS: domain name lookup over UDP

video streaming runs on UDP

### DNS

no one wants to memorize IP addresses

DNS maps a name like google.com into an IP 142.250.9.16

use the dig command

DNS has a hierarchy starting at the root level and going down to layers like com, org, etc.

There are 13 main DNS root servers (all owned by US)

The OS looks for public DNS servers before querying the root servers

8.8.8.8 is Google's public DNS server

ISP DNS servers can be used for geoblocking

Need to do a DNS request and recieve a DNS response

start at root, go to next level (com), go to next level (google), go to next level (docs), ...
- recursive resolution

DNS packets send over UDP:
- questions
- answers
- authority
- records

Identification:
- query ID
- 16 bits random

DNS responses are cached

security risk: caches can be poisoned

cache data times out periodically
