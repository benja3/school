# Network Programming

lots of time to do MP1; should not take a long time but do not procrastinate

see resources on first slide 

## Motivation

sockets: transport layer interface 

## Command Line tools

ip, host, dig, netstat, iptables, ping, traceroute

## Client Server Model

easy to think about networking problems with this model

sockets written to support this model, but can work with others

### Daemons

servers called daemons in linux 

has a well known name and port, and waits to be contacted with information

concurrent: simulataneous client exchanges

sequential: one client at a time

hybrid: maintain multiple connections but process one at a time

sockets designed to be concurrent

### Client

initiates connection and waites for response 

## IPs and Port Numbers

to connect, must know IP and Port

IP: identifies machine

Port: indentifies process running on machine 

multihomed: multiple IPs for different interfaces (WiFi, ethernet, Infiniband, etc.)

processes must be bound to port number to communicate on network

each OS manages its own ports

## Concurrent Servers

information necessary for socket:
- Local IP
- Local Port
- Foreign IP
- Foreign Port

sockets exist in forked child processes so can have multiple sockets for a single port 

socket: channel between processes on two computers

binding: reserve socket for communication

The port number on a client does not matter because no one will need to reach it

ephemeral: exists for time that is needed and then destroyed 

port numbers limitied to 16 bit / 65536

to transport packet, headers for each layer are built as the packet descents

packet structures all the same for communication protocols

fork good way to do this because it does not share memory and is more secure 

mapping of child processes to sockets is managed by the OS

a new port is opened on the client to distinguish packets from parent and child

## TCP Connections

transmission control protocol

exists as a user space process and can be manipulated

### Connection Oriented

Establish connection to the other end before sending data by sending multiple packets

must close connection at the end

Most of the internet does not prioritize this and just sends data 

### Reliability

This connection makes TCP more reliable by ensuring packet retransmission

### Flow Control

Manage the amount of data sent to optimize throughput 

make sure to not send more data than the destination can receive

reduces global congestion

### Full Duplex

Sockets can be used in both directions

16 bit port numbers so can have 65536 sockets


### TCP Negotiation 

client initializes connection

first packet called synchronization packet, contains signature saying wants to initilize

sets of sequence random numbers for flow from dest to host and host to dest

acknowledgement is x + 1 where x is the sequence number from the orignal message 

### TCP Termination

client sends close signal and server immediately responds with an acknowledgement

server sends final close signal when ready, and client sends ack 

## UDP Services 

User datagram protocol 

TCP solves a lot of UDP problems, but requires more overhead

Reliable without packet dropping on local network

### connectionless

no session established

best effort: packets could be dropped

packets are variable length

### Not reliable

IP layer can drop packes without error message 

no end to end acks

data may arrive out of order

no overhead from connection management

## Network Functions

functions: ```socket```, ```bind```, ```listen```, ```accept```

listen: tells OS that the server is ready to accept clients
- can be toggled
- does not destruct the sever when listen is off

accept: 
- blocking command: code waits until operation completed

socket: creates a local data structure necessary for connection

client/server can call send and recv functions

must kill server process when done or it will hold the port number

connect initializes TCP handshake

### Client

accept blocks until the server returns 

### Server Functions

socket, bind 

bind function will reserve a port for this proces

## Socket Calls for UDP

### Client

calls socket

first calls sendto to send a message to the listener

### Listener

type of server that listens for connections to come in

calls socket/bind

recvfrom function blocks until recieve data

will recieve sendto from client and respond with data 

## Socket API

all calls are C system calls 

incldue sys/types.h and sys/socket.h

### socket

domain: address family

type: comm style

protocol

returns the socket number (return value called a handle)

### bind

socket number (return value from socket function)

### listen

put socket into passive state, wait for connection from client

takes backlog argument that is a bound on the length of unaccepted connecion queue 

### accept

used by server to accept new connection from client 

### Connect



## Port numbers

well known: 0 - 1023

registered ports: 1024 - 49151
- registered but not restricted 
- can also be used for ephemeral ports

private/ephemeral: 49152 - 65535
- reserved solely for ephemeral ports

## Fork Example

can do !fork() to identify parent and child process 

child closes the orignial socketfd 

## Connection Oriented Exchange

cannot recieve on sockfd after it is closed 

draw out the model to make sure you know where you are listening 

write jokes as messages 

do knock knock jokes




















