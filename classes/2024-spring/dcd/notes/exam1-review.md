# Exam 1 Review

## In Class

Exam will be mulitple choice, true false and matching

Multivalue logic: simulation that provides values other than 0 and 1

Z+ and Z- are an attempt to state that the input gate is not driving the output, but is close to a 0 or 1

weak and strong 1's and 0's allow for modelling charge transfer from small to large conductors

a tri state buffer is just a gate with a switch that can put it in Z

When writing VHDL, start with design drawing
- the system drawn will be an entity that has I/O ports
- must determine if ports will be external or internal

to test, must create and instantiate it in a test bench

next, declare architecture based on the entity that contains processes that control the state of the device
- processes contain assignments of signals and ports

a combinational block is a piece that fits inside an architecture

3 types of code in archtectural
- behavioral
- data flow (boolean equation)
- structural
- these are just different styles of programming VHDL

generally not work putting small ocmpooents like couunters in the entity

a test bench is another entity that instantiates the system has code in its architecture to test it

test bench entity typically empty

logcial simulation is 0/1, electrical measures voltages and currents

since electrical simulaiton is much more computlationally intsnse, only do when necessary in certain parts of the system

switch level is between electrical and logical: *** review

rise time vs fall time: consider the time it takes for the signal to change instead of assuming it is instant

strucutral modelin: schematic capture in text

hierarchical: modules and sub modules

IN, OUT, INOUT and BUFFER are directives that assign data flow on ports 

signals connect components, variables are just for local storage and data management
- example: i in the for loop is a variable, and the itnernal bus is a signal
- try to use variables sparingly

concurrent assignment: <= 

flip flop implementation: on the rising edge of the clock, set the output to the input

a register is just mulitple flip flops in parallel
- also have enable, shift right, etc. to add more functionality


## CAD Workflow

### Design Entry

Schematic capture: drag and drop low level primitives onto a canvas to design chip
- does not work well with bigger systems because abstraction capabilities are limited

Bottom up design: create simple components such as registers or counters and use heirarchical design with moduels and submodules to create the final product

Top Down: plan out device at a high level and consider implementation details of increasingly low level compoents
- used due to complexity of large designs
- can use libraries to abstract certain low level things
- shorter development cycle

Hardware Design Language: programming language that can be used to model hardware
- synthesis: use a hardware compiler to implement a design

Design Cycle: Specs -> Design with CAD -> Simulation -> Prototype

Design Entry and Simulation: Specs -> Entry -> Synthesis -> Net List -> Functional Simulation -> Place and Route -> Timing Simulation -> Production Drawings

Common design entry methods:
- truth tables, waveforms and state diagrams
- schematic capture
- HDL: programming lanaguage like description of the logic cirucit

Design with truth tables: user enters the truth tables and timing diagrams and CAD will synthesize based on that

Schematic capture tools provide a collection of symbols called libraries; use graphical symbols
-  also known as heirarchical designs

### Device Library 

Part Library contains essential details such as component specs, function, delays, layout, pins and electrical characteristics of different components

## HDLs 

Hardware DESCRIPTION Language

Common HDLs: VHDL, Verilog

VHDL and Verilog are standards

EDIF: Electronics Design Interchange format was an early attempt at standardizing HDLs 

Behavioral modelling: 
- involves describing the behavior, not the specific implementation
- supports top down design 
- can do mixed mode simulation (incorporates both electrical and logical components)
- some designs can be synthesized from programming logic

Structural model:
- use textual netlists
- involves use of more specific, lower level description of design

netlist: data structure that contains information on components and their connections to each other

HDLs are advantagous over Schematic Capture because they are:
- portable
- functionality focussed (do not need to know alot of specific physical details)
- text based
- modular

### Synthesis

generate a logic circuit from higher level functional behavior (derived from VHDL code)

involves translating VHDL code into network of logic gates

synthesizer can also optimize a circuit in both size and speed

### Simulation

Functional:
- user specifies circuit inputs and the CAD tool generates output
- assumes that signal propagation time is negligible

Timing simulation: models the time it takes for a signal to adjust from 0 to 1








