# Combinational Logic and Abstraction 

Multi-value logic: contains U, Z, etc.

## Overview 

How to represent 1's and 0's in physical circuit?
- represented with voltages, but specifically how?

## Voltage Ranges 

See diagram in slides 

Specific voltage ranges define 0 and 1
- 0: -0.3 V through 0.7 V
- 1: 1.7 V through 2.8 V

on either side of the 1 and 0 range, there is a damage range and an unknown range 

If the unknown range was not present, the logic would not be stable due to noise 

## Noise Tolerance 

digital systems noise tolerant unlike analog

a little bit of noise will not push the voltage out of the 0 or 1 region, meaning interprettation is not altered 

Without boundary region between 1 and 0, noise could potentially flip a bit 

signals are periodically restored to keep them in the valid range 

In analog, there is a difference between 2.3 and 2.4 V, but not in digital systems 

If the voltage of an input signal is V and a noise n is introduced, the output

Signal restoring devices guarantee a smaller 0, 1 voltage range that still fits within the standard range 

When a voltage is changing, want dVI/dVO to be very high in the transfer region and low in the 0,1 ranges 

## Data Representation 

There are many ways to represent data with bits, pick one that is minimalist and appropriate for the problem 

Can use bitmaps for flags where each bit represents a different flag, can use bitwise ORs to perform operations on the flags and combine them 

## Combinational Logic 

Outputs only depend on inputs; no feedback or memory 

Same input will always produce the same output 

Can be described with english descriptions, logic equations and truth tables 

multiple implementations for same equations; can circle different things on kmap

some equations are more efficient than others

## Sequential Logic 

Involves feedback and memory 

output depends on inputs as well as data stored in the circuit

can be synchronized with a clock 

Circuits can be made up of both sequential and combinational components 

## Circuits with subsystems 

output computed from memory in sequential can be fed to combinational case statements to activate different things

good too block out subsystems 

Most digital projects are too complex to not use subsystems 

## Closure

If you stick 2 combinational circuits together with no feedback loops, the result is combinational 


## DeMorgans Law

~(x & y) = ~x | ~y

~(x | y) = ~x & ~y

Can use to replace certain gates with ones that cause simplification 

## Hazards 

Hazard occurs when an input changes and the result should not change at all, but flips for a brief period of time before returning to the correct state 

Occurs due to real world circuit delays 

Might not be noticable if output is not used while the hazard occurs 

Can make a circuit hazard free by adding more k-map implicants to cover the transition states
- less efficient, but eliminates hazard

Static hazard: output should be x but swithces to !x for a brief period 

Dynamic hazard: output should change from 0 to 1, but changes to 0, back to 1, and then back to 0

## Summary

systems are digital at the core and only analog at the edges 






