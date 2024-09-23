# Verification and Testing

Testing about finding faults rather than fixing bugs

a the misplacement of a single atom can mess up a chip

can the failure be detected before the chip is deployed?

## System design

review this later

### Specification

If hard requirements, write the user manual before you write the code

put things on paper to make sure there are no misunderstandings

keep is simple stupid

dont start coding until the design is done

### Verification

if you didn't test it, it doesn't work

test all modules, all states, all transitions, all edge conditions

find ways to accelerate testing

if testing is too hard, you won't do it

stop and think before changing code

### testing approaches

BIST build in self test

can build testing modules into the chip to make sure all components work

### faults

complex issues are made of simple issues, weed the simple things out by unit testing and using other good practices

dynamic faults: only happen in rare certain cases 

stuck at fault: when something is forced to 0 or 1 at all times

will be on test

multiple faults: one can mask another in different ways
- if all the single faults can be caught, there will be no multiple faults

the purpose of testing is finding faults

not all chips work perfectly, the ratio is called the yield rate

this type of testing does not involve locating the fault, just detecting it and throwing out the chip

## Stuck At Model

look at ever wire or node in circuit and check what would happen if it was fixed at a certain value

use on a design that should work and is proven to work; used to find the buggy chips after manufacturing

detection of fault invovles comparing the output of a known to be good chip

detecting the location does not really matter unless it is happening consistently in the same spot and the design should be reviewed

must design for testability to make testing easier

with this model, not all faults can be detected by holding a single signal

if a certain input is the only one that will detect a fault, it must be included in the test set

can significantly reduce the amount of tests from all to the necessary test set

## Path Sensitizing

dealing with individual signals is impractical for large circuits

group several wires that form a path and treat them like an entity

other inputs to gates on the path need to be held constant

## Random Tests

by putting in random inputs, odds are high that all the potential faults will be revealed

does not work well for high fan in circuits

## Testing Sequential Circuits

combinational is easy because just I/O

the memory in sequential circuits adds a lot of complexity

hard to track the state throughout the testing process

design the testability into the chip 

to test, put it in a known state

### scan path technique

add muxs to inputs of flip flops so they can either be the regular input or a test input

do have to add extra hardware but worth the cost

## Built In Self Test

BIST

another part of design for testability

what if the test hardware was built into the chip

two structures built in: RNG and compressor

need an input to set test mode that will send activate the test modules with mux

problems can occur if psuedorandom tests od not cover all possible faults

signature: smaller code compressed from original test data; possible for faulty data to be compressed into same signature of good 

signatures for correct chips baked into BIST unit

## Boundary Scan

## PCB issues

PCBs contain multiple layers of wiring

switching in CMOS circuits induce voltage spikes at power supply; can be reduced by addings caps 

## Final Not Cumulative

do twos complement for -1 and -2 recoding



