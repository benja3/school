# Documentation

## Overview

Learning to connect I/O devices to the FPGA 

Using switches and push buttons as inputs and a seven segment display as outputs

## Research

## Plan

Represent array of input switches as std_logic_vector

Pin assignments in VHDL entity must have the same name and delclaration as they do in the assignment file

### Part 1

Create a D Flip Flop that latches in the input on the rising or falling edge of the clock

### Part 2

Write a VHDL entity to describe the figure in the instructions which represents an 8 bit wide 2-1 multiplizer with two 8 bit wide input busses x and y, and one 8 bit wide output bus M

write a test bench to simulate this and verify functionality 

### Part 3

Modify design from part 2 such that output M selected from 5 3-bit inputs 

Assuming creating 3 parallel 5 bit multiplexers

*** Confusing instructions 

Simulate with test bench

### Part 4

decoder reads in 3 bits that are used to produce 7 unique outputs on a 7 segment display

codes 000 - 011 have a letter output on the seven segment display and the others are empty

First write a basic entity / architecture to illuminate each segment of the display individually and simulate with test bench and write to board

### Part 5

using the 7 segment display decoder from part 4 to display letters in specific order based on input from 5-3 multiplexer 

see final schematic in document





## Build