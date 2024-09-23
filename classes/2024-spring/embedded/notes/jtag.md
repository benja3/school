# JTAG and Chip Debugging

Chips that support JTAG have special pins that can be used to debug

wafers are circular because it is the least likely to warp

can see inside a chip with xray to see if traces are broken

all wafers get high res xrays coming off the assmbley line to check for errors

## Background

JTAG: joint test action group

IEEE 1194.1 Standard

## JTAG Pins

allows for stepping through the clock of the chip like in GDB

TDI: input (serial)
TDO: output 
TCK: clk 
TMS: mode select (on / off)

can connect outputs and inputs to daisy chain JTAG controllers, but they all have to use the same clock

BIST: build in self test
- makes sure that all the hardware is working as expected on boot

