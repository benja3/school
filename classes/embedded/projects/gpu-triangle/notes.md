# GPU Triangle Rendering

## Overview

### Questions

### General

given instruction on how to do the rendering process

### Requirements

Arguments: PLY object file, three rotation angles, output file name
- PLY file: contains info on polygonal shape to be rendered
- rotation angles, set a camera position
- name of output PPM image file

image dimensions: 256 x 256

## Research

## Imagine

Will create libary for managing file I/O 

Create a struct with members such as the file pointer, the array that stores the contents, etc.

## Plan

### File I/0 Libary

name: libfio

struct fio:
- FILE* file_ptr
- int size: size of file in bytes
- void* data: array with file contents

fio* create_fio(char* input_file_name, int debug): will create a file pointer, and read in the contents into an array all in one function




