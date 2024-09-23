# Intro

## General 

Projects intended to be easier in this class, just to expose you to the material.

Will not be doing a  lot of programming of algorithms, but visualizing and experimenting with the algorithms 

Fabric: NSF Testbed that allows for VM setup to represent switches and other networking hardware 

Office hours 3:30 - 5 Thursday and Friday 

Homework problems not on website, same in all versions of book

For homework answers, pirate the book

## Course Objectives

### Problems of network communications 

### Advantages and disadvantages of the current design plus other potential replacement designs 

The standard internet is not performant enough for certain usages 

### Problem analysis and evaluation 

### Discuss emerging network technologies 

### Networking from ground up approach 

How to get electromagnetic energy going down a cable and control it to do what we want at higher and higher levels 

Top down is more CS focussed 

## Perspectives

### Application Programmers

How easy is it for a developer to use the technology?

Want an easy way to make sure messages are delievered, do not care about nitty gritty.

### Network Operators

The network could be extremely performant if engineers cannot maintain it and keep it running reliably it is no good

Ethernet is the number one LAN technology because it is easy, cheap and reliable 

### Network Designers

want cost effective and efficient design 

## Scalable Connectivity 

Scaling is one of the biggest problems in networkings

Simplest parts of a network:

### nodes

Devices on a network 

hosts or special purpose hardware 

### links 

connection between devices 

can be point to point or have multiple nodes connected on the same channel 

Coaxial cable used to stream cable TV at first, but now can be used to connect to the internet 
- capacity of the cable must be shared 

## Switched Network 

contains many notes that are connected by swithces

get congested with lots of nodes on a single local area network 

in old times, an operator had to directly connect the notes, but now ethernet switches can do that 

internetwork: connection of multiple local switched networks; also called extended local area networks 

## Addressing  

How to assign unique addresses to all devices in the world
 
Address: 32 bit string that identifies a host 
- 32 bits can represent approx 4 billion, needs to go to 64 bits so more memory can be addressed and more devices can be on the internet 

There are 2^128 IPv6 addresses 

NAT: network address translation 

unicast: node specific 

broadcast: send to all nodes on the network 
- cannot be done on the internet because it would be ridiculous to broadcast to the whole world 

Multicast: send to a subset of nodes on the network 

Anycast: 
- rarely used 

## Routing

Routing: process of determining how to forward a message to the destination based on its address

## Cost Effective Resource Sharing 

physical links and switches must be shared among many users 

if a link is constantly connected to a single source, it spends a lot of time idle 

### Time Division Multiplexing 

assign nodes to slots on a frame and each slot represents the trafic from that user 

not efficient if a user is not using their slot 

### Frequency Division

Instead of dividing by time, divide by frequency of the signals 

If frequency is 1 MHz, can transmit 1 Mb/s 
- why 5G Wifi is faster than 2G

### Statistical Multiplexing 

Time division but on demand instead of fixed 

feed packets from all sources into a switch, and the switch figures out how to transmit the packets across the line (round robin)

Links are scheduled on a per packet basis 

Contension: debate 

If all hosts are putting in packets at a higher combined rate than the switch can send them, the queue could fill up and cause congestion 

If the switch does not have room for a packet, it gets drop 

Lots of math in queueing theory that can optimize packet loss



## Interprocess Communication 

Applications on computers need to be able to communicate efficiently 

Connection between two applications called a socket 

Want to give app devs the illusion of a pipe 

Do not want app dev to have to deal with packets 

## Types of Logical Channels

### Request Reply

client requests file and server responds with that file data 

data will end up at the client in perfect condition, packet losses resolved 

Applications typically will not show files they know are corrupt 

### Stream based

used for video and audio applications 

sends a continuous sequence of frames 

Want server to just send the data and client will handle it as necessary 

Do not care about packet loss as much 

If delays less than certain amount, humans do not really notice it 
- no one wants to use a system that has annoying amounts of delay 

Lots of compression occuring because streamed data quantities are huge and mostly redundant 

## What Goes Wrong? 

### Bit level errors 

caused by emag interference 

most comm cables have shielding 

good bit error rate on order of 1:10^9

these systems are never perfect, although error can be rare

wireless communication is much more prone to bit errors than wired 

### packet errors 

Come from congestion and buffer overflow 

### link and node failures 

Some dude accidentally shoots hole in cable 

must include redundant paths for packets to arrive at their destination 

### Others

Delays

Out of order

Security and eavesdropping 
- originally, security was complicated so the internet was designed without security considerations intially 




























