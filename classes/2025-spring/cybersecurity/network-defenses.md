# Network Defenses

## Firewall

Like a bouncer for a network; decides what to let in and what not to

### Stateful and Stateless Firewalls

stateless: maintain a static filter list
- examine each packet and look at IP and port

Modern firewalls are stateful:
- maintain dynamic list of ongoing flows
- better capabilities but harder to scale

### Packet Filtering

Uses transport and IP layer information only
- src/dest IP
- Protocol
- src/dest port

Example rules:
- DROP ALL INBOUND PACKETS TO TCP PORT 445
- DROP ALL INBOUND PACKETS IF DEST PORT != 443

An ICMP echo request is a fancy name for ping

### stateful filtering

firewall tracks outcoing connections ...

### local vs network

firewalls can run on network hardware like routers, or on individual devices

Linux uses iptables

Combinations of network and local firewalls are typically used

## Intrustion Detection System

Software to monitor network traffic for attacks or policy violations

Violations are reported to a SIEM for analysts to see

### Signature Detection

Maintains long list of traffic patterns and rules associated with attacks

### Anomaly Detection

Attempts to learn normal behavior and report deviations

## Virtual Private Networks (VPNs)

Problem: how to provide secure communication for non TLS protocols across the public internet

Solution: VPNs create a fake shared network on which traffic is encrypted

Do not need a VPN for HTTPS because the traffic is already encrypted
