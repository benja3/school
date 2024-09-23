# Lab2

## Overview

### Questions

How to implement clock

### Instructions:

Direction sensor, I. A direction sensor is used to detect the direction of a rotating gear. An input pulses each time a gear tooth is over the left side or right side of the sensor. This machine has two inputs, il and ir, and two outputs, ol and or. The FSM should output a one- cycle pulse on ol any time a high level on il for one or more cycles is followed, after zero or more cycles, by a high level on ir for zero or more cycles. Similarly, a one-cycle pulse on or is output if a high level on ir is followed by a high level on il. Wehave provided an example waveform in Figure 14.21. Draw the state diagram and table.

Two inputs, and two outputs. 

## Build

Use the good practices from the slides to make the VHDL state machine without having to do complex logic 

First, create an entity with the inputs and outputs of the state machine

In the architecture, declare the different states as contants 

declare registers to represent the different states, and connect them with signals 

implement the logic that decides the next state with a process 

use an output statement at the end to display the result of the next state function

