# Exam 2 Slide Review

# Wireless

Goal of 802.11 is to provide an ethernet like interface for wireless devices like laptops to communicate over

## Frequency Bands

Used for 802.11: 2.4 Ghz and 5 Ghz

FCC controls usage of different frequency bands 

### Channelization 

The 5G range is 5.17 GHz to 5.835 Ghz

This range is broken up into different channels of smaller frequency widths

These channels can be used for parallel communication within the band

### Spread Spectrum

idea is to add pseudo-random component into signal to spread it over a winder frequency band than required. 

Frequency hopping: transmit over psuedo random sequence of frequencies to reduce probability of collisions

see slide 5.6 for diagram

low probability of multiple hosts selecting the same frequency at the same time 

REVIEW Direct sequence: for each bit, send XOR of bits and a pseudo random mask that is known to both receiver and sender 

### OFDM 

Orthogonal frequency division multiplexing

lots of versions

## Wireless Channel Access

Similar to ethernet CSMA collision detection

IF all nodes cannot hear each other, they will not know if some others outside of range are transmitting 

### Exposed Terminal Problem 

QUESTION: How could red transmit to yellow? Would it not be jammed by the blue to green?

### Multiple Access with Collision Avoidance

Request to Send: RTS
Clear to Send: CTS

Sender sends RTS and receiver replies with CTS if channel is clear. Sender sends data and receiver responds with ack. 

All nodes in the area can overhear RTS and CTS and know not to send

If a neighbor receives an RTS but not CTS, it is ok to send because the data transmission will happen outside of interference range

### MACAW

Assume collision if no CTS reponse to RTS or no ACK

## Infrastructure vs Ad Hoc

### Infrastructure

our typical networks

mobile nodes communicate wirelessly with access points 

Access points are connected to ethernet and the rest of the internet

mobile nodes associtate with access points, and can go out of range

### Ad Hoc

Do not require pre existing infrastructure and are set up on the fly between nodes in the field

routes may contain multiple hops between nodes

## Infrastructure

### Finding Access Point

Node sends probe frame and all APs that receive probe reply with a response frame

this is what creates the menu of available networks 

process of sending probes called scanning

AP sends beacon and if the signal strength from a different AP is better than the nodes current one, it will switch

will also switch if teh signal is not heard from teh other 

### AP Placement 

signal propagation throguh obstacles hard to measure so placement can be difficult

finding good locations is  a very manual process

must also decide how much overlap is desired

too much or too little overlap will reduce performance

## Bluetooth

Also a form of 802.11 

Intended to replace wires on a desk

10 M range

uses same 2.4 G band as 802.11 wifi

channel access protocols between 802.11 and bluetooth incompatible

# Switching

## Packet Switching

allows network to cover a large area and tolerate latency

also allows for the support of a large number of hosts

### Challenges 

efficient forwarding: which way should packets go and when should they be forwarded?

routing: how to maintain information on where to send packets?

contention: if multiple packets need to go out, which should be sent first and what to do with the others if there is overflow?

### Network layer and switches

each layer of the network stack has to add its own header to the packet

different switches can operate at different levels

### Extended LAN

Multiple LANS connected with level 2 switches (bridges)

use the MAC protocol and make decisions based on MAC addresses

## Forwarding

Task of determining the correct output port for a packet

involves reading the header, using the specified forwarding process, updating the header and sending it out appropriate port

requires sufficient information in the packet. goal is to minimize the amount of data while still forwarding efficiently 

### Datagram

road trip analogy: navigating from Clemson to Charleston solely based on road signs without a map

connectionless: no state of connection needs to be established between the hosts before transmission occurs

packet navigates independently

process involves tracing the globally unique address to an output port on the router

QUESTION: answer to Why not use Ethernet?

maintain a table at each router that tells which port to send a packet out to get to any destination on the network

analagous to following signs

Advantages:
- forwarding tables are always ready and are maintained in the background. tables are dynamically updated to route around failures

disadvantages: 
- header requires full unique address
- packets may not take same route and arrive out of order
- forwarding tables require a lot of storage

### Virtual Circuit

analogy: like how rangers go into the woods and create a trail that is easy for other people to follow

explicit connection set up phase. Once connection is set up, packets follow that route. Connection / circuit is torn down once the data transfer is completed.

each switch maintains a VC table

switch translates virtual circuit ID and incoming link to a new virtual circuit ID and outgoing link

Problem assumptions:
- simplex circuits so can reuse same VCI in each direction
- VCIs are per link so same VCI can be used on different ports
- lowest VCI used for link on set up

REVIEW but low priority

### Source Routing

following directions

advantages:
- simple switches which are fast and cheap
- source knows path

disadvantages:
- host must know topology
- changes in topology must be known by all hosts

## Bridges

allows for scaling of traditional LANs which are on a shared medium

LANs connected with store and forward techniques

called extended LAN

### switch vs bridge

switches receive frames on input port and translate the address to an output before forwarding the frame out of the output port

a bridge is a special type of switch 

switches are typically smarter than bridges

### learning bridges

simple bridge might forward all frames to all LANs, but this is inefficient

bridge learns where hosts are to avoid forwarding unnecseeaary packets

maintains forwarding table

learns table entries by monitoring packets that it forwards; learns from receiving frames

this is an optimization process and will still work correctly even if the table is incompltee

bridges intended to be used with datagram forwarding

extended LANs can have loops to add robustness, however, packet loops can cause big problems because they will be forwarded in circles forever

always forward broadcast frames


### Spanning Tree

represent LAN as a graph with no loops 

distribtued algorithm: all nodes send (assumed root ID, hops to root, sender ID) and learn from each other until all nodes know they are not the root

stop doing unecessary stuff like forwarding if know not root and not designnated bridge

### bridge limitations

do not work with heterogeneous network technoglies

do not scale becaues spanning tree does not scale; configuration becomes too much overhead

# Internet

## Internetwork

establishes connections between hosts on different networks

protocols designed to support heterogenous technologies

## Internet Protocol (IP)

provides global name space, host to host connectivity and best effort packet delivery

packets can be lost, delivered out of order, duplicated or delayed

### header info

ipv4/6, header length 

data length (max size = 65536 bytes) fragmentation details

time to live or hop count

protocol

checksum

src / dst address

20 B standard header size

### Fragmentation

some links have an MTU that is smaller than others and not all packets fit

to solve this, must fragment IP packets that are too big into smaller ones and then reassemble at the destination

reassemble at destination to prevent refragmenation

if a fragment lost, drop the whole packet

should not fragment at source and therefore create packets that fit within the links MTU

bits:
- 16 bit fragment ID
- flags
- 13 bit offset (in 8 byte words)

### global addresses

IPv4 addresses globally unique

heirarchical addresses: network address and host address on the network

Class A, B , C

### forwarding

hosts and routers maintain forwarding tables which contain a list of host and next hop pairs

every datagram contains destination address. check if a connected network contains the destination and if not, send to the next router

making routing heirarchical allows for easier routing since can route at the network level and then find the host once the correct network is identified

### Subnetting

cool stuff

### CIDR

Class Inter Domain Routing

instead of having Class ABC, break apart everything into subnets

subnets within a group must be contiguous

CIDR address: 195.17.80/20

collapses range of subnets into a single address

## Address Resolution Protocol (ARP)

maintains table of IP to MAC address maps

## Internet Control Message Protocol (ICMP)

sends error and control messages 

## Tunnelling

Can configure routers to wrap IP packets in another IP packet that only knows source and destination router. 

used to enable VPNs and encryption

# Routing

forwarding vs routing: forwarding involves sending out the next port, while routing involves building the table that tells what port to forward out of

use distributed algorithm so a single point of failure will not break the whole system


























