# ALUs

## What is an ALU?

Circuit that performs various boolean and arithmetic operations

perfoms AND, OR, NOT, addition, subtraction, x, /, etc.

fixed point operants: integers (not floating point)

Can do fractions with fixed point if decimal is fixed at a specific place

## Addition

Can be done with 1 bit adder

full adders take in the two numbers to add and the carry 

### Ripple adder

full adders connected in chain such that outputs and  inputs are in parallel and carry outs connect to carry ins in series

delay for carry to propagate through the whole thing

good for when space is more important than speed

### Carry Look Ahead

Carry generated in advance so it is ready at the same time as addition

carry predicted before it is needed for the sum

time to predict carries not constatn and increases with teh side of the adder, but significantly faster than ripple adder

### Negative Integers

Three ways to represent negative numbers
- 1's complement
- 2's complement
- sign magnitude

1's comp: invert all bits

2's comp: invert all and add 1

### Why 2's complement so popular

makes subtraction easy

with 1's complement, must remove extra sign bit to adjust back to original

## Multiplication

methods:
- add shift
- booth recoding
- bit pair recoding
- array mutlipliers
- table look up

table look up used more for division than multiplication

can be thought of as repeated addition

product is twice the length of the operands

### Sequential Add Shift

multiplier is the one on the bottom, multiplicand is on top

for negative multipliers, convert two complment first

### Implementation Issues

single adder accumulates partial products in a register

### Design 1

control unit generates signals to control the datapath
- represented by state machine

shift all bits of multiplier number and let the last bit decide whether to add 0 or another copy
- the answer will be iflled into the other bits as the mutliplication occurs

Can think about problem mathematically or with respect to digital machines
- translating problems to different paradigms can present different solutions

do not deal with negative multipliers

multiplicand is being multiplied by the multiplier that number of times

see example in slides for process 


### Sign Extension 

sign extension: 07 = 007 = 0007
- can keep adding 0's to the left
- only works for positive numbers

in 2s comp numbers, the most significant bit is always 1
- for these, must add 1's instead of 0s

  1101
 11101
111101

just duplicate the most significant bit to extend sign

### algorithmic state machine

another representation of state machine

numbers in top left of rectabnles state names, rectangles are states

diamonds are decision boxes

can contain mealy outputs in the transitions and moore outputs in the states

can represent processes within the states and with Ovals

Can fit more information in this schematic than a regular state machine






