# Scheduling

## Time Slicing

programs hop on the processor, do a little bit of work and then hop off

linux uses /proc filesystem to decide what to scheudle next

## Priorities

Equal priorities are worst possible case

## Rate Monotonic

techinques to analyze if tasks will meet hard deadlines

### assumptions

preemptive scheduler: tasks can swap during execution

periodic and non-ninteracting: no shared resources

deadlines

shorter period gets higher priority

### RMA formula

for all i from 1 to n where n is the total number of tasks, try 

### preemption

save state of a program by taking a snapshot of its state of execution 

## Resource sharing

implemented usign time slicign and CPU quanta

### locks

critcal sections, semaphores, etc.

cannot have critical sections running in parallel

the semaphore is passed between programs

### deadlock

when all processes are waiting for each other

each process waits on a resource owned by another

### priority inversion

shortest period gets highest priority

when a higher priority task is waiting on a lower one to finish before executing

fix with dynamic priorities

low priority tasks that are in the way are boosted to high priority so they can finish

the low priority task (now high) will finish in the time cycle and the high priority task will hop on before any thing else can

### priority ceiling

OS has table of tasks, priorities and reseoruces used

also has a table of resources and teh highest level priority task that needs it

start of with sys ceiling of 0 because nothing in use

task A wants to allocate antenna, can because system ceiling is low

sys ceiling goes up to P2

motor cannot be accessed because it is not greater than P2

north korean missile detector is higher than sys ceil and can access the motor

### highest locker

like hot potato game

## Direct vs push through

direct: higher priority waiting on lower priority using needed resource

to do anything on a computer, it must be turned into math

when dealing with floating point number comparison, add a tolerance

## Aperiodic tasks

trade off between polling too fast and too slow

use sporadic server to queue events when they occur





