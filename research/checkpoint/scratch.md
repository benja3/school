# Scratch

## Meeting 03/11/2024

### High Level Plan of Tunable Benchmark Done

Know how to implement the three main tasks:
- I/O Leader to PFS throughput measurement
- Internodal congestion simulation
- Monitor Application Performance

### I/O Leader to PFS

Implment a function that behaves similar to I/O aggregation benchmark from SC23 paper

Will just generate a bunch of files on the I/O leader and copy them to the PFS, measuring throughput

Measure throughput in total bytes copied / total time

Will use the timestamp accumulator wrapper to easily track everything that is going on 


### Internodal Congestion

Spawn n OpenMP writer threads on each node and send data 1 - N

measure time it takes for the data transfer to complete

Could the heatdis benchmark be used for this by scaling up the problem size?

### Monitor Application Performance

Heatdis is split up into two sections: data transfer and matrix crunching

Will just put an MPI_Wtime on the ends of each section to monitor the state of computation and communication in the dowork() function

### Other

To tie it all together, will have a main similar to heatdis that goes through timesteps and decides what to do on each. 

Still kind of confunsed about how to tie all of the functions together in a single program. What should be done when to get the results we are looking for?

Going to be learning C++ while I implement this, any suggestions on the best way to go from C to C++?

What was I supposed to take away from the AI4IO paper?

