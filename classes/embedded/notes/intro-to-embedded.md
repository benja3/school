# Introduction to Embedded Computing 

## Fundamentals 

All embedded devices include processors, memory, bus, I/O just like regular computers

All computations use binary data, fetch/decode/execute and have an instruction set architecture 

Design of an embdded system starts with the data that is being processed 

## Design Axes 

Size

Cost

Processing power
- processor clock speed 
- memory bandwidth 

display power
- frame rate


## Data Type Axis

Consider the hardware and software necessary to handle data such as boolean, text, sound, image/video, etc. 

Dot matrix display: like a 7 segment display but with more pixels, enough to be capable of displaying ASCII

## Data Types

A binary string's meaning depends on our interpretation of it 

### Why use two's complement

Makes addition and subtraction easier

Taking twos complement and adding is cheaper and faster than building a separate subtractor module 

### ASCII vs Unicode

Unicode uses 32 bits and contains all language symbols 

### Image 

visible light meausered over space 

use shutter to modulate light accumulation on a sensor

sensor is a raster grid with pixels 

design choices:
- wavelength frequencies (RGB, greyscale, etc.)
- raster size
- sample rate (for video)
- pixel encoding 

standard frequency in US is 30 Hz, this is enough to trick the eye into thinking that it is seeing continuous 

## Programming

Macro: replaced with something else during preprocessing stage 

When high level programming, clean code and good practices are much more important than on a low level 




