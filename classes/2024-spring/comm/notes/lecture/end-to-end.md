# End to End Communication

skip 5.3, 5.4 for this class

process to process communication instead of host to host like layer 3

## End to End Service Model

user perspective: functionality and services defined, do not care about implementaitno

focus of end to end procotols are comm between apps

must implement things that cannot be done at lower levels like detecting lost packets

IP services:
- best effort
- host to host with no process context
- drops duplicates and reorders messages
- old packets can show up

end to end services:
- support multiple processes on each host
- guarantee delivery
- deliver in order sent
- only one of each
- support large messages
- support synchronization bewtween sender and receiver
- flow control

transport services:
-

## User Datagram Protocol

simple demux 

unreliable and unordered

no flow control

applicaitons must tolerate these defficiencies and handle them when they occur

checksum to validate header

### demux

packets arrive at UDP, which demuxes port number and sends data to appropriate queue

### header

64 bit

source port, dest port, length, checksum

has UDP header and pseduo header

psuedo header has src and dst IP

## Transmisison Control Protcol TCP

### overview

connection oriented
- must do handshake to set up
- 4 way handshake to tear down connection

only works between two endpoints

has flow control to prevent from overflowing the buffers

congestion control


