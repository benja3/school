# Caching

What is a core?

L1 cache split into two halves: instruction and data

instructions need to be near CPU to be fetched efficiently

Read more on cache details ( ask the right questions to learn as much as possible)

instructions typically executed sequentially which helps with storage locality

prefetcher: do not want to have to wait on instructions and fetch instructions and data before it is needed

each core has some private cache specific to its execution

inclusive vs exclusive caches

inclusive: L1 in L2 and L3

exclusive: lines only exist in each cache

Having cache in cores can make cache go unused if not all cores are being used

Most CPUs have individual L1 and L2 per cache and a shared L3

Intel KNL: configurable cache in the form of embedded DRAM

Must subtract lower cache sizes from bigger ones to get free space after inclusion

If it depends, what does it depend on?

Executing a for loop consists of moves, adds and jumps

The time to do this depends on stuff like memory access time, ALU cycle speed

How to know clock rate of CPU?

Read After Write (RAW): very important for parallelization
- something has to be generated (more instructions) before an instruction can execute
- eliminating dependencies or processing them in parallel can significantly speed up execution

superscalar: executing multiple instructions at the same time

variable clock speed done to manage power and heat

5 stages: fetch instruction, decode instruction, execute instruction, memory access, write back

can execute the stages independently to prepare for future instructions

this makes the time to execute an instruction the length of the longest stage

adding more stages can increase the amount of instructions per cycle, but mistakes causing the pipeline to be flushed could mean lots of clock cycles to get back
- full pipeline means good performance, but mistakes are costly

not every application can execute with a deep pipeline efficiently

branch prediction: predict what is coming next. if wrong, pipeline must be flushed

flushing pipeline leads to a lot of no-ops meaning nothing is getting done

want logic that determines mistakes early so you can correct sooner

CPU designers try to gauge what applications will need

bigger number clock speed does not always mean better

a CPU is only as good as the compiler that generates code for it

uncore: any part of the CPU that is not a core

RISC: few instructions with basic operations

CISC: Complex ISC: x86 has 1000+ instructions
- architecture is much more complex
- not all instructions useful

The complex instructions can do more in a single clock cycle
