# Synchronous Sequential Logic

## Overview

circuits with states

based on synchronous clock

depends on past behavior and present inputs

involves D Flip Flops
- can be done with J and K Flip flops but more complicated

Finite state machines and designing state machines in VHDL

## States

feedback allows circuit to store information bsaed on previous input

there is a path between previous inputs and current state

next state is a function of the current inputs inputs and current state (based on previous input)

These are called finite state machines

synchronous logic built out of asynchronous components

sequential logic just combinational logic where the outputs feed back to the inputs

set up time: time before the clock edge where the input to the flip flop must be stable

hold time: input must be consistent for a certain amount of time after the clock edge

this information is contained in timing diagrams

do not get too agressive with set up and hold times

## Example: counter

increment a count on every clock tick

simply use an adder and a flip flop such that the two inputs to the adder are 1 and the output of the flip flop

## Two Types of Finitate State Machines

Moore vs Mealy

difference is the way the inputs are connected to the output

Moore: outputs determined strictly from current state and not the inputs
- no outputs during state transitions



Mealy: inputs do not have to propgagate through the sequential section fo the circuit to reach the output
- outputs can react as soon as inputs do
- some input -> combiational -> output
- clock does not have to be involved when these inputs
- asynchrnousous logic can be included in the state machine
- output not synchronized with the clock

## Sequential Circuit Design steps

### State Diagram

REVIEW

how many states needed and what are transitions?

if output is delayed, usually means moore machine

### Translate to State Table

represents state diagram containing 

REVIEW

### State assignmets

must decide on bit representation of states

makes it easier to figure out how the logic will be structured

### chose FF and next state and output experssions



### implemenat and analyze timing diagram

## State Encoding

### Gray code

sequence of codes where consecutive codes only vary by 1 bit

### one hot

advantages:
- simpler and smaller equations
- each flip flop set to 1 for transitions into only 1 state

requires more flip flops than other implementations

can use no hot assignment for initial state that is all 0s to represent start

## Unused States

minimal risk: assume state machine can enter an unsused state, and therefore identify them all and go back to a known state in this situation

minimal cost: assume state machine will never enter undefined states

## traffic light controller

light must be yellow during transition from red to green

if green in one direction, must be red in the other

if car waiting east-west, it should become green before returning to north-south

to vary the time for different states, use counters that wait for a certain number of clock cycles

VHDL:

represent states at constants in architecture

declare state register; just need 1 because only in 1 state at a time

implement the combinational logic as a process

moore outputs simple: output when state is case

using VHDL makes it easier, as opposed to doing k maps and other logic math

## State Machine VHDL

can implement the clock in a process that will keep it symmetric

in the past, having compact and efficient code was important, but now, people and time are the most expensive resources so writing code that is dense and complex is counter intuitive

Flip flops are delay elements; delay the input until the clock cycle

Does optimization automatically so user does not have to worry about doing state minimization

state minimization: there is more than 1 way to implement a state machine and the first way the engineer comes to is not always the most efficient

two states are said to be equal if for every possible input sequence, the outputs will be the same

### Equivalent States

All I/O relationships are the same despite the path taken between the states

### Partitioning Minimization

partition consists of one or more blocks that comprise a subset of state that might be equivalent; states in blocks not equivalent to states in any other block

start with one big block, find ways of determining whether sates are equivalent and divide block into partitions

Practice this for test

## Timing

Propagation delay: time from last input change to last output change 

contamination delay: time from first input change until first output change

if both a high and a low line in timing diagram, do not know for sure what the state is

both values might not be the same because the input and outputs might not flow through the same gates

### Example

full adder because two inputs, carry in as inputs and outputs are carry out and sum

create tables for min and max delay going from different gates to other gates

with multi input gates with heirarchical structure for fan out regions, input and output times can be different depending on the internal structure of the gate

must consider contanmination even if the input changes to the same state

can see synthesis reports for details on netlist

contamination delay not the same thing as minimum delay
- contamination: minimum time from input to output
- minimum: time from input signal to CORRECT output

if an input changes and the output changes after the contamination delay, cannot assume it is correct until after the minimum delay



## Synthesis Report 

a net is like a node in electric circuits

a cell is a gate or collection of gates that are connected together directly

## Set up time constraint

goal is to optimize the amount of slack between hold times and set up times such that the system performs as fast as possible, but does not have errors


must calculate necessary set up times for multi layer syncrhonous logic because they can stack and influence each other

bigger and more complex logic must be clocked slower because everything needs more time to set up

if clock pulses before the signal has propagated through the system, the value will not be latched in correctly

## Summary of Delays

Digital systems experience delays from contamination and propagation

## Counter Design Example

### JK flip flop

JK = 00: do nothing

JK = 01: reset

JK = 10: set

JK = 11: toggle

Can to ternary operator with ? : in VHDL

data path is the process that user program related data takes in the machine and contains a lot of registers and multipliers and adders

the control system for the datapath is a state machine that will take user program input and perform appropriate operations on the data

### Symbolic Table

6d"5" means represent the number 5 as 6 bit binary

### Up Down Load (UDL Counter)

Deluxe counter that can count up, count down and be loaded with a value

inputs
- in
- rst
- up
- down
- load

up, down and load guaranteed ot be one hot

can encode input priority with don't care statements. If there is a 1 or in a certain place can automatically trigger something regardless of the other bits.



















