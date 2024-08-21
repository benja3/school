# OCaml Project

## Overview

### Questions

### Why

Walt is making me. It will give me good experience learning a new tool. Take advantage of this opportunity to learn how to learn. Also, boosting confidence that I am a great computer engineer and can solve problems.

### What

Writing specified OCaml functions

### Who

Solo but can work closely with Matt

### When

Due Friday April 26th

### Where

Anywhere

## Research

ocaml function sheet on canvas

https://youtu.be/_L_UMDI7-3E?feature=shared

see examples on canvas

### How to properly learn OCaml

I have been trying to BS this project and it does not work. If I am going to be successful here I need to learn OCaml properly from the ground up. Lets break down the steps do doing this. As much of a time crunch as I am in, lets not rush. I need to take this opportunity to do reinforce my engineering skills and do it properly.

Steps:
- learn the functional paradigm
- learn the concepts of ocaml
- for each concept, learn how to implement it

Follow through. Do not do a half swing and only execute part of the process. Do the whole thing. I have had issues staying focused and following through, so practice it now.

Do not take too big of steps. Going from knowing nothing to do this project is like trying to jump from one floor up to the next with no stairs at all. Part of the reason I have been struggling in both of Walt Ligons classes is because I do not learn much from class, and going from that limited knowledge to implementing a project is too much of a jump. I need to build some steps by filling in my knowledge gaps. Right now, I have found a video playlist on OCaml. I am capable of watching this and learning the language for as long as it takes. I will do that.

### Functional Programming

functional languages use expressions, not commands

expressions are composed of functions

anonymous function: function without a name

functions can return functions (do not do this in the project)

functional languages do not use iteration but recursion

define computations as mathematical functions and avoid mutable (changeable) states

state: the information maintained by a computation

in functional programs, expressions specify what to compute

variables never change value

do not need to worry about pointers and managing states

languages are tools: certain languages fit certain problems

## ocaml

### expressions

have syntax and semantics

type checking semantics: produce a type or fail with an error message

evaluation rules: produce a value or exception or infinite loop

### value

expression that does not need further evaluation

all values are expressions but not all expressions are values

### types

types are automatically decided

### if expressions

use keywords if <cond1> then <code1> else <code2>

require a type bool, not integer 0

### anonymous functions

int -> int : function takes in an integer and outputs an integer

do not put parentheses around function arguments

### named functions

let <function name> <input(s)> = <expression>;;

call function: <function name> <args>;;

ocaml has lots of syntactic sugar

### recursive definitions

must explicitly state that functions are recursive with "let rec <name>"

### function types

i -> o represents a function that inputs type i and outputs type o

t1 -> t2 -> out takes in t1 and t2 and outputs out

### lists

written inside square brackcts

[];; - : 'a list = []
- 'a means no type

[1] will be an int list

delimit items with ;

int list list: list of lists of integers

add an element to the front of  list with ::

1 :: [2;3] -> [1;2;3]

list are immutable, can only construct new lists from old ones

data structures are tools: pick the right one for the job

available list functions:
- List.hd
- List.tl
- List.cons
- List.nth
- List.mem
- List.append

## Unabstract

see project doucment for details, I am not copy and pasting everything overhere

will likely need helper functions for each one

:: to build list

need two lists for the first two problems

dont use nested functions

### first_duplicate

let rec firstdup (l1, l2) =

first_duplicate should be a wrapper and call another recursive function that determine the value



### fist_nonrepeating

### sumOfTwo

### take

### drop

### powerset

## Taskify

Learn, plan, write and test each function

## Goals

TBH, this project is not as high on my priority list as others. I will likely wait until next week to work on it. Goal setting will come in the future.
