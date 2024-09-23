# Lab 1 Design Process

## Overview

Writing two images to the display of a lab computer. One is grey scale and the other is RGB. 

Must make this work with both the X window system in Linux and whatever Windows uses

Provided with images and skeleton code for display servers

Must be able to select image without recompiling (command line args)

Linux:
- greyscale image
- rgb image

Windows:
- greyscale image with 8 bit color map
- rgb image

### Questions

Should the 8 bit entries in ```dispdata``` be color map entries or the 16 bit RGB Data?

We do not need to worry about rows and column parsing right? All data is 1D? 



## Research

Greyscale PPMs contain 1 byte per pixel, RGB PPMs contain 3 bytes per pixel. To translate into 16 bit RGB, use the greyscale value for the display RGB. For the RGB PPM, use the most significant bits of the different colors for display data.

### X Functions

see x.org for man pages

XOpenDisplay: https://www.x.org/releases/X11R7.5/doc/man/man3/XOpenDisplay.3.html



## Plan

Have two separate programs (one for linux and windows) that call library functions for data conversion 

Create Library with important conversion functions called libimgwindow

Use uint<n>_t for 8 to 16 bit conversion

Try to make as much code reusable as possible. There are lots of similar operations that will be done here. Remember, functions should do one thing, and serve as building blocks.

## Library Functionality

### Metadata

read image metadata (code for this on canvas)

### File to Display Data Conversion 

convert 8 bit greyscale to 16 bit RGB for linux 

convert 24 bit RGB to 16 bit RGB for Linux and Windows

Will need other functions to loop n times and perform conversions

### Color map










### Library Functions

Will only call the highest level functions in the window manager code. The majority of the functions in the library will be private. 

imgwin_read_metadata: return struct with metadata










## Build

## Test