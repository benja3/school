# Simple Processor Engineering Process

## Overview

### Questions


Why no data bus output 

Done timing

Subtraction always 0 


### general 

DIN separated into 8 instruction bits and 8 data bits?

Does order matter?

Is the instruction component of DIN passed around to all the registers?

Assuming instruction width remains the same, so with 8 bit total width, do we use less registers to get enough bits for data?




### Requirements


Implementing a simple 4 instruction processor in VHDL. 

Design should be structural at the top level entity, and all lower level functionality should be modular in components.

Must create state machine with diagram

data width should be generic and not fixed

See instructions for schematic

inputs:
- DIN (16 bit)
- clock
- run
- reset 

outputs:
- bus (16 bit)
- done

testbench with 16 bit width and on board with 8 bit

### Instructions

mv Rx,Ry: move data from Rx into Ry

mvi Rx,#D: move data from DIN bus (#D) into Rx
- value must be on #D when instruction executed

add Rx,Ry: add values in Rx and Ry, storing results in Rx

sub Rx,Ry; subtract values in Rx and Ry, storing results in Rx

encode instructions as IIXXXYYY where the two "I" bits represent the instruction, the "X" bits represent the Rx and the "Y" bits encode Ry

## Research

### VHDL Generics


## Imagine

### General

The multiplexer decides which of #D and R0-7 should be on the bus. 

Some instructions will take multiple clock cycles to complete

Depending on the instruction and state, data will be moved to different places in the processor

### Control Unit FSM

responsible for activating all components at the appropriate times 

has connections to all registers, the multiplexer and the ALU

a portion of DIN feeds into the instruction register which is how the processor gets its instructions

inputs to watch: clk, reset, run, instruction register

need to have start state to reset to and done state for when instruction finishes

Need to represent each instruction, each register 

Also need to control the bus and multiplexer

Could have stream of states for each instruction that goes through the necessary process




## Plan

Two components:
- architecture
- state machine design 

### Architecture



## Build

<<<<<<< HEAD
Get working with mvi first to make sure can do the most basic instruction and the rest of the data path works 

Assuming needs to be a single clock pulse before an instruction is executed to latch IR
=======
writing bits and pieces using generics and connecting them with signals should not be too difficult



>>>>>>> main

