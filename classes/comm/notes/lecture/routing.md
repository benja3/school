# Routing

<<<<<<< HEAD
## Review

Poisoning prevents a router from thinking it can get back to 

## Dijkstra

find shortest paths from all nodes to source 

can break a tie either way for dijkstra, unlike spanning tree

sparse: small number of connections compared to the number of nodes in the network

can enhance to nlogn if network is sparse

no distributed implementation of dijkstra beacuse it requires all the cost information before running 

## Link-State Routing

distributed and dynamic version of dijkstra

each node nodes knows all the information

communication overhead is much more of an issue than computational

everyone has to get every link state packet, which creates a lot of overhead

link state packet:
- ID of source
- seq number
- Time to live
- distance vector (neighbor, link cost)

contrast with distance vector, which only exchanges packets with neighbors

## Reliable Flooding

sequence number represents the time of the update (iteration)

sequence numbers do not have to be the same across nodes, and are just used for determing when they are sent

LSP: link state packet

increment sequence number for each new LSP

generate LSP periodically or if a change is detected

send local LSP to all neighbors

if recv new LSP store and foward to all neighbors except origin

if miss a sequence number but get the most recent one, does not matter (unlike sliding window)

overhead reduction:
- long timeouts
- sequence number ensure info is new
- 64 bit sequence numbers

what if sequence numbers lost

## Link State Route Calculation

## Exam

spanning tree

subnets

assigning subnet numbers and taking block and assigning subnets to LANs
- assignment must be efficient

CIDR

subnet CIDR combo

distance vector update route

no dijkstra

## Metrics for Weight Assignment

no good guaranteed metric

each organization must come up with own solution


=======
## Overview

russells favorite

forwarding: IO process on router based on table

routing decides how forwarding tables are built

routing table and forwarding table usually the same but not always

there are routing protocols that serve different purposes

want to find best paths between nodes as efficiently as possible
- paths will hardly ever be perfect

can represent a network as a graph where nodes are routers, edges are network links

weights for edges are the same in both directions for our purposes

## Routing

network topology can change, as can traffic conditions

impossible to calculate fasted route due to size of network and potential for topology change

### Ideal Approach

maintain information on each link

calculate fastest path between each directed pair of notes

for each link direction, consider
- bandwidth
- latency
- queueing delay

### Problems

unbounded amount of informatin

rapidly changing queueing delay

BW depends on traffic load

### Solution

adaptive algorithm periodicly recalcualtes routes

distributed algorithm (like spanning tree) so signel failures will not break the system

so many fun hard problems in networking

## Example Algorithms

shortest path algorithms
- bellman-ford
- djikstras

bellman ford based on local iterations

must implement a dynamic distributed shortest path algorithm

### bellman-ford

given directed graph with edge costs and destination node

finds least cost path from each node to the destination

graph theory algorithm

destination based

## Distance Vector

distributed dynamic version of bellman ford algorithm

node maintains table of Destination, cost and next hop

assume cost of links to neighbors are known

distance vector is destination cost pair

refresh existing routes every so often and delete if they time out

slower to converge than link state in some situations

### Changes

occurs when node detects link to neighbor has failed
- not always obvious

current route disappears

current route to dest has less cost or new neighbor

when a link fails, algorithm sets the distance to infinity

### ROtuign loops

possible for cycles of path generations in loops 

can break a loop by setting the infinity value to a finite number of hops 

loops only become an issue with partitioned network 



## Djikstra

maintain confirmed set of the shortest path

look to neighbors and see cost of current path plus path to neighbor

pick any in case of tie
 
 
>>>>>>> 53a6fe6f5858325029cdd5f53a8ebf2ff6876b60

