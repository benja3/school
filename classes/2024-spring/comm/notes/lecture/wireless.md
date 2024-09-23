# Wireless

802.11: Wifi
802.15.1: bluetooth
802.16: WiMAX: greedy corporate version of wifi

## Wireless LANs

goal is ethernet like access for laptops, want it to be wireless because laptops are mobile

call the white box on the ceiling or wall an access point or router

### frequency bands 

wireless uses frequency bands, which must be allocated by government

left over bands from gov experiments: 915 M, 2.4G, 5G

these frequencies are are polluted by random electronics that create interference and noise

called junk bands

wifi and bluetooth got to use these bands as an experiment

general idea is ownership of frequency bands

ISM band is not harshly controlled like radio, so can make devices that communicate over wifi without applying to FCC

There are channels at different frequencies that reside within the range of a band lke 2.4G
- band divided into smaller ranges

want to be on channel 1 6 or 11

channels are also divided up into different standards

government can set aside frequency bands within something like 5G for different applications

goal is to get as much capcity with all the different users within the frequency band

5G has much more channels than 2.4G

software tries to select channel that does not have a lot of interference

## Physcial Layer

### original standard

want to spread energy out in pseduo random manner across the frequency spectrum, and then reassemble on arrival

reduce the probability of errors

if some is disipated due to interference in one frequency, can likely reconstruct 

developed my military to be jam resistance

bluetooth uses frequency hop, wifi uses direct sequence spread spectrum

### new additions

can do better

formed two groups: 802.11a/b

OFDM: orthogonal frequency division multiplexing

a was trying to operate at 5G which was too expensive at first, but has not become more practical

b group sticks with DSSS but makes it high rate
- uses similar design but large improvements

data rate always limited by interference from surrounding like walls and trees

systems will adapt data rate based on channel quality

a is very sophisticated scheme so it was not economically competetive

b group copied the idea and implemented it at 2.4 and got it to market much faster

diversity: sample on all channels and detect which one is best

MIMO: multiple input multiple output

omnidirectional: antenna sends signal in all directions

directional: sends signal mostly in a beam 

can use digitla techniques to make an omnidirectional signla multidirectional

## Spread Spectrum Signaling

idea is to add pseudo random component to signal

piano has 88 keys that represent frequencies; what if sender jumped around to different frequencies but the receiver knew the pattern? 

reduces probability of two devices communicating on same channel at once

without doing this, both devices would have to agree on a channel in advance 

if both choose teh same, called a hit and the signal will be degraded; can use error correcting codes to fix teh broken signals

## OFDM in 2.4 and 5

### FFT: fast fourier transform

digital implemenation of fourier transform

done as an integral of sine waves with different frequencies

inverse produces imaginary and digitlal component of time 

## Review

line of sight: no obstacles can be in the way of the signal or it will be absorbed

very high frequencies get absorbed easily

## Wireless Channel Access

problem: RF may not be fully shared if all nodes cannot hear each other

energy detector could detect signals that are not related to wifi

Layer 2

## 802.11 DCF

what if data packets small?

if data is small enough, transmit carefully

do not give users too much capability or they will find a way to break your system

not practical to send out a CTS in response to broadcast

upon design, assumed that the channel would be busy and noisy and had to accomodate for this

802.11 and bluetooth jam each other, but can use different channels so collisions are not as likely to occur

## Supporting Mobility

### Infrastructure Based Networks

mobile nodes communicate with access points

acces points connected to ethernet

new home wifi technologies realease features on top of teh link layer 

### ad hoc

does not require infrastructure

example: hurricane knocks out access points and emergency workers still need to communicate
- could make a network on the fly using technology in vehicles and other tools

need to bring all the infrastructure yourself and make it dynamically accessible on the fly

no commercial product available 

## Infrastracutre based LANs

all wiresless transmission between access points and nodes

place access points so can get reasonable coverage

overlaps between access point regions can create overlap

mobile devices can only communicate with access points; no device to device communication

different access points communicate through ethernet

## Finding Access Point

node will send out a probe message in broadcast form, and any nearby access points will respond with information

## handoffs

probing only done when there is no connected access point

what if you move out of range?

if wait too long, have to probe again

### beacon frames

access point sends out frame letting it know that it is there

if get closer to a new access point, its beacon will be louder and the node will know to perform the handoff

handling the beacon is up to the manufacturer

## Access point placement

propagation is hard to predict and can be interfered with by obstacles

must think 3d

microwaves operate at 2.4G at much larger power, but are shielded and do not leak energy 
- do not put AP near microwave

human bodies can cause interference and large crowds can cause signal interference

access points that are too close together cannot be accessed at the same time because of the RTS sends 

## Ad Hoc and Mobility

use DCF mode like before

not single wireless link to access point, but a bunch of individual radios

each radio has a communication range

assume all nodes are mobile which makes routing challenging

no universal solution to routing in ad hoc

mesh network: some access points but instead of a single wireless like, can have relays between nodes in some cases

## Bluetooth

bluetooth because low data rate is higher priority

range: 10 m

transmission rate: 1-3 Mbps


















