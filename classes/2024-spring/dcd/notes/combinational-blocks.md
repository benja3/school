# Comnbinational Building Blocks

buidlilg Blocks:
- decoder
- encoder
- multiplexer
- arbiter
- comparator
- ROM

## One Hot Represetnatio

001 > 00000010

111 > 10000000

can be created with decoders

## Decoder

a circuit that converts binary input to one hot output

the only bit high in the output will be the binary representattion of the input

only one bit will be hot at a time

### Large Decoders

can be made from several small decoders

making big decoders from several smaller ones uses less gates than building the big on the traditional way

also reduces fan in so less parasitic capacitance

### VHDL implementation

```sll``` shift left operator

use ssl to shift the hot bit a certain amount to represent the input 

## Encoders

converts from one hot to binary

will break if the more than one input bit is hot

### Large Encoders

## Arbiter

has n inputs and n outputs

used as part of the interrupt system to decide which of multiple requests should be handled
- generally, the lowest number is picked

inputs represent pending requests and output represents the one currently being serviced

output the first input bit that is high as one hot

see slide for logic implementation

implemenation has chaining affect which takes time for signal to propagate through 
- sometimes this is OK but not always

can turn into a look ahead circuit to prevent chaining 

when designing hardware, use these standard devices and their traditional implementations and use them as components

## ROM

first of programmable devices

n input address lines and m output data lines 

programmable decoder array
- each address is decoded to a unique cell who's addres is output on the data lines

use a tri state buffer or fuse to disconnect all cells that are not selected

programmable roms have a machien that burns out the appropriate fuses to write

can also be done with resetable circuit breaker type components

ROMs essentially decoder technology to select cells based on address

and gate technology

### 2D array implementation

isntead of sending all address lines to decoder, send some lines to decoder and other lines to multiplexer to select rows and columns from 2d array

### Types

Mask programmable: fuses blown during manufacturing and cannot be reset
- good for mass production of simple chips that do not need to be changed and have concrete designs

Programmable (PROM): programmed by a device controlled by the user to blow fuses

Erasable PROM: can be erased after being programmed and be reprogrammed
- usually done with UV light shined through window on top of the chip
- to drive a gate to 1, overdrive with high voltage to manipulate CMOS; to erase with UV, shine light to make the charge disperse

Electricaly Erasable PROM: erased with electric signals instead of UV light
- BIOS settings stored in EEPROM so interfaces with motherboard and persistent

## Programmable Logic Devices

want to create a block of logic with inputs and outputs

### Types

Programmable Logic Array

Programmable Array Logic
- different from PLA

Field Programmable Gate Array (FPGA)

### Programmable Logic Array (PLA)

flexible because includes both AND and OR logic, unlike ROMs which only include 1

for each input, generate an inversion as well

chip contains an AND plane and OR plane

all the and gates have fuses to every input and its inversion

outputs of and gates all connected to or gates with fuses 

the fuses can be blown to program the chip and dtermine what gates connect to what

route signals between layers of gates to achieve 

both AND and OR programmable

### Programmable Array Logic

involves programmable connections to and gate and fixed connections to or layer

simpler than PLA

have output latches 

most widespread programmable logic device for simple tasks

only AND is programmable 

### Complex Programmable Logic Device

multiple PALs and PLAs per chip connected by a bus and routed to I/O

allows for higher level designs than the indivudials

XOR can be used as a controllable inverter with a 0 or 1 on 1 input and the signal on the other

## Field Programmable Logic Array (FPGA)

Each vendor builds into own FGPA

must use specific vendor FPGA and software to program it

want ot have more generics

### Type of logic implementation 

LUT: look up table
- load equation into truth table and use multiplexors to select input that generates output

Multiplexors: switch logic

Array Logic (PAL)

### Programming Styles

either programmable, reprogrammable or partially reprogrammable

### structure

array of logic blocks connected by switch blocks

surrounded on edges by IO blocks 

## Look up table (LUT)

use combinations of multiplexers to select certain lines to be the output 

look up value with certain key by passing it to the multiplexer and the appropriate value will be output by the circuit 

use combinations of multiplexers to reduce parasitic capacitance

### Flip Flop inclusion

can attatch a flip flop to the output of any circuit to latch the output

called registering the output

### Pass transistor switches

essentially transmission gates

## ASICs

not reprogrammable

### Sea of Gates

IC with array of unconnected transistors

manufacturing process involves the connection of transistors to implement a specific design

### FPGA vs ASIC

FPGA better for prototyping other purposes where few units will be created

ASICs more cost effective when large volumes being produced

## Cyclone V

has 110K logic elements

5.6 Mb embedded ram

some components are programmable and others are built in so they do not have to be programmed

Review diagrams for more details

FGPA faster than traditional CPU for specific applications because it does not have to do things like fetch instructions from memory

### Logic Element

a logic element is a 4 input LUT that can implement any function of 4 variables

has a programmable register / flip flop

chain connections: fast interconnects between blocks

types of interconnects:
- local, row, column, register, etc.
- allow for signals to efficiently move to different places on the chip

register packing: combining a register in teh combinational design
- saves time and space because can fit both logic and register in 1 cell
- signals do not have to travel across the chip to access the register

register feedback: flip flop output can feed back into the LUT

see diagram in slides















