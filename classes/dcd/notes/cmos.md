# CMOS

## Example 

State machines have rules that decide what state an input will trigger

one hot encoding: take an n bit word and assign each bit to be a state; only one bit will be on at a time
- do this to change the way the synthesizer handles the logic and can make things more efficient at the hardware level
- not always optimal if the state machine has lots of possible states

in this state machine, include a process to set the next state of the machine after each operation

VHDL will pick don't care by default if states not specified, but this could break the system so always specify 

on clock edge, copy the next state to state

combinational logic typically does not have clock in sensitivity list

## General

Complementary Metal Oxide Semiconductor

## Structure

metal (aluminum) sits on top of an insulator (SiO2 (silicon dioxide)) that sits on top of the silicon wafer 

prior to CMOS, size of transistor had to increase if it needed to handle more current; with CMOS, the size does not matter with respect ot current because current only flows on state change


## Switch Logic

allows for imitation of gates with swithces

Need both positive and negative switche to create all logic functions
- use both active high and active low transistors 

can have multiple switch networks that represent the same function

## MOS Transistor

source and drain are indentical terminals that are embedded in the silicon wafer; achieved by doping parts of the wafer

voltage on the gate controls current flowing between source and drain; voltage creates channel between source and drain 

NPN requires positive voltage to conduct, PNP requires 0 voltage to conduct 

swithces are not perfect and some voltage that is passed through them is lost, but digital systems restore the signal so this does not cause issues

Width (W) of channel: increasing width allows more current to flow because the channel can fit more electrons
- width larger W the device is faster because it can charge / discharge the load capacitance faster but the overall gate capacitance increases 

Length (L): how far the electroncs have to go to get throguh the channel
- determines speed of the device 
- when you see nm specification in CMOS technology, refers to the length of the channel

## Transistor Sizing

reduce delay by increasing W:L ratio

## Electrical Model

model as resistance in series with source and drain; value based on L and W

Current gets higher in NMOS than PMOS; this is why NMOS is not used 

VIL and VIH determined by when the output voltage is changing at a rate that the derivative is +/- 1 

## CMOS Gates

any CMOS gate can be modelled as a set of P and N type transistors; inputs and output connected to both; for output to be true, input must pull output to the value of the supply; for false, N type must connect output to ground

networks must be complements of each other

this is called inverting logic 

in steady state, the gates have no current flowing and therefore no power

### CMOS inverter

### CMOS NAND

CMOS gates involve one structure at the bottom and the complement of that structure at the top

For NAND, there is a NAND gate at the bottom and an OR gate with inverted inputs on top, which is the complement of NAND by demorgans law

### AND-OR-Invert

implement the original logic expression, then use demorgans law to complement the original expression and design that with transistors to complete the CMOS

Advantage of making complex CMOS gates is that it uses less transistors than all the individual gates combined

increased speed, reduced power, smaller area and lower fabrication cost

take equation, implement with logic, and then apply demorgans law to the equation and implemnt that

## Tri State Circuits

add extra transistors connected to the enable that will be off / on in the appropriate situation to drive or disconnect the rest of the circuit 

## Circuits to Avoid

make sure that the p type logic and n type is in the right place or the circuit will not work correctly

the p type logic cannot be connected to ground and the n type logic cannot be connected to the power supply

## Delay and Power

parasitic capacitance exists between two gates

transition time: time for capacitor to charge and deplete are called rise and fall time 

propagation delay: way of estimating the time it takes for a signal to traverse a long arbitrary path in a circuit 
- time between VDD reaching 50% on input and output
- time due to the parasitic capacitance causing the voltage to resist changing 

## Fan In/Out

Fan in is the number of inputs to a gate
- can have an arbitrary number of inputs to something like an AND or OR gate
- the parasitic capacitance of a gate increases as the input does due to incrases transistor count

fan out is the number of connections to the output of a gate
- limit typcially 4-5 connections to not build up capacitance 

### driving large loads

increase the fanout in stages: 1 -> 4 -> 16 -> 64 -> 256 ...

if the pad being driven is too large compared to the transistor, then the transitor won't be able to change its voltage quick enough 

if not enough fan out, the voltage of the large device being charged will sit in the grey zone between 1 and 0 for too long

a similar phenomenon occurs when a single gate is driving a large number of gates, as opposed to a large unit

### high fan in 

each transistor in the gate has a parasitic capacitance and it stacks on all the capacitors

larger propagation delay

can use wells to isolate certain components and make circuit design much easier because less electronic influence

means gate has too many inputs and capacitance stacks too high

with low fan in, resistance and capacitance are negligible

all the input capacitance goes to the output and slows down the gate

### logical effort

logical effort is the increase in input capacitance for the same output drive

see equations

equations based on constants from table with capacitance values of NAND and NOR gates with different fan in values

### circuit delay

designers just care about delay

fan in is input count

fan out is output count

to compute max delay of circuit with fan in, determine the longest critical path

the overall delay depends on the longest path 

the delay is not always obvious, and just because a path has more gates does not mean it will have more delay

### wire delay

large portion of power and delay is due to wires connecting gates

long wires have significant resistance and parallel capacitance

## Power Dissipation

most energy dissipation occurs when charging and discharging output load (changing from 1 to 0)

performing logic does not consume much power

In CMOS, power only conusmed when switchign 

no current means no power

energy consumption dominated by largest gate in the paths

### Reduce V

power reduces quadratically but circuit also operates slower at lower voltage

typically reduce V and f together

### Reduce C

make circuit as compact as possible to reduce wire length

### Reduce activity factor

how often gates are switching 

eliminate glitches and hazards

HDL design optimization

can disable the clock to certain areas of the chip to save power; only power the parts of the processor that are being used 

### Static Power

leakage current that flows when the transitor is off increases exponentially as the threshold voltage decreses 

### Power Scaling 

CMOS capacitance scales with L (length of the channel)

If you are interested in more of this, read the book!!!

at a point where electrical capabilies are maxed out and must rely on parallelism to get speedup

## MOS Transistor Review

source and drain created by exposing regions of chip to a gas that contains the doping element; the longer the exposure, the deeper the molecules go 

gate structure grown on top of region between source and drain

## transistor sizing

speed of a circuit depends on value of C (capacitance) and the W/L ratio

reduce delay by decreasing cpacitance or increasing W:L

small transistor
- more resistance to electrons because less space for them to flow through

large transistor:
- takes more space
- less resistance because width is larger



































