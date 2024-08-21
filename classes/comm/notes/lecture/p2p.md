# Point to Point Communication

Abstracting out level 1 due to complexity

Points can communicate over any medium

Exam on Feb 21 or 23

## Encoding

signals propagate over a physical medium such as air or copper or fiber

Can manipulate the electromagnetic energy

### Problems

Problems exist due to physics

Attenuation: signal power absorbed by medium 
- some energy lost in the channel to heat or otherwise

Dispersion: energy is dispersed in the channel and spreads out across the medium
- signals frequencies propagate at different frequencies down the channel, and begin to separate over time

Noise: random background signals that interfere with teh digital signals 

### Encoding Binary to Signals

0 is low signal and 1 is high signal

simple to think of as voltage

Non-Return to Zero (NRZ): low and high signal relative, no voltage means no signal
- can potentially interpret low signal as no signal

Long strings of 1's and 0's create baseline wander: 

## RS-232

Not plug and play, had to manually configure all settings before could be used

## Manchester

a signal change happens for each bit, no matter if there are strings of 1's and 0's

all devices today use this scheme

if string of 1's, clock changes from high to low and then back to high within the duration

Having to change twice per bit duration means 50% efficiency because not all the bandwidth being used to transmit data

## Non Return to Zero Inverted

A 0 is no change and a 1 is an inversion

Causes issues with long sequences of 0's because no changes 

## 4B / 5B

take 4 bit binary strings and conver them into 5 bit codes with lots of changes

no pattern, just a look up table

all 5B codes must have at most 1 leading 0 and at most two trailing 0's

5 bit codes transmitted with NRZI are 80% efficient

## Framing

Must have a framing scheme to know when bits start and stop

Must also be able to analyze correctness of bits

NIC: network interface card
- connected to the bus
- takes symbol input and processes information so it could be put on the bus and used by the rest of the computer

encoding and decoding all happens in hardware

## Framing methods

### Size determination

Determine size of frame by using sentinel strings, which have a unique end of line character like C strings

Could also use a counter to track the number of bits; frames would know how big they are

clock based: all frames are fixed duration and size 

### approach differences

modern networks byte oriented 

### Enables

ask how various combinations and features allow for meeting specifications

efficient error detection

synchronization recovery

multiplexing of link

## Framing With Sentinels

Mark end of frame with special pattern

DLE: data link escape

STX: start and end transmission

if receiver dectects a 0 with 5 1's, it expects to end and if the final are 10, then the frame is done

## Counter Based

include payload length in header

byte oriented

variable length

data independent 

can have issues with corrupted count field, but can apply parity to prevent fatal errors

## Clock Based

continuous stream of fixed length frames

SONET: Synchronous optical Network
- each frame 125 us 

frames arrive synchronously every clock pulse

do not want to have to trash hardware to increase clock speeds

problem: how to recover frame synchronizatoin
- 2 byte synchronization patter starts each frame
- hardware will check for this pattern at the beginning of each block pulse, it can be detected and resolved

how to maintain synchronization:
- 127 bit pattern XORed with data on the way out and on the way in
- probability of having data that ends up with lots of 0's or 1's is extremely low
- adds no overhead

## Merging Sonet Streams

could try to do timing alignment of bytes of packets from different streams onto the same length in a round robin manner, but this has issues due to timings of byte arrival

buffering also not optimal due to wait times 

clock synchronization across the whole internet impossible

### Solution: Float Frame

payload frame floats within clock frame

involves offsetting the frame by an amount specified in the header 

## Error Control Coding

flow: input -> encoder -> modulator -> channel -> symbol estimator -> decoder -> output 

encoding involves adding redundant bits

1/2 rate coding scheme: encoder will turn 100 bits to 200 bits with parity

the bit errors arise in the channel 

### how much redundency

models include probabilities of error per symbol, error location and value independence

probability of burst errors in adjacent signals

ethernet frame can protect 12000 bits with 32 bits 

wireless uses 1/2 rate

## CRC Example

binary finite field: represent data with polynomial 

error modeled with polynomials created by encoder 

decoding the polynomial will tell whether the bits are correct or incorrect, so must throw away whole frame


error locator polynomial: specifies positions for bit errors
- like my bit flipping mask for posits


## Error Detection

### Cyclic Redundency

CRC: cyclic redundancy check

can prove mathematically that things will work well

represent n bit message as n - 1 degree polynomial starting at degree 0 (a 1 in degree 0 is just 1)

to find transmit pnomail shift message by k bits (mulitply pn by x^k) where k is the degree of the divisor polynomial 

when working with these polynomials, 1 + 1 = 1 - 1 = 0 because binary field; addition and subtraction are XOR

x^7 + x^7 = 0

if E is 0, there are no errors

There is a chance that the error polynomial is 0 despite an error, this is unavoidable

P + E is recieved by the decoder C

guaranteed to not detect even number errors, but odd number of errors could be detected

make sure x + 1 is a factor of the error polynomial to detect errors

on hw, factor and see if x  + 1 is a factor 



## Selecting C

make sure x^k and x^0 are 1 

## CRC Hardware

## Internet Checksum Algorithm

## 2D Parity

have 4 rows of 8 bits

calculate row parity and add an additional column with that data

add a new row with teh column parity

corner bit guaranteed to be 1

can send rows and columsn in stream and reconstruts them and copares parity

can be used to isolate bit error between rows and columns, but not perfect

if the number of errors is odd, guaranteed to detect

high desntiry parit codes allow for both detection and correction

most schemes can correct a small (realistic) number of errors

can always detect more errors than you can correct


# Part 2

## Outline

Encoding

Framing

Error Detection

Reliable Transmission
- large / small pipe

Media access control

## Reliable Transmission

achieved by numbering frames and retransmissions of frames that errors are detected in

always want to keep the pipe full regardless of errors

satellite is a "bent pipe" meaning it serves as a relay

### Outline

ARQ: automatic repeat request

Variations:

stop and wait
- send and receive ack if correct

sliding window
- attempt to make stop adn wait more efficient

concurrent channels

use CRC to ensure correctness and use packet label to request another 

overhead goes up

FEC: forward error correction coding
- correct errors on the fly 


### Desirable Features

could be implemented on end to end or link to link
- waste of time to propagate bad messages throughout the network

Assuming implemented at link level

## ARQ

### definitions

acknowledgement
- acknowledgements are CUMULATIVE
- reciever acks specified frame and all previous frames
- an ack says that all frames including n and before were received
- if 5 dropped out of 10, ack 4 but save 6 - 10; when 5 received, ack 10

timeout: sender decided that frame was lost and retries to send

### Stop and wait

can either lose frame or ack

if ack dropped, sender will resend same frame but do not know if the new frame is a duplicate or not

Therefore, add sequence numbers to know which packet is which

if ack is delayed sender will still send another frame but will not know which frame the delayed ack is for if not labeled

only need 1 bit in the header for two sequence numbers in both frames and acks

keep the last number recieved and check if the number is correct

overall 11% efficiency via calculation

### Sorcers Apprentice Bug

when sender receives an ack, immediately sends next frame

to fix, sender should ignore duplicate because do not know which bad scenario happened and it is easier to redo everything than try to fix

despite duplicates, all data still gets ot the destination

## Sliding Window

Allows for multiple otustanding unacked frames

the upper bound on the unacked frames called the window

### When Should Receiver Ack

two approaches 

approach 1: cumulative ack for every frame received

approach 2: do not need to send ack if frame is in window but not in next position (next expected frame)
- sender will likely ignore these acks anyways 
- if 34 is received, but 35 is not, and just received 36 do not send ack 34

## Sliding Window with sequence numbers

if only have 8 sewquence numbers, then when the window slides forwards, the sequence numbers will wrap around

If there are not enough sequence numbers, problems can occur if acknowledgements are lost the protocol will fail

How many sequence numbers are really needed?  

the number of sequence numbers must be larger than the number of outstanding frames 

SWS < (MaxSeqNum + 1) / 2

MaxSeqNum >= SWS + RWS

need to avoid worst case where the reciever window advances past the sender 

ARQ: automatic repeat request: general strategy of using acks and timeouts to implement reliable protocols
- simplest is stop and wait
- includes sliding window

Basic algorithms:
- stop and wait: SWS = 1; RWS = 1;
- go back n: SWS = N; RWS = 1
- selective repeat: SWS = N; RWS = M

go back n good for keeping the pipe full when frames rarely lost
- if frame lost, all frames that are in the senders window must be retransmitted

receiver buffer size should always be less than sender because the extra receiver space would never be filled 

Sender buffer size should always be large enough to fill the pipe

### Variations

must have timeout when frame lost to prevent sorcerers apprentice bug 

could send cumulative acks for frames that arrive our of order, but this is difficult to implement 

### Important Assumptions

assume that frames do not arrive out of order

if frame 1 send before frame 2, it will always arrive before before frame 2
- reasonable for single physical link, but becomes problematic when routers and switches get involved 



























