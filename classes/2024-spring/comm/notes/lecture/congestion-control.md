# Congestion Control

## Problem: allocating resources

fast links coming into a router and slow link leaving; buffer overflows and packets are dropped

instead of preventing congestion, control it when it occurs

### two poitns of implementaitn

hosts at the edge of the network and routers inside the network

## Framework

connectionless flows

sequences of packets sent between source and destination pair

a flow is essentially a path through the network

want to provide fairness among flows

lots of bookkeeping requierd to manageflows, so not done

## Cost of Congestion

### infinite buffers

input and output increase linearly to a point and then no more output despite input increase

delay increases exponentially as input increases

### finite buffers 

real world

packets are dropped

sender must perform retransmission to compensate for dropped packets

## What is fair?

no definite solution 

can try to set up min max problem

## Queueing

### first in first out

### priority queues

can starve lower priority devices

### fair

segregates traffic based on flows

if packets are equal length, each flow gets even access

if packets are different length, let each flow get to transmit the same number of bytes

if a queue is empty, move on to the next

### weighted fair

can set fractions of capacity for different flows

Si = Si + P/wi

just divide the packet sizes by the weight so they do not fill up the service counter as quickly

can make jobs that are long let smaller jobs go first to reduce average delay








