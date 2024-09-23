# Exam 2 Review

## In Class

PLD: programmable logic device
- covers all devices

PLA: Programmable Logic Array
- fuses select inputs

PAL: eliminates inputs by making the inputs to AND gates never be 1

ROM: implemented with decoders that takes in address lines and selects requested cells

CPLD: contains cells with routing channels between them such that logic can be programmed into the cells and connected to each other in arbitrary ways
- predecessor to FPGA 
- FPGA blocks are smaller 

FGPA:
- has certain areas for special functions like multiplication and storage

Decoders made with AND gates

## Switch Logic

Series and parallel combinations of switches can be combined to make logic functions

need both positive and negative switches

## Mos Transistor

Both C and W / L is important to performance

C is the parasitic capacitance that builds up and resists voltage changes  

### Width

represents the width of the source and drain 

### Length

represents the distance between the source and the drain

affects the speed of the devices because the time it takes for the signal to propagate through the gate affects return times

### NMOS

when gate is 0, no voltage to create the channel and the source and drain remain isolates

when gate is 1, the channel opens and current flows between source and drain

can only reliably pass logic 0

### PMOS

same affects as NMOS but 1 and 0 reversed

can only reliably pass logic 1

### Electric model

see slides for VI plots

### CMOS

Must be driven by supply voltage

contains both positive and negative logic that must be the inverse of each other 
- any time the positive is high, the negative must be low and vice versa

can only generate inverting logic with a single CMOS gate

SKILL: be able to analyze CMOS gates
- review inverter, NOR, etc.

### Tri State

see slide 19 for diagram

input drives the output only then the enable is true

when enable is false, output is Z not 0

any CMOS gate can be modified to be tri state

### Bad Circuits

SKILL: learn to analyze and detect bad inputs

## Delay and Power of CMOS

### Parasitic Capacitance

Transition times: rise time and fall time

Parasisitic capacitance can be modelled with a capacitor connected to ground in between two gates

Propagation delay: how long after the input changes does the output change
- time for a signal to travel through the circuit from input to output
- caused by parasitic capacitance resisting the voltage change

### Fan In/Out

Fan in: number of inputs to a logic gate
- depends on how the gate is constructed

fan out: number of inputs a gate can drive without performance degradation

The more gates that are connected to an output, the more C builds up

see plot on slide 26 for plot of voltages with different fan outs

### Driving Large Loads with high fan out

typically 4x fanout = 4x delay

for very large fanout, increase in stages

such that 1 -> 4 -> 16 -> 64 and each gate has a fanout of 4

### High fan in

series: increases output resistance and capacitance leading to larger propagation delay

see slide 28 for example

parallel: increases load capacitance at gate output

### Logical Effort

CONFUSING: logical effort: increase in input capacticane for same output drive 
- how much "effort" different gates need to perform the same task

see 29,30 for formula

### Circuit Delay

CONFUSING EXAMPLE 

### Wire Delay

large fraction of delay and power consumed by wires connecting gates

### Dynamic Power

P = 0.5 * C * V^2 * f * \alpha 

alpha is activity factor

to reduce power, reduce V, C and alpha

reducing voltage causes the power to reduce quadratically but circuit also operates slower, so V and f typically are reduced together

reduce capacitance by making circuits as small as possible to minimze the wire length

reduce activity factor by eliminating unnecessary transitions that consume power

### Static Power

also called leakage power

power dissipated when the device is not doing any computation 

comes from current leakage through transistors

to reduce, use transistors with higher threshold voltage and turn off certain parts of the chip that are idle in some cases

### Power Scaling

both capacitance and energy consumed scales with L

however, the power density increases when L is reduced because there are more power consuming transistors per unit area

1/2 L -> 2E

therefore use parallelism instead of fast cores

## Combinational Logic

Building blocks:
- decoder
- encoder
- multiplexer
- arbiter (pick first of N)
- comparator
- read only memory

large decoders made by combining small decoders 

## Programmable Logic Devices

### PLA 

programmable logic array

contains n input buffers / inverter pairs, an AND gate plane, an OR gate plane and m output buffers and inverters

see slide 23 for diagram

inputs to all gates have fuses to program the device

### Programmable Array Logic

PAL

contain input/inverter pairs

programmable connections to the and gates

fixed or plane that cannot be programmed

output latches / flip flops

both PLA and PAL can have inverters at teh output or latches to store the otuput

PLA
- AND and OR structures that are each programmable
- More flexible becuase only AND is programmable in PAL

### Complex Programmable Logic Device

Multiple PAL or PLA blocks per chip

good for more complex circuits

PAL like blocks connected by interconnect channels

### Field Programmable Gate Array

contain logic blocks to store user programmed circuits

IO blocks contain pins that interface with other devices

interconnect switches programmed to connect logic blocks to each other and to IO blocks

### Application Specific Integrated Circuit

not reprogrammable

contain standard cells that implement a sea of gates

good for large scale applications 

### FPGA vs PLD

FPGAs are internally more flexible than PLDs. PLDs have fixed internal structures, while FPGAs are capable of routing and programming all parts. 

FGPAs sometimes have I/O issues related to number of output pins

PLDs used for smaller tasks that fit in single logic block

FGPA used for larger circuits that span multiple blocks

FGPA requries CAD

ASICs require a mangufacturing process to create, but can be made in bulk after that
- Expensive to design, but cheap to produce

FGPA cheaper in smaller quantities and allow for development 

## Intel/Altera Cyclone

### Features

read slides

2D row/col based architecture to implement custom logic

interconencts have varying speeds between different logic blocks

contains dedicated memory and multipler blocks

### Logic Element

4 input lookup table that can implement any function of 4 variables

look up tables cover all values in the variable space and define a value, thus implementing the function. If the inputs are known, the output is known.

see 4.26 for picture

## Sequential Logic

output is a function of both the input and stored values

State machines

sequential circuits involve both combination and sequential parts

### Moore

Inputs must go through flip flops before reaching the output. Output only ocnnected to the sequential component

### Mealy

output connected to combinational parts and can change immediately (not just on clokc pulse)

sometimes need less states

## State Machine Design Process

### Formulate State Diagram

Decide number of states that are needed and the transitions

include start state for power up and resets

### Translate to State Table

### Make State Assignments

### Choose Flip Flops 

### Implement

## Delays

Propagation delay: time from last input change to last output 

contamination delay: time from first input change to first output change 

minimum delay: time from input change to output having stable correct value

overall contamination delay is the minimum across all paths 

overall propagation delay is max across all paths
































