# Exam 1 Concept Review

## General 

Point to point: each node has a direct connection to something else that is only shared between those two nodes

Multiple access: all nodes share the same channel

packet switching: store and forward messages; divide data into packets and send them one at a time to their respective destinations

Statistical multiplexing: like time division where each input gets a chance to use the output, but based on demand 
- has issues with congestion

### OSI Layers

Application

Presentation

Session

Layer 4: transport
- used by applications to send useful data to other systems
- HTTP, TCP, etc.

Layer 3: internet
- involves resolving the location of nodes on the greater internet
- IP
- packet switching 

Layer 2: data link
- involves controlling a physical medium such that data can be transferred across it in an effective and reliable manner

Layer 1: physical
- electromagnetic energy flowing down a cable 

##  Performance Metrics

### Bandwidth

measure of the frequency band of a singnal

represents the amount of data that can be transfered in a given unit of time

### Throughput

performance measurement 

used by applications to describe the amount of meaninful data that can be transfered 

Byte measurements:
- 10 Kbps: 10^3 bits per second
- KB: 2^10 bytes

### Latency

time to send a message from point A to B

can be represented as one way or round trip

components:
- propagation: distance / speed of light; time it takes for the signal to travel across the physical medium
- transmit: size / bandwidth; time for sender to transmit all the  bits across the medium
- queue: time message spends waiting in router queues on its way

speed of light: 
- in vacuum: 3 * 10^8 m/s
- in cable: 2.3 * 10^8 m/s

# Exam 1 Review

## Socket 

an API on the transport interface used to 

### Structure

consists of 2 IPs and two ports, one for each machine

### Creation

on server side, the server process will fork

client process uses an ephemeral port assuming the connection will only be temporary

different client processes must use sockets with different ephemeral ports to connect

## TCP

connection oriented, so establishes stable connection to other end before sending data

data is delivered as a stream of bytes

has flow control, which prevents the sending of information the destination cannot store

REVIEW SOCKET FUNCTIONS 

## UDP

connectionless protocol, no session is established, just sends data and hopes for the best

best effort service, so does not worry about dropped packets or packets arriving out of order

no acknowledgements

## Byte Order

computers use big and little endian to store bytes, but internet adopted big endian

# Peer to Peer

## Encoding

### problems with transmission

attenuation: signal power absorbed by medium

dispersion: discrete signal spreads in space

noise: random background signals

### NRZ

fixed voltages for low and high values

can be anything, but common are -3,+3 and 0,5

consecutive 1's and 0's are difficult to process and the clock synchronization can break if the signal does not change frequently

for clock management purposes, the clock must be encoded in the data signal somehow 

### Manchester

merges clock with signal

to represent 0: signal changes from low to high 
to represent 1: signal changes from high to low

### NRZI

Invert the signal for 1 but stay the same to encode 0

this works with lots of consecutive ones but not with consecutive 0's because the signal will stay the same

### 4B/5B

encode 4 bits of data with 5 bit code that contains enough ones to not cause the issue of the signal staying the same for too long

the 5 bit codes have special requirements so that more than 3 consecutive 0's will never be output with any combination

solves consecutive 0's problem when transmitted with NRZI

## Framing

Framing organizes data into transferable units by separating a continuous stream of data into frames and sending each independently

Implemented in hardware on NIC

enables efficient error detection and link multiplexing

### sentinels

mark the end of a frame with special bytes or bit patterns

requires bit stuffing

frame length depends on the size of the data

BISYNC:
- byte oriented sential based
- contains special bytes DLE (data link escape) and STX/ETX (start / end transmission)
- to stuff ETX sent as DLE and TEX
- DLE sent as two DLE
- DLE is an escape and will interpret the next byte exactly how it comes

HDLC:
- bit oriented
- has a flag: 01111110
- sender will insert a 0 after 5 consecutive 1's
- if more than 5 ones after a 0 encountered, end of frame

Counter based:
- include the length of the payload in the header
- problematic if the length is corrupted

## Error Control Coding

error detection validates the correctness of each frame

focus on bit error detection and correction

do decide how much redundancy is necessary, consider the probability of an error per symbol, the impact of errors in specific locations

### Error models

independent: considers the probability of an error in each invididual position without considering others around it

burst: probability for error in adjacent symbols

### Cyclic Redundancy Check (CRC)

uses powerful polynomial math that has a simple hardware implementation

can detect but not corret

represent n bit messages as n degree polynomial with binary variables

transmit polynomial P that is evenly divisible by C 

divide the result by C and if remainder is non 0, there was an error

REVIEW THIS 

Selecting C(x):
- x^k and x^0 should have coefficients of 1
- should contain factor (x + 1)

to create an error that cannot be detected: E = C * Q where Q is a multiple of C (any polynomial)

### 2D parity

good for burst errors

### SONET

synchronous optical network

wait 9.6 us when transmitting ethernet so each node gets a chance to transmit and no one hogs the line

all network protcols define service and peer to peer interface 
- service: how applications can use the protocol
- peer to peer: how the protocol communicated with other devices

SONET frames are fixed length

to find smallest frame size for max throughput: total delay / one way travel time 













