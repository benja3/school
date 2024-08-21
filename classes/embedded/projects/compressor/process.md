# Lab 2 Documentation

## Overview

Writing a program to compress and decompress golfcore.ppm with run length encoding codec

User should be able to select filename, so it should be able to compress or decompress any file

Must work on image, text and binary files

Must implement markers to avoid negative compression

## Research

## Plan

Debug approach: if a complicated file does not work, keep creating test inputs until you have recreated the simplest situation where an error occurs. Then, debug that case and repeat until there are no more errors. 

### Structure

driver.c: 
- will contain main that handles arg passing and file selection
- will call the compressor function

compressor.c:
- will contain functions for compression
- some functions will be building blocks for all compressors and others will be specific

compressor.h:
- header file for compressor library

makefile

### Interface / Implementation

Since doing more codec labs in the future that will have similar formats, create library functions for file handling

The way the labs are structured, the only thing that will be changing is the method of compression used, so can create libraries with compression functions and call those functions in a main driver file

Prompt the user for the image, as well as the compression method to be used (in preparation for future labs)

### Markers

Make marker configuration parameterizeable to tune compression

Must decide when to stop and start doing compression

Design choices:
- how many bytes in advance to search for prediction
- minimum number of unique characters to disable marking in the range

Must consider overhead of adding 0's 

If next n bytes are unique, disable RLE until there are matching characters in next n bytes

make prediction at end of run



### Other

Must decide on a unit size to read in at once, and cannot guarantee that a run of the same character will be contained completely within that unit

Read in one character at a time

Track run information such as character, current length of run and do not reset until a new character is detected

Flow chart for this in notes

