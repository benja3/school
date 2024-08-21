# SDE1

## In Class

see instructions for rules and code outline

constraint based problem

provied with data base of flowers
- copy directly into project file

can modify the rules to have different flowerws

main predicate is garden plan that is called to start the process

plant assign: allocates the lists and puts flowers in

write prolog helper code to make sure everything is working as expected

output should be the same every time, so no random

write garden prints out the garden list formatted proprely

if odd number list, middle should guaranteed to be wet

## Overview

I am learning the mindset required to pick up new tools


## Research

Solving a constraint based problem. Define the constraints in Prolog.

can use _ as a wildcard

### Predicate

consists of name and argument list

example: flower(daisies, med, wet, yellow).

### Clause

fact or rule

built with predicates and logical connections

### Rule

Clause with non-empty head and a tail

### Goal

need to have top level goal for prolog to achieve

## Video

### Variables

can use a variable to find all the predicates that match a certain rule

example: parent(X, bob)

### Lists

denote with []

get head and tail with [H | T] = [a, b, c]

list will contain flowers

### Conditionals

prolog does not have explicit if statements

## Imagine

define is_valid rule to determine if a certain flower is valid in a space

for each item in the list run is_valid with each flower until a match is found

## Plan

top level entity: plantassign(N, List)
- N will be the number of flowers and List will be empty

use recursion to add flowers to the list

How to represent flowers in the list?

use random_select function to select random flower

### Approach

learn prolog tools and capabilities

find out which ones are relavent to solving the problem

learn how they work

implement
