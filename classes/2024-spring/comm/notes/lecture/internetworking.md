# Internetworking

## Questions

Who owns class C addresses?

## General

Reading classic engineering ideas will provide you with foundational knowledge

Living on the edge of technology allows you to see opportunities for max leverage as soon as they arises

already discussed communication between two hosts on a physical medium

must consider that networks in the internetwork will make different decisions regarding packet management

## Simple Internetworking

establish connectivity between hosts on distributed heterogeneuos networks

abstraction is software supported instead of hardware

The IP protocol connects transport and application protocols in an hour glass shape; they all connect to each other through IP

IP does not handle congestion

## IP Service Model

What does it provide to higher levels?
- TCP and UDP expect global namespace, host to host connectibity and best effort packet delicery

Packets can be dropped, experience delay and deliver out of order

## IP Datagram format

max size of datagram (including header) is 2^16 = 65536

supports fragmentation so that ethernet can break the IP packets apart and reassemble

time to live or hop count: original idea was that packet had a time to live in the network and after that it would be dropped; did not work well so swithced to hop counting
- typically 64 hops
- each router decrements the count
- protects network from infinite loops of packets, so no need for spanning tree

checksum just covers header and not data

contains both source and destination IPs

## Fragmentation and Reassembly

problem: different physical layers provide different limits on frame length 

solution: when necessary, split IP packet into fragments before sending over link
- where should reassembly occur and what happens when a fragment is lost?

reassembly done at destination to prevent routers from reassembling and having to disassemble again

if a fragment gets lost, the network will still send the rest of the fragments and then the transport layer will throw them away at the destination
- causes lots of overhead in error prone environments so should be avoided

try to avoid fragmentation at source host by creating packets small enough to fit in the MTU (max transfer unit) of local network

32 bits for frag support:
- 16 bit packet ID to identify fragments
- 3 bits for flags
- 13 bit fragment offset

Routers can be set to not fragment and will just drop packets that are too big

offset is in multiples of 32 bits

if the more bit is 0 it is the last fragment; if packet contains both offset 0 and more 0, it is the only packet

## Global Addresses

Internet addresses are globally unique and 32 bits

hierarchical: network subnet host

addresses assigned to NIC not computer itself

### classes

see slides for diagrams

## private networks

the rest of the internet cannot acces these addresses

1 private class A address range; has 16 million addresses


## Subnets

unique identification of a single part of the network not good enough for scale

only 4 billion possibl nodes

subnetting involves taking a single IP address to represnt a network and allowing for the address to represent multiple networks

see slide 27 for diagram

instead of 16 hosts bits, can have 8 subnet bits and 8 host to have 255 networks with 255 hosts

make the internet more scalable by allowing for more efficient use of global addresses

break up the network into more manageable chunks so IPs are not wasted

### Subnet Mask

simple IP: all hosts on the network have the same network ID

The subnet mask includes the network ID bits as well as the subnet ID bits

se slide 28

allow to chop up class address into pieces

FIGURE OUT EXAMPLE
- go through slide animations

### Forwarding Algorithm

subnet mask stored in forwarding table not packet

D is address, and with mask, D1 in the subnet number 

go through the subnet table until a match is found

subnets not visible from outside, they just care about the class B address 

will never match more than 1 entry

## CIDR

Class Inter-Domain Routing

eliminates classes completely

can hand out a block of contiguous addresses
- 192.168.30.* - 192.168.32.* instead of 192.168.*.*

to represent number of bits in subnet, use the IP/n notation

Domain address refers to the organization address

most organizations want Class B addresses but there are not enough

can take multiple class C addresses and aggregate them together into a single

subnet bits do not have to be contiguous but not making them so is foolish

CIDR only allows contiguous subnet bits

195 is a class C address

allows for allocation of blocks of contiguous network numbers that relate

blocks sizes are restricted to powers of 2

use a CIDR mask to identify block size

### Example

195.17.80.host to 195.17.95.host

claim most singificane 20 bits are the same

### table example

longest match: item with biggest number of bits in the mask

### Tunneling

extra work for routers so can cause bottlenecks at busy routers

reduce MTU when tunneling to consider both the original IP packet and the tunnel wrapper


## Virtual Private Network (VPN)

company wants proprietary private nerwork for confidental traffic

guarantee no one can snoop on traffic

can use tunnels to guarantee privacy and and provide the VPN service to customers

ISP sets up tunnels between locations for private traffic

QUESTION: each connection to different devices requires a new tunnel?

virtual network, meaning not hardware implemented

QUESTION: do VPN servers require two tunnels?

## Address Translation

someone has to assign IPs to subnets and LANs

### Hard Coded

encode physical address into host bits of IP address

not possible for many networks such as ethernet

world ruled this out until IPv6

### Fixed Table

admin had to find out IP and manually add it to a router table

lots of management

## ARP: Address Resolution Protocol

### Source 

routers have ARP table for each interface

all ethernet will receive the broadcast message and check to see if the IP is its

know output port, check the table for address needed

if not in table, broadcast request and wait for reply
- request for ethernet address associated with IP

do not refresh table

### Target Hosts

intended destinations

if receiving from source, add source to ARP table

### Forwarding Algorithm

when host comes online, needs IP, subnet mask, defailt router, DNS server

ARP broadcasts never forwarded by routers because they are only needed on an ethernet LAN

For HW:

H2 to H1 via R1
1. is H1 local, No

H2 forward IP packet 

H2 ARP table empty
1. 2 arp query brodcast
2. 1 arp reply to h2 with R1 MAC
3. h2 send ip packet to 1
4. R1 arp query for H1 broadcast 
5. 1 arp reply to r1 with h1 mac
6. r1 send IP packet to h1

After this rpocess, ARP tables updated and it does not need to happen again

ARP frames do not leave the subnet, must send to router 2 in a packet

### Host Configuration

IP
- must be unique on internetwork

## DHCP

executed when host is booted or connects to new network

Requires a server to operate

Most networks have a global DHCP server

lease IPs for a certain amount of time and have to renew

protocol had to change to release because windows computers kept crashing

### Server

host broadcasts DHCP disover message

## Internet Control Message Protocol

all of these protocols are constatnly building packest

REVIEW

### error messages

destination unreachable 

reassembly failed

invalid header

etc.

### Control Messages

Ping

Redirect







>>>>>>> 360f50f61ff6da1f597431b730f1f42c910d2749















