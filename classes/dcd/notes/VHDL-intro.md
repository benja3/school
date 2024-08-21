# Intro to VDHL

Test Covers all slides so far

Chapter 7 in book

Review material for question and answer section and quiz

## Why use VHDL

quick time to market

allows designers to quickly develop large projects

provides high level constructs for complex logic

supports modular design methodology

testbench: self contained program that sets up chip and captures I/O for verification
- VHDL code to test other VHDL

## VDHL

Used as input to synthesis and simulation

case insensitive

Can be used to work at all levels of abstractions

### Design entity

describe function information such as input, output, etc.

Declaration: like prototype, specifies the ports and name of the component

### Architecture

implementation of entity 

can have multiple architectues/implementations for an entity 

inputs and outputs called ports 

a signal looks like a variable but represents a wire connection 

## Example

types are usually std_logic

port modes indicate direction of data transfer
- IN, OUT, INOUT, BUFFER

buffer allows for implementation of tri state

## Architecture Body

look similar to standard programming langugaes

testbench: instantiates and connects all components and simulates behavior 

## Behavioral Architecture

### process statement 

can be used to implement nearly everything in HDL

ususally small and implement components like counters and registers

process statements run independently of each other

can be thought of as threads running in the simulation

execute based on sensitivity list, which are arguments of the process

the process will be idle until something in the sensitivity list changes

can add extra details to statements such as delays 

assignment operator: <=

### dataflow

evaluate expression every time an input changes

similar funcitonality to processes but contain less complexity 

## Modeling Structural Architecture 

defines entity using components 

internal signals connect components 

can declare port maps with inputs and outputs 

similar to netlist 

different compoents like gates build into HDL

## Types

VHDL has built in types, and can also import types from libraries 

bit: can be one or 0

bit vector: array of bits

can specify ranges with TO or DOWNTO to specify the significance of the bits in the vector

## IEEE 1164

STD_LOGIC has 9 possible values instead of just 2 (1,0), includeing Z, U, etc.

must include the library at the top

## Literals

see slides for details

use # to specify base of a number

can combine multiple literals 

### bits

can specify hex, binary, etc. from strings

## Declarations

CONSTANT bus_width : INTEGER := 32

use constants for details like register and bus size, delays

if delay not specified, assume no delay simulated

VARIABLE means just a general variable like int

use variables for measurements not part of the actual design

SIGNAL specifies the connection between two components

Can create FOR loops in HDL

variables can be declared in loop headers 

a declaration is like a class

## Component Instantiation

instantiation creates an object of the type declaration

instatiate: ```reg5 : fill reg``` where reg5 is the name of the ibstance and fill_reg is the component declration 

multiple ways to instantiate; use the more verbose method (named)

### Boolean Operators

VHDL has built in support for AND, OR, NOT, NAND, NOR, XOR, XNOR

assignment operator: ```<=```

VHDL does not use precedence, so use parentheses
- exception: NOT will bind to the var it is infront of

not equal to: ```/=```

for bit vectors, comparisons will happen on a per index basis 

### Native Operators

string concatenation: ```&```

### Overloaded Operators

overloading: can have multiple functions of the same name and distinguish with arguments

## Thoughts

VHDL code does not execute sequentially like C code, the code that makes up all the components is active all the time

Code segments are activated as events happen

The code that is checking for events is always running

Goal is usually to create a single piece of code that can be both simulated and synthesized to hardware

Do not hack with VHDL. Do not sit down and just start coding like you might do in Python or another high level language. Always plan and make sure you understand what you are building before you start implementing it.

## Design Style

### Combinational Design Entities

Use ONLY:

Concurrent assignment statement: boolean statement, each of which is like an event handler that recomputes the state 
- combinational only

Case Statements: mostly useful in state machines where each case is a state ***

if statements: if can be used as a logical statement
- must also include else for all ifs 

instantiation of other combinational modules 

### Sequential

Use ONLY

combinational logic

explicitly declared registers

connect combination logic to registers

### Do not use

loops

processes: 
- define external code that is run when called
- can be dangerous because there are no limits to what code can be included in a process and can make the design not synthesizable 
- can get stuck in infinite waits 

There are bad VHDL code examples online so don't copy them

### Do use

signal slices to only use certain bits of a vector: ```4 downto 1```

Organize code into small design entities that serve as building blocks (just like any other design)

### Comment

write comments themselves

learn to comment while coding

write appropriate comments that provide useful information

comments should summarize design choices

Use meaningful names to make code self documenting

shift thinking away from class projects and towards work place production code 

Commenting should be a habit

### Constants

Like in regular programming, use constants to make code more readable and prevent from having to change lots of numbers

### Signals

Use busses (multi bit signals) as much as possible

### Draw

Draw a visual of what you are trying to design before you start implementing it with VHDL

## Architecture Body

### Concurrent Assignment Statement

```a <= b + C```

activated when any associated signals change their value

independent from other statements in the architecture

### Component Instantiations

breaks down complex system into blocks

### Processes With Behavioral Descriptions

## Other Assignment Statements

order of concurrent assignment statements does not affect meaning of code
- since they execute at the same time, initial values always used

## VHDL Process

processes either asleep or active

d <= a + c  is the same as:

foo : process(a,r)
begin
    d <= a + c
end process foo;

(a,r) is the sensitivity list and the process will be executed when one changes 

if one variable is a constant, do not include in sensitivity list

if no sensitivity list, process executes continuously
- this is ok if the process contains a wait statement
- not a good practice 

Multiple processes can execute concurrently, but statements in a process execute sequentially

Updates happen at the end of the process

## Variables

variables assignment is not concurrent

can only be used inside a given process

cannot be used for interprocess communication

use := for immediate assignment

the <= operator schedules for update instead of performing immediately

## Concurrency

means not procedural

execute at the same time 

order has nothing to do with execution order 

any back to back assignments in a unit such as an architecture or a process occur concurrently 

Concurrency is fundamental to hardware since signals are transmitted at the same time

to design, think about how the hardware will be synthesized and what will happen when

## 2 Designs example

the example with hardware concurrency (multiple gates performing operations in parallel) is faster becaues the change has to propagate through less gates

## Combinational and Concurrency

combinational logic can involve both concurrent and sequential statements

## Selective Signal Assignment

assignment based on signal selection

like an if statement for assignment

use ```WHEN``` keyword

x <= a when 00,
     b when 0 to 3,
     c when 4 | 6,
     ...
     z when others

cannot leave out an option, use an else / "when others" to avoid issues 

## Conditional Signal Assignment

assign a value based on conditions

signal_name <= value_1 WHEN condition1 ELSE value_2

conditions are combinational logic

else statement at the end called the "catch all"

conditions do not have to be mutually exclusive

Processes are concurrent with each other

typical synchronous circuits are only sensitive to the clock

A flip flop is a synchronous latch

It is easy to accidentally create latches if code is not modularized

## Case Statements

like a switch statement in VHDL

CASE s IS
    WHEN "00" => x <= a

can use string formats in VHDL: 4d -> 4 bit decimal

"-" in a binary string means do not care

use m downto n instead of n to m

## Comparator architeture 

want to write an architecture that sets a_eq_b when a = b

conncurrent with condition: a_eq_b <= 1 when a = b else 0;

many ways to do this: use conditions instead of direct logic

Match the problem to the appropriate implementation style to keep things simple

'x' is format for hex

## Test Bench Style

process without sensitvitiy list

entity is empty

uses looping constructs and wait statements

style of test bench should not be replicated in synthesizable code

### Example

everything labeled test

signal declarations happen above ```begin``` statement

must instantiate module to test 

DUT: entity work.prime

DUT is label for entity prime from previous slide

port map also declared

for loop loops through 0 - 15 to simulate all 4 bit inputs

uses report to print output information (with & to concat)

work keyword is a package name, will discuss packages later, but they are just groups of entities 

to assert in your test bench, check outputs to expected and halt the simulation if anyting goes wrong

## Clock Example

process that has no sensitivity list (runs constantly) and inverts the value of the clock signal after time

VHDL print different from printf: can concatenate strings instead of using formats

port maps can be in any order 

## Summary

Do not try to do logic design yourself. VHDL is powerful and can reduce complex logic automatically, so there is no need to hand work the logic

Synthesis tools will automatically optimize

VHDL encourages small functional blocks of code to be interconnected

make models generic such that they can be easily tuned and configured

make a comment header to describe what each module in your code does

## Aggregates

collections of items that are gathered together 

can declare or specify mulitple things at once, such as setting multiple bits of a signal based on different patterns

allows for one line of code to do a lot of different things

use: control bus where each line enables a component

## Generics

can be used to parameterize code by making components modular

can have parameters like bus WIDTH, and pass that value in on compile and the code will adapt to the new value

feed in constant to alter the structure of the designed hardware

example: register of SIZE flip flops

## Generate Statement

structural code involves creating instances of components

processes create behavioral codes

like a for loop but for generating multiple components

use: 64 bit ripple carry adder, do not want to individually instantiate 64 adders

generate can do most of the work but some times there are parts on the edges that do not follow the same patter as specified in the generate statement, and those must be coded manually




































