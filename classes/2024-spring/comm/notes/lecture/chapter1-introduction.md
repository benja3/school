# Introduction 

## Switching 

First challenge: how to manage switching process?

### Circuit Switching

dedicated circuit to send and recieve bit streams 

Examples: original telephone network 

### Packet Switching 

chop up message into pieces, assembled into packets and forward the packet to an appropriate destination 

This is currently used by the internet 

leads to greater efficiency but less reliability 

Would be impossible to use an old phone betwork at this scale, but if it were possible the conneciton would be more reliable

Swithces have a scheduler that determine what packets go through when

Priorities can be assigned to packets 

## Common Patterns

Early applications:
- File Transfer Protocol (FTP)
- Network File System (NFS)

## Reliability 

### Bit Errors

Electromagnetic interference corrupts bits in the link

Relatively rare

Sometimes but not always possible to correct bit errors

### Packet Failures

Some type of error occurs that corrupts an entire packet or renders it useless 

### Node/Link Error 

computer crashes

## Manageability 

networks need to be managed with relative ease 

Mindest: once it is working and you have a stable build, do not touch it!

# Architecture

## Layering and Protocols

Abstraction leads to layering 

Objects that make up layers are called protocols; higher level protocols are build with lower level ones 

### Protocol Service Interface

defines operations that other objects can performon the protocol 

how to use the protocol

example: send, recieve, fetch, etc.

### Protocol Peer Interface 

Defines form and meaning of messages

Example: Way that a service interface function would communicate with another machine 

## Layering and Modular Design 

Use abstraction to hide complexity

Application developers need an interface to program with that communicates with the nitty gritty below 

Host to host: IP

Can replace one layer with something completely new as long as it communicates the same way with the layers above and below 

## Protocol Machinery

Building blocks of network architecture 

Protocols must coordinate to exchange information over the network 

## Enscapsulation

Each protocol can add its header to the overall payload (packet)

Payload: bits that the application wants

headers hold information that determines how the protocols communicate 

Contains information such as the type of channel, where the information goes

The request/reply or other protocol does not care about what the bits are, which leaves room for encryption

as more and more protocols get involved, more header bits get added that are irrespective of each other 

## OSI Architecture / Stack

Open Systems Interconnection architecture 

Assembled by ISO (International Standards Organization)

Model on how to create a network 

X.number networks based on OSI (do not work well)

each layer adds its own header 

for each hop, bits must be demodulated and decoded to determine the next destination 

Bottom 3 are the minimum that must be implemented on any networked device 

1st exam question: name layers of stack 

Please Do Not Throw Sausage Pizza Around 

Layer's 1 - 3 typically found in kernel or hardware 



### 7. Application

interface for application programs 

### 6. Presentation

formats for network data 

### 5. Session 

name spaces for connection management

### 4. Transport 

Process to process communications for messages 

takes message and gives it to the network layer such that it can create packets; divides message into appropriate sizes such that the network layer can send packets 

Allows software communication and reorganization of data that is too big to fit in a single packet 

### 3. Network

Packets 

A packet and a frame can be the same thing or a frame can contain multiple packets, or a packet must be distributed across multiple frames. No real relation between frames and packets. 

forwards packets to their destination in a switch based network 

Frame vs Packet: only difference is the layer the group of bits is on 

A packet is a frame plus a header 

When data has to travel through many nodes 

### 2. Data Link

Collects bits into an organized frame

Where do bits start and stop, are they correct, where bits go?

Moves frames from one node to another 

For high performance networks, most of this is hardware implemented 


### 1. Physical 

transmission of raw bits over a channel

turning bits to electromagnetic energy for transmission and reinterpretting the energy as bits when it arrives 

Modulation and Demodulation 

## Internet Architecture (TCP/IP)

TCP is the protocol of choice for request/reply channels 

TCP: layer 4

IP: layer 3

Most internet software is open source 

FTP: File Transfer Protocol

Ethernet contains both layer 2 and layer 1 information 

## Implementation 

### Socket API

Relatively simple interface that allows communication between two separate applications 

## In Class Design

Throw away packets with bit errors as soon as they are detected instead of spending resources to continue sending it 

Separation of concerns: if something cannot be done properly in one layer, leave it to another completely 

Must consider buffer space on destination to hold the message being sent if it is large 

Consider how long to wait for delayed messages

## Performance Metrics 

### Bandwidth

Signals: measure of the width of a frequency band (Hz)

the amount of data that can be transmitted at one time

Higher frequency signals contain more information 

Networking: amount of data that can be sent in bit/s

theoretically: 1 MHz signal -> 1 Mb data 

Can divide bandwidth across multiple channels with fractional bandwidth of the original 

Volume of water that can flow through a pipe

### Throughput

unit: bits/s

protocol to protocol measurement 

Measures volume payload bits, excluding header 

Ethernet:
- bandwidth: 10 Mb/s -> limitation of physical medium
- throughput: 2 Mb/s -> limitation of protocol to protocol communication 

### Notation

Kbps: 10^3 -> electrical engineers
KB: 2^10 -> computer scientists 

Do not trust anyone elses unit conversions, do them yourself 


### Latency 

delay time

time to send a message from A to B 

How long is the pipe, how long does it take the water to flow

can measure in one way vs round trip 

components:
- latency = propagation + transmit + queue
- propagation = distance / speed of light 
- transmit = size / bw

propagation: delay from speed of light 

queue: how long does it take for the message to be forwarded after sitting in queue
- usually the bottleneck 
- will ignore in this class 

speed of light:
- 3 * 10^8 m/s in vacuum
- 2.3 * 10^8 m/s in cable
- 2 * 10^8 in fiber 

## Example 1

100 Mb/s Ethernet, packet size: 12000 bits in 1 packet, 10 us propagation delay 

transmit time (tx) = 12000 bit / 100 Mbps * 1 Mbps / 10^6 bps = 120 us

two devices A and B are separated by cable of distance 

## Bandwidth Vs Latency

Jitter: varying arrival times (latency) of packets when streaming 

Pipe value shows the number of bits that are transmitted before feedback can be generated 
- this information can be used to determine the applicability of certain protocols like stop and wait or acknowledgements

want to keep the pipe full as much as possible

When sshed into a system, the characters are sent to the remote system before they are rendered, which explains lag

characters put into packets and sent to remote to machine, which interprets them and preforms appropriate actions on the remote machine 

different metrics matter in different situations 




















