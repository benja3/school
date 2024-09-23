# Shared Access Netowrks

reliable transmission protocols allows for reliable communicaton between a and b and keepign the link full as possible

delay bandwidth product for wifi and ethernet not vey high

for shared netowrks, must be able to share a link between mulitple devices and govern who uses it when

Main example: wireless has multiple devices communicating over the air medium 

all shared networks need a broadcast mode to know what all is connected to the network

## Typical Assumptions

communication requirements vary over time and between hosts

statistical mulitplexing is still appropriate
- provides time slots for access to the channel on demand as opposed to frequency division or time division

## Statistical multiplexing problems

demands to channel can cause conflict

two hosts send at the same time and statistical multiplixing cannot handle it

need Medium Access Control (MAC) protocol to solbe this

two MAC approaches, both called CSMA

### Collision Detection

if you can tell someone is transmitting then don't transmit

stop sending immediately if sending detected

CSMA/CD (collision detection)

easy to detect conflicts in wired environment but not wiresless
-  cannot recieve while transmitting because output is so loud

### Collision Avoidance

Aloha: transmit if believe channel idle

ask if receiver free and if ok send message

## Ethernet Overview

developed and standardized by Xerox 

ended up as an IEEE standard 802.3

CSMA/CD: Carrier Sense Multiple Access / Collision Detection

Bandwidth: scaled up to 10 Gbps +; the reason ethernet is so popular

new versions of 802 must be backwards compatible with older versions so all hardware does not have to be replaced

sometimes collsion detection can be difficult to detect and correct, so try to avoid at all costs, but in environments where collisions are easy to detect and correct, just corrent them

## Bus

all nodes connected together with a single Coax cable

computers have NICs which are connected to the bus 

no switches or anything, just a copper connection to all nodes

### 10Base5

10 megabits per second / 5 something length cable

cable is copper with shielding to prevent emag noise from messing with it

Vampire tap: pin that pokes through the shielding of the cable and into the copper to add a new connection to is

use repeaters to boost the signals coming down the cable
- could use 4 and get 5 500m coax cables for a total length of 2500 m

expensive cables

all shared link technology is backwards compatiable to appear like they are all connected to a coax cable

### 10Base2

ThinNet

thinner but shorter cables that are less expensive

## Star

have connection points and connect 

### 10BaseT

twisted pair

using a single cable was primitive technology and broke easily

all devices connected to hub instead of directly to bus

backwords compatible with the copper cable bus technology 


### 10 Mbps Ethernet

Xerox

manchester encoding

framing with sentinels
- if sentinel being transmitted, but handle bit stuffing

IEEE 803.2 similar but uses length field instead of sentienl
- still works with sentinel from Xerox

### Frame Format

preamble: 7 bytes of 10101010  and 10101011
- synchronized the recievers clock

addresses are unique 48 bit 
- each manufacturer assigned a 24 bit prefix and the remaining 24 are globally unique
- burned into hardware

broadcast address all 1's

Adress resolutoin protoco(ARP): converts netowkr sddress to phsycial address (MAC)
- only need to know the local address on the local network 
-  can send a broadcast message to get the MAC of other devices 

DNS is a huge system that allows for any hostname to be turned in to an IP address

2 byte type field can be demultiplexed to higher level protocl

body contains up to 1500 bytes of data and must contain at least 46 bytes of data 
- higher level protocol must give ethernet at least 46 bytes
- ensures that the frame is long enough to detect collisions
- pad if necessary

## Transmit Algorithm

If line is idle and no carrier sensed, send immediately

Must wait 9.6 microseconds between back to back messages

If line is busy (carrier sensed), wait until idle and transmit immediately

to detect if line busy, look for voltage changes, which happen frequently because manchester encoding involves lots of changes

This protocol does not attempt to avoid collisions because they are easy to detect and resolve

### Receiver

simply accepts frame if CRC passes

checks that no other signals are on the line while transmission occufrs

MAC protocol gaurantees that all nodes recieved transmission

## Collisions

occur when two nodes think the channel is empty and start transmitting at the same time

when collection detected, transmit jamming 32 bit pattern

Make the collision really obvious so everyone knows there has been an issue

a minimum 96  bits will be transmitted: 64 preamble + 32 jam
- will finish preamble before jamming signal 

### Detecting collisons

collision detectected by voltages on the cable not being 5 or 0

frame stored in ethernet card, transmitter tells receiver to listen and see if channel is free


### Binary exponential backoff

after collision, delay and try again

if delay for all is the same, guaranteed to have collision again

max backoff delay doubles after each failure

give up after 16 times, after 10 attempts stop doubling window time 

time slot is worst case round trip time


## Hubs

collisions are detected by more than one port receiving input traffic at a time

### switched hubs

unused lines can be used to switch other traffic

takes advantage of full duplex

## General

ethernet works best under light loads, these loads limited by flow control 

when heavy loads, lots of collisions occur degrading performance

ethernet responds to these heavy loads by reducing window size and transmission rates

ethernet works well with TCP which has built in flow control

star topology with switch easier to mainatain than having everythign ocnnected to a single cable

difference between cat 3 and 5 cables: how many twists within the cable
- more twists leads to large improvment 

### gigabit ethernet

since increasing data rate so much, have to increase the minimum size of the frame from 64 to 512 bytes

### 10 gigabit

fiber cables usually have many strands of fibers to maximize throughput

all ethernet is backwards compatible















