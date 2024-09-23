# More Caching

### What is a cache?

cache is SRAM memory typically (wikipedia for architecture differences)

cache is like a hash table
- needs hash function and key value pair
- cache stores data with key value pairs

key is address and value is data

direct mapped cache:
- each address has one location in the table that it will go to
- hash function: k % N

dirty bit detects whether the data is modified while in cache
- if dirty, must copy the value back to DRAM

LD/ST Queue:
- Load Store
- manages reads and writes such that do not have to wait on writes to continue
- read more online

EAX and EBX registers do not exist (purely logical). there is just a register bank and the CPU will write the value wherever it fits in the bank

register renaming
- reorder buffer

hardware structures like LDST queue have special registers in the CPU

When 2 addresses map to the same place, called aliases

must think of reasonable hardware solutions to manage the hashtable

double hashing: have two places to store data for each hash address

set associative cache: less entries but multiple locations per entry

if all slots full, evict

resolution tree???

rows in hash table called sets

### What is an address?

location in memory written as a hex value

hex words are great

virtual address space mapped to physical address space

memory management hardware in CPU

operating system works with pages of memory

translation lookaside buffer: a cache for pages of memory

suspending causes all the pages to be written to persistent storage, and be reloaded back to the same place when the computer it started again

address broken into tag, index and offset

tag: corresponds to key in cache

index: set in the set associative hash table

offset: how far into the cache line to start reading
- based on cache line size
- indexing into array of bytes that is cache line

eliminating metadata frees up space for other things in the CPU

lscpu shows address sizes accounted for other metadata bits

when loading address, need to know if it is in cache so decode address and check cache
