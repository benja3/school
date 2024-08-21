# DCD Lab 4

## Overview

### Questions

Purpose of not(loadreg)

recoding

Is the D register even necessary? what is its purpose

### Advice

Do not build anything until you are sure it is right.

Test all the components thoroughly before adding them to the final design. 

### Why 

To further increase my VHDL/Quartus skills, learn about how multipliers work in computers, and boost my grade in DCD. I also need to restore my engineering confidence and get this hard lab to work. It is valuable to get experience working on a project where I need to clarify the instructions, because in the real world, I will not get detailed project documents like in some classes. Need to develop my self accountability. Yes I will pass the class even if I do terrible on this project. No I am not the kind of person to slack off and do a poor quality job. Being able to analyze diagrams and fill in the gaps is an important skill as an engineer. 

### What

Building a bit pair recoded fixed point multiplier with VHDL. It will need to be demonstrated in both testbench and on the board. Top level entity should be structural with component instantiations per the datapath in the instructions. Should be represented by mealy state machine.

### Who

Solo but can work with the people in the lab and ask Steven questions. 

### When

Due Friday April 26th, last day of class. 

### Where

Riggs 309

## Research

### Booth Recoding



## Unabstract

### Register

Two of the registers must be shift regs

Registers C and B hold the product and should be the output

C:
- first bit will be carry
- input: from adder
- output: back to adder

### Adder

needs to handle carry somehow

output will be valid or invalid depending on the last bit of the multiplier

From what I understand, if the last bit is 1, the sum is loaded in to C register. Else, the C register does not change. I do not see why the mux would be necessary when I could just not latch register C. 

### Mux

### Control FSM

perform N cycles for N bit numbers

## Taskify

### Review Material

### Build Datapath Components

Register, Adder, Mux

must be generic 

### State Diagram

### VHDL State Machine

inputs:
- start

### Structural Entity and Datapath Connections

This system is not clock based, but loadreg and shiftreg signals will latch the registers periodically



