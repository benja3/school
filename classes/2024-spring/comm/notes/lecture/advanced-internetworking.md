# Advanced Internetworking

<<<<<<< HEAD
can isolate OSPF routing into areas

## IPv6

major features:
- 128 bit addresses
- classless
- real time service
- authentication and security

people thought IPv4 was going away and created IPv6 but now it is still here

ISPs needed to be motivated to be good enough for companies to buy new routers

nearly all new devices implement IPv6, but ISPs don't want to spend the money

### notation 

were going to use 64 bit addresses which would be more than atoms in universe, but committee decided to go even bigger and do 128 bit

can support 1500 devices per square foot of the planet

notaion: 8 16 bit hex numbers

contiguous 0's are represented by :: where everything between the colons is 0

IPv4 to 6 address mapping built in

address assignment geographically oriented

### header 

40 bytes 

must store 2 128 bit addresses, but gets rid of a lot of junk from IPv4 header

no fragmentation, source must retrransmit a smaller packet

NextHeader represents whether there is more header info (extention) 

extension headers: fragmentation, source routing, autheitcation and security, etc.


## questions

how to build a routing system that can handle the whole internet?

how to increase IP space beyond IPv4

how to enhance internet functionality

address scalability

Mobile IP

## Mobile Hosts

home and foreign agents are computers that are typically built into routers

host on new network must register with foreign host so it can get a new IP but stores the old IP from the old network

### mobile ip

create a tunnel from home agent to foreign agent

when sending from origin network, fwd to home agent which sends to foreign agent with the tunnel and the foreign agent forwards to the corresponding device

### delivering to mobile node

how does home intercept packet for mobile node?

proxy arp: allows a home agent to respond to messages that are registered with it but not its IP

how does home deliver to foreign?

use tunnel

clemson fancy wireless uses block of class C addresses and cisco server with massive table of what APs all the devices are connected to

mobile IP is a cheap solution for moving devices

care of address: corresponds to foreign agent which can then forward to appropriate place

do not want to daisy chain if multiple movements occur. registering with new foreign agent notifies home agent of change

## Global Internet

dominant problems are complexity and scale

### structure

backbone network ran by NSF

network was in tree structure where the backbone was root

backbones began to be bottlenecks

now, internet contains lots of backbones with different levels

backbones can be accessed by ISP with peering point

large companies can pay and get direct connections to the backbone network

### autonomous systems

two level route propagation herierachy

have two autonomous networks that need to connunicate seemlessly

interfaces that connect the two called gateway

interior gateway does interdomain routing

exterior gateway connects to teh outside world

### interdomain routing

need to find loop free path to all destinations

due to TTL, looping packets will still be dropped, but will still cause unecessary traffic

why?

scalability: backbone must forward all packets

### Extended Gateway Protocol (EGP)

designed for tree structure of NSF backbone

### Border gateway protocol (BGP)

internet is arbitratily interconnected set of AS

autonomous system: AS

two types of traffic: local and transit
- local: begins with AS
- transit: passes through AS

AS types:
- stub: single connection to one other AS
- multihomed: connections to more than one AS but refuses to carry transit traffic
- transit: connections to more than one AS but does carry transit traffic

each AS has one or more gateways (border routers)

one BGP speaker that advertises local networks, other transit AS, path information

does not long to either of two main classes of protocols (distancce vector and link state)

uses TCP between speakers to make sure messages are reliably delivered

heirarchy of payemnts from backbone providers to regional providers to customers

can have peer relations where two regionals are connected and can reroute through cheaper links to the backbone 
>>>>>>> 3f64ebee0eaddffd1832a45e2afe23dd4d413b2d
