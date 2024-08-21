# Parallel Programming Notes

## Questions

When does the actual forking happen in MPI?

## Theory

MPI used to solve problems too large to fit in the memory of a single processor

## Basics

All MPI programs must start with ```MPI_Init``` and end with ```MPI_Finalize```

### Processor Identification

since all processes use the same executable, must find a way to distinguish instances from each other and make them do different things

Can use ```MPI_Get_processor_name``` to get the hostname of the node a process is running on

```MPI_Comm_rank``` and ```MPI_Comm_size``` return process ID within the communicator, and the number of processes in the communicator

Knowing ID is enough information to do basic parallel tasks, such as decide which section of data to operate on 

## Communicators

Object that describes a tightly coupled group of MPI processes

```MPI_COMM_WORLD``` describes all processes that a job starts with 

```MPI_COMM_SELF``` only contains the current process

```MPI_COMM_NULL``` is the invalid communicator, and is used for errors and other invalid operations

Communicators are predefined and do not need to be set up by the programmer

Type is ```MPI_Comm``` 




## Functions

### MPI_Init

Initializes MPI environment 

Must be called by each MPI process

Can pass in argc and argv from main, but these are only guaranteed to be passed to rank 0, so the best way to share args is with a broadcast

the program

### MPI_Finalize

destructs MPI environment

no MPI functions can be called after this

### MPI_Abort

Terminates the process of the communicator passed in

if MPI_COMM_WORLD is passed, all processes are terminated

### MPI_Get_processor_name

returns the hostname / processor name of the node / processor the process is running on

### MPI_Comm_size

returns the total number of processes in a communicator

### MPI_Comm_rank 

finds the number of the process in the communicator that calls the function

returns the errorcode, not the rank; variable to store rank in passed in as arg

### MPI_Send

Standard send function

makes a decision about whether the send will be synchronous or asynchronous 

arguments:
- buffer: buffer to send
- count: number of elements to send
- MPI_Datatype datatype: MPI wrapper to represent the type of data in the buffer
- recipient: rank of process that will receive data
- tag
- communicator

### MPI_ISend

The "I" means non-blocking and the function returns immediately

Non blocking version of send

takes an MPI_Request type argument, which is a handler to *** REVIEW

### MPI_Waitall

takes arrays of requests and statuses and waits until all the requests (representing asynchronous tasks) have completed




