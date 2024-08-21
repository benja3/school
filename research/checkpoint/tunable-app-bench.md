# Design of Tunable Application Benchmark for VELOC

## Overview and Requirements

C++ back to basics, CPPcon

unqique pointers, other smart pointers etc. are good for this

std::list

dont use shared pointers

compile with C++17

use emplace_back instead of push_back

### Questions

Should I be creating my own functions to max the internodal I/O or can I rely on the heatdis?

### Measure communication between compute nodes

Need to be able to see how fast different nodes in groups are communicating with each other and the leader. This shows how I/O leaders are impacted by contention at different group sizes.

### Measure communication between each compute node and PFS

This will represent a compute node writing a checkpoint file to the PFS. This process only happens occasionally, so will want to execute less frequently than other measurements like internodal communication. 

The IO aggregation benchmark from the SC23 paper contains most of this functionality.

### Monitor Application Performance

Doing checkpointing will cause overhead that interferes with the application since they are running concurrently. Want to monitor how long it takes for the application do finish its task while checkpointing is and isn't occuring.

Components of interest include computation and communication. Monitor this every timestep.

### Other

Should allow for verbose command line arguments to control each variable in the benchmark

Should collect data and output as CSV


## Research

## Imagine

### Need to figure out

how to combine all these together

### Ideas

measure application performance by timing do work

Have the heatdis benchmark which is a mock application, so can just use that to find computation and communication delays

Using C++ so have access to fancy libraries that can make things like strings easier 

Monitoring the app should involve no parallel I/O, just recording the times of when specific things finish. The node to node communication measurement will include the messages being sent by the application.

### Measure communication between compute nodes

Create a function that creates multiple writer threads and sends tons of information to each node continuously. 

Not sure if heatdis will be sufficient to max out the I/O. Can it be configured to do this? Could probably just increase the size of the matrix to send more data.

Could this just be run once at the beginning before any computation is done?

Simulate I/O contention with a burst of concurrent writer threads on each node trying to send 1-N?

Want to create contention which involves trying to send more data than the throughput allows


### Measure communication between each compute node and PFS

Just run the code to generate a bunch of files on the I/O leader and copy them to the PFS with concurrent writer threads

### Monitor Application Performance

use timestamps to log how long it takes to finish things like crunchin the matrix in do work

can track time it takes to send all the data between nodes and time it takes to compute the matrix independently

can run wtime before the send and after the recv and waitall to measure how long it takes to send the parts of the matrix to different nodes

run wtime before and after the matrix computation for loop

## Plan

Functionize each of the three main components

use wrapper to make life easier

have a for loop in main that runs through a certain amount of timesteps doing work, checkpointing and calling the benchmark functions
- similar to heatdis main 
- could just duplicate heatdis and modify it 

Config file or command line arguments? 

### Groups

Group size is command line argument 

select rank 0 to be the leader and others to be followers

### File Structure



## Build