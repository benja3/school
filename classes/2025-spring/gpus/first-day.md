# First Day

original graphics processors designed just for graphics, which made it difficult for them to be used for other types of programs

### Architecture

thread execution manager helps manage the parallel threads running across the many cores in the GPU

streaming processor: one of the tiny cores in the GPU

streaming processors are combined into streaming multiprocessors of 8 or so

stream processing: technique that simplifies parallelism

GPU's memory space is independent of CPU's memory space

to offload to gpu: run C program -> offload memory to GPU -> process in parallel -> load results to main memory -> continue running C program

### Stream multiprocessors

each thread in each core calculates the results on a different piece of data

be aware of single vs double precision

### CPU vs GPU comparison

GPUs do not have a shared L3 cache like GPUs do

GPUs save power compared to CPU runs at the same scale
