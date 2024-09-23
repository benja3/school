# TCP

## end to end vs link issues

why does TCP do so much and IP doesn't

TCP is end to end

round trip time varies between packets

packets do not last more than 1 - 2 minutes

peer capabilities vary, so need a protocol to make decision based on things like buffer space

TCP uses sliding window

The overall data transfer from end to end requires a bigger picture view of the network that cannot be achieved at the link level

In general, if insufficient information to implement at lower level, implement at higher level

## Data Transport Model

data is broken into small segments because fragmentation is evil

called max segment size (MSS) and is 536 bytes

three events can cause send
- collected MSS bytes
- explicit push operation by app
- timeout 

## TCP header format

src port, dst port

sequence number: packets do not come in in the order they were sent

acknowledgement

header length: can add more options than the default

advertised window: mechanism for flow control

urgent pointer: never used; says that there is very important data at that location

checksum: 16 bit, required

### flags

fin: final segment for teardown

ack: ack seq num valid

syn: synchronize segment for set up

rst: reset connection

urg: urgent pointer is set

## Connection Establishment

three way handshake to set up

see drawing

## Segment Format

connection identified by (src port, src IP, dst port, dst IP)

tcpdump shows all of this info

## State Transition Diagram

will be given the diagram, do not have to memorize

all states in event/action format
- event occurs at higher level and action occurs at lower level protocol

start at closed state; one host becomes the server and calls passive open 

passive open is the action and listen is the tcp action

the node that receives the intial connection will call active open, which takes it straight to SYN_SENT instead of LISTEN

both sides will negotiate and reach the ESTABLISHED state

in the hw, label the connection diagram with states

at the end of teardown, leave FIN_WAIT after timeout


## TCP Variant of Sliding Window

ack is next expected instead of last received; can still get the same info from this

must think about from POV of both hosts

application can only read data within the window

advertised window represents amount of space at the receiver

for the sender, advertised window represents sent but not acked data

flow control adjust size of advertised window

if application cannot read fast enough, the advertised wimdow can fill up
- sender will know this because advertised window size if 0
- prevents sender from sending data that will get thrown away

## Flow control issues

### problem: slow receiver application

adv win goes to 0, sender cannot send, receiver may not generate a packet updating the size

solution: sender periodically sends 1 byte segment ignoring advertised window of 0

receiver will trow this away or respond with new advertised window size

always send an ack in response to arriving data

### problem: slow application reads data in tiny pieces

do not read data in tiny pieces like you do in every program you write

reading 1 byte from a TCP buffer will make advertised window size increased by 1 byte, causing a new packet to be sent with 1 byte -> 40 byte header for 1 byte = terrible performance

called silly window syndrome

solution: receiver opens advertised window only when MSS of 1/2 buffer is avilable

### problem: application delivers tiny pieces of data to TCP

ssh: ls characters have to travel across the internet to the device and it will respond with filename characters

the ls packet will only have a few data bytes

solution: nagle's algorithm: delay transmission to accumulate more data

for some purposes (mouse), this does not work well

### wrap around transmission

sequence numbers are indexes into the byte field

a data rate of 573 Mbps will cause seq num wrap around

### keeping pipe full

16 bit advertised window

## Adaptive Retransmission

### Karn Partridge Algorithm

### Jacobson / Karels

guaranteed final question: in advantage to avg RTT, what is used to calulate ...? variance

if you are collecting data and need to calculate an an avg or var, use these formulas

## TCP opetions

negotite MSS: each host suggests a value and the minumun of the two is choses to prevent fragmentation

PAWS: protection for wrap around sequence numbers

## Additive Increase / multuplicative decrease

objective adjust to changes in capacity

final question on keeping pipe full and proper buffer size

slowly increase window size when congestion goes down

quickly decrease window size when congestion goes up

how to determine ocngestion? timeouts

losts packets imply congestions

in theory increment congestion window size by 1 packet per RTT

when timeout occurs, divide by 2

sawtooth behavior 

words are inefficient way of encoding graphical informatin

congestion window problem will be on the final

this process required for fair sharing of capacity

see slide with graph of flow balance

the combination of additive input and multiplicitave decrease is required for this to work peroprly

## SLow Start

begin with 1 packet window and double with each RTT

exponential growth is slower than sending advertised window at one, but faster than additive ncrease]

packets are spaced out so buffer overflow does not occur

tcp deliberatley creates congetion until it figues out the limit

coarse grain timeout: ??? 

congestion threshold: half of the value where congestion was created

when reach congestion threshould, switch from exponential increase to additive

duplicate acks can also trigger congentio warning

go back to window size of 1 after cognetion detected and use exponential increase until half congestion threshold

coarse grain timers lead to idle periods

### fast retransmit and recovery

avoids long periods where no packets are sent

review

### congestion avoidance

alternative strategy is to predict when congestion is about to happen and reduce rates before packet loss

### Random Early Detection (RED)

clever

what do we have that can use to indicate congetion?
- timeout
- duplicate ack

can TCP be fooled into thinking ther was congestion to back off on window size

why random? if randomly selected packets drop, high probability that the more congested flow will be dropped

this reqires creativity to think of






