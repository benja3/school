# Document

## Week of 04/16/2024

Need to create new communicators to restrain the volume of communication occuring in different partsof the benchmark.

https://mpitutorial.com/tutorials/introduction-to-groups-and-communicators/

Can use MPI_Comm_split to make a new communicator
- color: processes that pass in the same value for color will be added to the new communicator
- key: determines ranks within the new communicator

How to scale the volume of communication occuring? Variables: processes in communicator, threads per process, buffer size, number of comm functions called

Thinking I should hold the buffer sizes and number of functions calls static and scale with threads adn processes

Scatter: break up data and send it to all processes in a communicator, including the root.
- https://rookiehpc.org/mpi/docs/mpi_scatter/index.html
- use MPI_Bcast to send the whole array to all processes

Gather: the opposite of scatter. takes data from all processes and combines it into a single buffer at the root process. 

Collective Operation: involves the communication of all processes in a communicator (scatter and gather)

### Meeting Prep

This week, I started planning how to generate the communication with MPI functions. 
- Peer to Peer: neighbors sending to each other
- Collectives: Alltoall, Allgathers, Allreduces

Doing std threads because what has been used in the rest of the project

Question before I implement: When I scale this do_comm function, should just processes and thread be scaled? 
- Just doing threads and processes

Suggestions for buffer sizes?

Want to spawn threads ever timestep or just when checkpoint occurs?

Not much time with SCC app and helping people with Pi clusters plus going home and end of semester projects. 

## Questions

Monitor communication during all checkpoints?
- could be useful to compare checkpoints with and without contention
- contention will also be tunable so could just set values very low

Take average of times for each rank?

## Week of 04/01/2024

Could just start with a basic tracking of do work and move into implementing contention later just so I can get something done

Log: timestep number, dowork comm time, dowork comp time, 

## Week before April 1st

### Questions



When writing to pfs, use actual checkpoint files or simulated ones?
- will real files be big enough?
- configurable to any size

### Notes

What is the $(MAKE) directive?
- represents the call "make" itself

.PHONY means that this recipe does not acutally involve making a file

This entire thing is just a massive heirarchy of makefile abstraction

Make sure your dang code is right before you compile because it takes like 5 minutes. 

Use configuration file for inputs because so many

Figure out data logging last after the code is written


## Meeting 03/24/2024

Have not made progress on the benchmark itself

Over break, reviewed C++ content to make sure I was familiar with the tools it had to offer so I could right good quality code

## Meeting 03/04/2024

discuss notes from Mikaila meeting

nearly finished reviewing IO benchmark code and when done with that, will start development work

have a good medium level understanding and this week will start looking into lower level implementation details

## IO Aggregation Benchmark

### OpenMP threads

use pragmas to specify that certain sections of code should be run by threads in parallel

## Meeting 02/26/2024

### Prep

Since last meeting, I have read, understood and executed the heatdis program, as well as put some thought into an MPI Wtime wrapper like suggested.

For heatdis, I traced the code to understand what each section was doing, and reviewed the included MPI and VELOC calls. Learned how the VELOC api is used, and also gave myself an introduction to parallel programming while tracing the code. 

Ideas for MPI Wtime wrapper:
- create objects that are essentially time accumulators 
- objects will have tags that identify them, so can have multiple accumulators for different purposes
- the accumulator objects will maintain a data structure of time stamps, and calling a specific function will add a new time stamp to the data structure with a tag for identification
- would include functions to do things like report the total time for all time stamps in accumulator, report the difference between two time stamps, etc.
- this would prevent having to have a bunch of variables in the code to do advanced timing with MPI_Wtime

Better to do MPI_Wtime wrapper in C with structs, or with C++ objects? 

### Report

## IOR and marcsio

### IOR 

https://ior.readthedocs.io/en/latest/

writes data sequentially based on parameters:
- block size
- transfer size
- segment count
- num tasks

### MACSio

https://macsio.readthedocs.io/en/latest/index.html






## Running Heatdis

Must append: 

```/home/bschlue/research/checkpoint/ckpt-aggregation/build/lib:/home/bschlue/research/checkpoint/ckpt-aggregation/build/src/lib:/home/bschlue/research/checkpoint/ckpt-aggregation/build/src/modules:/home/bschlue/research/checkpoint/ckpt-aggregation/veloc/lib64```

to LD_LIBRARY_PATH


## Ideas for MPI_Wtime wrapper library

want to be able to have multiple timers

could allow user to create key value pairs related to time stamps

each accumulator could maintain a data structure of key value pairs (timestamps) which have labels and the accumulated time at which that label occured

could provide functions that take in timestamps and calculate the difference between them and other timestamps

struct accumulator:
- label
- offset from first wtime call
- data structure of timestamps (could use 2230 linked list)

struct timestamp:
- label
- wtime value

functions:
- add_timestamp(accumulator)
- double difference(accumulator, timestamp1, timestamp2)
- total time for this accumulator

## Building VeloC with Adios2

Started by cloning the ckpt-aggregation branch to palmetto and switching to the frontier branch as suggested

Needed to install adios2 using spack. Ran into several errors that helped me learn about spack. The first involved one of the adios dependencies requiring a cmake version higher than what was beign used by default (3.21.1). To fix this, had to use spack to install cmake 3.27.7 and tell it to use this version when installing adios. Also, the gfortran compiler was not found for gcc version 9.5.0, so had to go into the compilers.yaml file to specify the location. 

After these issues were resolved, the install of adios completed to 98% but failed due to undefined references to MPI functions in the ```adios_write_bench``` file. This has not yet been resolved. 

## Feb. 12 Meeting

Talk with Mikaila to get a better understanding of the big picture so I am not dependent on her instruction to contribute

MPI undefined reference issue likely a result of a runtime configuration difference between palmetto and the system that Mikaila was originally running this on

Me and Mikaila's goal is to find an optimized way to write large scale checkpoint restart data

## Feb. 5 Meeting

### Before next meeting

understand what VELOC does and how it is different from other libraries

build VELOC