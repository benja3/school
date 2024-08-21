# Parallel Programming

key issues:
- parallel algorithms
- parallel hardware

how to decomponse task into something that can be broken apart and executed in parallel?
- software and language problem

questions:
- where is the parallelism?
- how can the parallelism be described in a programming language

data dependency: when one line of code depends on the results from another
- can execute parts before data dependency in parallel

do not think of parallel programming in terms of its concepts, think of it logically and then map the logic to concepts

analyzing runtime of paralle is similar to big O notation but adds some more variables

## Performance Limitations

running on n processors will not lead to completion in 1/n time

1/n is an upper bound 

must consider the communication overhead that was not a problem on the single processor

speedup = single / n processors 

### amdahl

some parts of a program cannot be sped up

## MPI

### Why

MPI itself is not software, but a standard with function calls, args, types, semnatics, etc.

## OpenMP

### why

API for shared memory systems

classes of parallel:
- message passing
- shared memory

can only run on a single system

## Science

classical science: develop a theory, develop an experiment to test the theory, observe and analyze the results

modern science: develop theory, numerical simulation, observation, analysis

## Beowulf

came from NASA

walt worked with tom sterling, one of the founders of this project

use commodity processors and interconnect, linux, and MPI

## Advanced Strategic Computing Initiative

gov put money into parallel computing to ensure quality of nuclear stockpile

## data parallelism

independent tasks apply same operation to different elements of a dataset

## Functional parallelism

independent tasks apply different operations to different data elements

functional: different tasks do sifferent things

can be tricky to work with because want tasks to be around the same length of time

## pipelining

divide process into stages and prepare the data for the next stage in advance using free resources

## Data clustering

organize data into clusters of similar items

## Programming parallel computesr

### extend compilers to translate sequential programs to paralle

detect parallelism

can make design choices that reduce the amount of possible parallelism

do not have to rewrite existing code to be run in parallel

### extend languages to add parallel operations

add functions to sequential language

MPI: adds functions to C / C++ to do the parallel stuff

easiest, quickest and least expensive approach

compiler is not as aware of issues

### can add parallel layer on top of sequential language

### define totally new parallel language and compiler system

difficult to get programmers to switch to a new language

lots of people writing scientific codes are scientists and do not want to bother learning a new langauge

# Ligon's slides

goal is to speed up computation by distributing work across parallel processes

## COmmunication 

interesting programs need to communicate

communication is not free and cost must be managed
- takes resources and influences the behavior of the program

### pass messages

explicitly send and receive information with function calls 

gives programmer more control

### Share MEmory

processors have access to same memory banks and read / write shared variables

tranfser of info handled in the background

need to use locks, semaphores, etc. to prevent race conditions

### message passing semantics

primary functions
- send
- recv

these have variants:

### syncrhonizaiton

one processor has to stop until an event happens

non-blocking: does not block but might fail due to other timing issues 

async: returns immediately and runs in the background
- in user level, must use thread

### buffering

no buffer: requires synchronous comm
- will send until done because no place to store data
- data needs to be handled immediately adn cannot wait or it iwll be lost

infinite buffer: non blocking

partial buffer: will block in some cases where data needs to stored temporarily before the operation can continue

explicit buffer: user handles buffer space

### naming

direct: processes name each other directly

indirect: send and receive via mailbox; any process can read and write to the mailbox in any order

symbolic: number erpresntation

symmetric: processes must name each other

asynmmetric: must send explicitly but can receive from anything

### data 

stream: read n bytes at a time into a buffer as they arrive

## MPI

### collective

involves groups of processes

tasks that involve the communication of every process in the group

### interface

one of those interfaces designed by a committee from experts from everywhere

MPI 1.1 is the basics and 2.0 / 3.0 add more features

### MPI JOb

job creates n copies of the program

one process manages I/O 

different processes can be given different tasks

# MPI Part 2

essential commands:
- init
- comm size
- comm rank
- send
- recv
- finalize

primary methods

can create all other mPI functions with these

communicator: abstract representation of a network

be careful that ends other than the end of main because of MPI_Finalize

## Data Types

Built in types: CHAR, INT, etc.

encodes the type of data sent and received

### user defined

can create your own new types like structs that can be encoded with MPI

## Status struct

can reference status.MPI_SOuRCE, etc.

## Examples

can use a for loop with recv to make everything print out in order 

if the recieve buffer is not big enough, part of the emssage will be lost

MPI_Probe allows for the message size to be checked before it is received

## Semantics 

### Non-overtaking

if sender sends two messages in succession ot the same dest and both match the same receive, this operation cannot recv the second 

the first recv will block until it is satisfied, so the second will not 

can use tags to identify which should recv a send

### Progress

### Fairness / Starvation

MPI does not guarantee fairness matching

messages from different sources may overtake one another

two sending processes on different nodes do not coordinate

most implementations do queuing to increase fairness

### Limited Resources

MPI does not guarantee resources exist for sending and buffering messages

if this was the case, the program could deadlock waiting for resources

### combined send/recv

can do both send and recv in a single function call that takes both send and recv args
























