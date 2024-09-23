# Switching and Forwarding

## Packet Switching

why not just a shared link? range and scalability

cannot just use longer cables

switching allows for netwokrs to cover larger areas and tolerate latency

goal is to provide illusion of local area network on a shared link

## Challenges

### efficient forwarding

which way should packets go? 

could be multiple sources trying to communicate across the channel at the same time

think about all the ways that roads connect and merge

stop sign vs stop light vs overpass vs spaghetti junction

### routing

how is forwarding infomration maintained

do not want PC to figure out how to find paths

if a link goes out, must find new way to communicate across the network

background routing protocol builds and updates forwarding tables 

### contention

many inputs could try to communcate with few outputs

### network layer (level 3)

called switch if decision regarding where a packet goes occurs at level 3

### level 2 switching

endless argument as to level 3 or 2

make forwarding decisions based on MAC and not IP

good example: ethernet bridge

bad example: 802.11

need more information in header to do level 2 switching so most occurs at level 3

## Forwarding

process of specifying output port

packet comes in and and its packet header for that layer is read and decision is made to send it to an ouptut port

sometimes modify the header then the port is determined
- sometimes size changes

goal is to limit information as much as possible to limit overhead from reading packet headers

### Think Pair share

first time looking for classes is hard but once you know it it is trivial 

have general directions and try to navigate based on those

know a few general landmarks and figure out how to get to the land marks and ***

### types

important idea: globally unique addreses

routing is process of building forwarding tables

### datagram forwarding

road trip idea

know generally which way to go based on signs and can get more specific as you go

### virtual circuit

knowing class route

once the route is known, as many packets as necessary can follow the same route

### source routing

your house to party

someone provides you with instructions or connections that allows you to know the route in advance

have complete listing off turns to take on the way to destination

## Forwarding Datagrams

connectionless or destination based

each packet travels independently

no connection states needs to be established

translate global address to output port
- need to ensure globally unique addresses

forwarding table must be properly updated 

### example

each switch has a table that knows the port for what to forward packet out of to get to all host

not scalable because each host must have a table the size of all hosts on the network

analogous to following signs

table can be adjusted due to congestion

### advantages

forwarding tables always ready and can be updated in the background

intermediate switches can route around gailures


### disadvantages

header requires full unique address which takes time to decode

packets may not take the same route and arrive out of order

global address can require significant storage

source does not know if dest ins available
- separation of concerns

## Review

all routers and switches have to exchange between each other to assemble tables, this does not scale

switching and routing more difficult at layer 2 because have limited information in header

Adding heterogenous network technology to the internet requires higher level protocols to manage all of the information

## Virtual Circuit Switching

explicit connection set up -> data packets follow established route -> tear down virtual circuit when complete

want to set up a path between two nodes

analogy: rangers go and set up the trails so that everyone else can just follow them

For our examples, assume simplex

VCIs are per link so same VCI can be used on different ports

not good for short transmissions because of circuit set up overhead

still have to do destination based routing for the set up packet

not as prevalent becaue the performance saved is not as significant due to faster modern hardware

VCs allow for reservation of resources and improved quality of service

networks and applications are beginning to blend together in such a way that the application decides what type of networkign it needs

## Source Routing

Analogous to following directions

carry information in packet header as to how to get to its destination

switches do not do table look up

makes switches a lot simpler, faster and cheaper

source knows the path that packets will take

build a packet header with output ports on each switch in order

to find destination, recursiely send broadcasts to map the math to a location

99% of usage is destination based

## Bridges

for traditional LAN over a shared medium, easy and cheap to administer

problem: how to extent LAN?
- need to scale geographic area but retain the LAN like functionality

connect two or more LANs with a bridge

store and forward strategy: bridge will accept a frame, verify CRC, forward frame out of appropriate port

collections of LANs connected over bridges create extended LANs

bridges separate collision zones because the store and forward functionality prevents messages from being sent at the same time
- collisions only occur on the individual LANs

uses same MAC protocol and makes forwarding decisoins based on MAC address

### Switch vs Bridge

switches recieve frames on an input, translate to address to output and forward
- store and forward

bridges are type of switch used for connecting shared medium
- all ports bi-directional
- must support broadcast

bridges not the same as repeater or hub

can be a bottleneck if too many devices and hubs connected

### Limitations

limited scalability because broadcast will congest the large LAN

not heterogenous so cannot add new technology to the extended LAN

### Learning Bridges

working with wired networks

trivial birdges might forward all fraemes to all LANs which wastes frames

attempts to avoid forwarding unneseccary packets

maintain the forwarding table at the bridge

learn table entries by monitoring all packets on the LAN and examine source address to learn which hosts are on the network
- build table by checking source address

generic forwarding table with host : port maps

every time receives a frame, updates table

bridge still receives frames that are on the LAN because energy propagation
- for these frames, check if on network and if not, forward it out of port 2

entries in the table have timers that must be refreshed by hearing traffic

devices usually send frames soon after being connected so the table will be updated

always forward broadcast packets

### Loops

if all bridges go down and have a table reset, packets can get stuck in an infinite loop if bridges have looped connections

loops not necesary, but can be added for robustness

need a way to prevent the looping issues while keeping the physical links

## Spanning Tree

represent LAN as extended graph

Lans and bridges graph nodes

ports are edges connected to LAN bridges

Lowest ID bridge is root; all bridges have unique ID

for each bridge, compute the shortest path to root

for each LAN, the bridge closest to root is designated bridge and port toward root called designated port

if there are ties in bridge/port selection, use the bridge with the lowest ID

does not always allow packets to take the shortest path

to create spanning tree, replace LANs and switched with nodes in the graph

## Defining tree

bridge iwth Lowest ID is the root

for each bridge, compute the shorted path to the root and define the port on the shortest path as the root port

for each LAN, bridge colsest to root is desginated bridge

port towards root is called designated port

start at the root and do a breadth first search on each link

each link connected to root is guaranteed to be designnated

bridges connected to LANs connected to root bridge have root ports that connect to the LAN

if LAN has two choices, will connect to the shortest path to the root

if there is a LAN or bridge tie where both are the same length, then look at the two bridges and the one that has the lowest ID wins

can configure IDs to get a better topology

## Distributed algorithm

algorithm manages the process because humans make mistakes

on boot, all nodes sent that they are the root

decide which nodes should be the root by sending their self ID numbers to each other

race conditions involved when nodes all boot 

(expected root, hops away, source node ID)

all ethernet addresses are globally unique so can always pick the lowest ID

decide on designated port if receive a message from node that is more hops away than you are

because of timeouts, root must send a periodic message stating that it is still the root

root connects up the tree, designated connects down the tree

root is the only that generates messages and triggers the other messages when received

root only has designnated ports

works as an election algorithms

### disaster

if a bridge does not hear anything, starts election process 

when find a node that knows who the root is, tell the lost node that and update designated port 

if connections between network sections broken, the separate sections will run independently

## Forwarding with Spanning tree

everything connected to a LAN sees a message from a host, including all bridges

when a bridge receives a message, it knows where the sender is and if it knows where the receiver is, will forward it that direction

first messages go to all LANs until it finds out where stuff is 

will be on the test





























































