# Memory Access

hardware makes a machine fast and software makes a machine slow

the worlds fastest hardware can have bad performance if it is executing bad code

predictable memory access makes it easy for hardware to prefetch values

gcc instrinsic?
- look like C functions but the compiler will translate them into assembly
- have the __ before them

prefetch parameters:
- size of each item
- current address
- number of items to fetch

actual prefetch parameters:
- address end
- read or write (0/1)
- temporal locality ( how frequenty the value will be used ) (0/3)

size in implied from type of address

cache line vs word

r/w and locality must be compile time determinable

temporal locality: if you access something, you are likely to access it again in the future

not guaranteed that this will work, but just trying to help the compiler in what ways you can

too much can slow down code

how far in advance to request data and how much to request?

a small array can fit in cache but a big one cannot and will be cycled out and has to be reloaded

loop unrolling is making a loop have less jumps and more assignment statements

to unroll use a #pragma

experiment with rolled vs unrolled loop execution times

unrolling gets rid of useless instructions

optimizations can break code

in floating point, a + b is not b + a

while something is in cache, do as many operations as you can on it

loop fusion: if have multiple loops that do operations on the same data, can combine them into a single loop

__inline: dump code of function here ???

performant C++ code has a lot of information in the header that the compiler can use for optimization

there are software tools that will tell you how your program is performing
