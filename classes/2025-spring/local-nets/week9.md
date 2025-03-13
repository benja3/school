# Week 9

Going beyond a single node

Discussing shared medium networks, and medium access control

electric signal affects the entire medium; need a way of knowing who it is meant for

## Nodes on the same network

On LANs shared medium is key

pros: broadcast is easy

con: cannot send multiple messages at a time or a collision will occur

ethernet works with different medium types like copper and fiber

protocols established to manage the hardware and things like packet transmission timing

### How Does LAN Work

Source and Destination addresses in the transmission

Recipient decides to receive or drop a transmission

Ethernet addresses statically set in hardware; want a way to make sure no overlap occurs during the manufacturing process

## How Does Ethernet Work

CSMA/CD: carrier sensing multiple access / collision detection
- ethernet protocol
- uses exponential random backoff

Ethernet has two lanes, one for transmission and one for receiving

need an extra wire for collision detection

half / full duplex: can communicate in one or both directions at the same time
- half duplex is the default on a basic wire
- to achieve full duplex, more than one wire is used

modern ethernet switches are smart enough to only forward certain traffic out of certain ports so not every signal is a broadcast and there is less noise

assume everything you see today is a learning switch

on a wire, electric signals keep bouncing around unless the wire is grounded; travel needs to be one way

collision detection only works on a wired network and must be executed by the transmitter
