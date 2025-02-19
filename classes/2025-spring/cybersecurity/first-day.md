# First Day

Cybersecurity issues always involve an adversary or an attacker

"Computer systems security studies how systems behave in the presence of an adversary"

the adversary is an intelligence that actively tries to get the system to misbehave

Know your enemy:
- what are their motives? Embarrass a friend or fire missiles?
- what are their capabilities?
- how much access to they have to the system?

Red team: the offense; actively simulating attacks and trying to break in, etc.

Blue team: the defense; responding to threats, patching vulnerabilities, etc.

### Attacker Perspective

look for the weakest links

identify assumptions that security depends on and make them false
- developer assumed that no one would open a certain component and access a port

attackers think outside the box

### Defender Perspective

What assets are we trying to protect?

What properties are we trying to enforce?

Threat model
- who are the attackers?
- what kind of attacks are we trying to prevent

Risk assessment
- only have so many resources that can invest into security, pick the best things to secure against

rational paranoia

Everything can be broken

need to know the ins and outs of how security defenses work


CIA triangle: Confidentiality Integrity Availability

### Confidentiality

Alice does not want anyone besides Bob to read the message

Eavesdropping: man in the middle can intercept and read traffic; solution: encryption
- does not necessarily solve the spoofing problem


### Integrity

Man in the middle: message sent from bob to alice spoofed by Mallory

spoofing: replace original with your own corrupted version

### Availability

Email: not just one server at google head quarters that is a single point of failure

Denial of Service: send tons of packets to a target to exhaust resources

defense: detect and deflect the horde of packets

### Terminology

Threat: any potential occurrence that could harm an asset (malicious or non malicious)

Vulnerability: weakness that makes a threat possible

Attack: intentional action that exploits a vulnerability or enacts a threat

Passive vs Active: listening but not acting vs changing the information

Inside vs Outside

Attack Surface: Area of the system where the attack takes place

### Why are there Vulnerabilities?

Buggy software and lack of security awareness

Need to consider security during design

C is unsafe

Lots of systems are being switched to Rust

Consumers do not care about security
