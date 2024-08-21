# DCD Introduction 

Lab door code: 327468

## Traditional Digital Design

Going back to 80s and 90s

### Schematic Entry

Drawing or diagram that represents a circuit or other system

### Low Level Primitive

object implemented by the CAD tool

example: AND / OR gate

Similar to programming languages having libraries of functions 

Does not work well with bigger systems because they get over complicated

No abstraction 

## Bottom Up Design

Can design modules out of primitives and use these as building blocks 

primitives include gates, flip flops, registers, etc.

Can use the modules created to build more complex systems 

## Top Down Design 

Handles design complexity much more effectively

Allows for more effective planning 

decompose system into submodules 

Important for collaborative work 

### Benefits 

Shorter development cycle 

Flexibility:
- can change implementation on the fly by editing sub modules 

## Hardware Design Language 

### synthesis 

use a hardware compiler to turn hardware code into actual hardware

compilation results in a physical object 

CPLD: complex programmable logic device 

Hardware implementation (ASIC vs FPGA) depends on usage environment and numbers that will be produced 

## Design Cycle 

This class covers
- Specifications
- Design with CAD
- Simulation
- Prototype 

### Requirements 

First part of the cycle involves client writing document specifiying what they need from the digital system 

Written in english in paragraph form, not flowcharts or psuedocode or anything like that 
- English is not precise, so must be interpreted into more specific form 

Most important part of project is translating requirements to specification

### Specifications 

Similar to requirements, but contain a more technical description

Engineers will build based on specs, so if information is lost in translation from requirements to specification, the customer will not be satisfied 

### Design

Come up with a solution to the problem 

System is ususally much more complex than specifcations can capture 

Use CAD to design the hardware solution itself 

### Simulation

If software, just run the software

Some things cannot be tested in the physical environment, so much adjust and use simulation

Prototyping can be expensive, so simulation can save lots of time and money if multiple iterations are needed

If simulation results not satisfactory, go back to design and make adjustments 

### Documentation

Set of informative documents that describe the finished product 

Capture specs, design details, and how to use the product 

## Electronics Design Automation Tools

EDA system includes
- design entry
- synthesis and optimization
- simulation
- physical design 

Net List: machine code for hardware, list of connections between gates, created by synthesis 

Flattening: process of taking the module heirarchy and turning it into a one dimensional layer of just gates 

Functional simulation: how does the chip behave

### Place and Route

Physical details of hardware, technology used, where things go on the board

Place: physical layout

Route: details on how signals propagate through the chip

Longer wires have more resistance and capacitance; alters behavior of the wire; must be considered when deciding the physical layout 

Still happens in simulation environment 

FPGA's contain a grid where different components will be put, nitty gritty done behind the scenes 

### Part Library

Logging of primitive components and libraries being used 

logical description: how it works

physical description: details on location, power, etc 

## Design Entry 

process of entering a description into the CAD system

Methods of entry:
- truth tables, waveforms (timing diagrams), state diagrams 
- schematic: graphical
- HDL: programming implementation of logic circuit 

### Schematic 

Create library of graphical tools and drag and drop connections and parts 

netlist: pin to pin connections 
- unique tag for each part

Not typically used anymore 

Does not grant acces to power of programming logic like loops to create many components of certain nature 

## Hardware Design Language 

Common:
- VHDL
- Verilog 

HDLs provide:
- a textual definition of a netlist 
- user defined primitives 
- high level functional models 
- mixed level simulation 

High-Level Functionality Model: can create software black boxes for testing purposes so all the details of the hardware does not need to be simulated 

HDL supports hierarchical design 

### Behavioral models

Behavioral models: subsystems that describe behavior without knowing implementation
- can connect these with other models to assume the system functions as intended 

Many ways to implement the behavioral models

Can use a synthesizer to automatically implement the described behaviors 

Some things cannot be synthesized and the HDL code will not work 

## Schematic vs HDL

The C preprocessor can be thought of as a metalanguage on top of C

## Synthesis 

Synthesis CAD Tools generate logic circuit from stated behavior 

Can also optimize the circuit as it is synthesized 

## Netlist Output 

EDIF: attempt at standardizing netlist forms

## Simulation 

### functional

user specifies inputs and outputs and the tests are run and evaluated 

the simulator provides model of the primitives and the engine will simulate the interaction and create the output 

In hardware, logic correctness is not enough. The propagation time for the signals to pass through the chip must also be suitable for the chip to work properly.

When simulating, mainly checking for logic correctness (zero delay)

To test timing, use a timing simulator 

Must determine the physical location of all the components before running the timing simulation 

input waves called stimulus 

device models consist of primitive logic functions and timing information 

Timing simulation options are rise, fall times during best, worst and typical conditions 

setup time: amount of time for input to be stable before the clock changes 

hold time: time after clock where input must be stable 

pulse width: time a signal must be in a certain state before it changes 

Typically use Spice to see thigns like curves in signals that are not digital 

## Simulation Styles

### Electrical 

measures the voltages and currents in the circuit

Example: SPICE 

simulations are time driven, measure the information over time

primitives: resistors, capacitros, transistors, etc. 

much more time consuming due to large simulation overhead

### Logical 

event driven: calculations happens as each event happens, not continuously throughout time 

HDLs

only collect data at interesting times 

uses table to track the logic state of the machine 

HDLs are designed to be event triggered rather than conditional (event based language from 3520)

Race conditions: when two or more signals change at the same time
- causes issues in zero delay simulations 

Hazard condition: momentary value that is opposite to what is expected 


## Basic Logic Values

0, 1, U, Z

### U: unknown state
occurs when signal is not initialized and the output cannot be determined 

prevent with reset that forces the component to become 0

### Z: high impedance 

literally an open circuit such that the output is disconnected from the rest of the component 

application: disconnect write register from the bus while a read is occuring to prevent interference 

## Hybrid Simulation 

combines attributes of both electrical and logical simulation 

## TSB and TG

### TSB: Tri state buffer

has three pins, input output and enable 

if enable, is 0, open switch and disconnect ouptut 

Can charge a node and start striving it

allows to break physical connection between device and whatever it is connected to 

schematic: triangle with input, output and enable 


### TG ***

hard to simulate

two transitors connected such that inputs and outputs are connected 

TG is bi-directional, unlike TSB

allows for the connection of two signals 

### Charge Sharing

have a switch on either side of a cap connected to ground, and when one switch is open, the cap charges and when the other switch is open, the cap will discharge 

If multiple caps used, the voltage across all caps will be Vs / n_caps 

Caps not included in chip level design 

Everywhere in a chip, when a wire is added, it creates a capacitance 

## Advanced Logic Simulators

can operate at gate or switch level, and can therefore simulate both electrical and logical 

### switch level

models transistors as switches that could be on or off 

Still must calculate delay for signal propagation 

Does not consider analog curves involved which CMOS 

### gate level

logic elements are modeled by functions 

Propagation delay is the time it takes for the curve to stabilize at the opposite logical voltage 

Must consider electrical details to calculate this delay 

## Flip Flops 

Behavior can be described in different ways 
- primitive
- no delay
- HDL 

### Timing 

Must consider:
- rise and fall delay of output after the clock pulses 
- set up and hold time (time required for I/O change before/after clock pulse)

See slide for flip flop timing diagram 

When there is a line on both high and low in a diagram, it could be either 
- if there is a single line, must hold line stable 

Simulators will print error messages based on the timing diagram 

## Input Routing 

A level closer to the physical chip

Involves physically where components will go on a chip 

Chip typically looks like a square grid with I/O pins on the outside and gates / other components fill the inside grid spaces

Must find a way for wires to be routing through the grid 

Can only be so many wires in a single channel 

Some configurations cannot be completed due to lack of space 

To do this, need to know:
- dimensions
- electrical characteristics (capacitances)
- signal names
- special flags

Must have netlist from the schematic capture 

Pins are not necessarily physical pins, but the place where input / output signals are connected to 

Functions define how fast signals can propagate through each gate 


## Routing Parameters 

### Dimensions of layout space 

Typically want square but rectangular not unheard of 

### placement of connectors and parts

Gates have a certain pin structure of input, ouptut, power and ground

Can use tricks such as overlapping power and ground rails to prevent wire connection 

gates typically have rails that stick out of both sides to maximize connection options 

### Routing Layers

can have different layers of logic on top of each other 

### Floor planning

designate area for specific components to go 

allows for some human input in the place and route process

Can keep all components in something like a register in a static arrangement 

Traditional organized by gate, floor planning organizes by structure 

### Electrical characeristics 

prevent resistances and capacitances from leaving value ranges 

## Back Annotation 

Add up length of wires and I/O of devices to calculate the intrinsic capacitances 

Can use this to estimate the delay

Higher capacitance prevents states from changing as quickly 

Results can lead to re-design if necessary 

## Moores Law

Since 2005, voltages in chips have remained constant due to power limitations 

Power optimization is tricky, too much power and the chip will burn up, so must use more efficient cooling 

Currently, instead of making CPUs faster, people are just using more and more CPUs













































