# Exam 1 Review

## In Class

S represents a complete program in the language

if there is an S in a block below the top, cannot assume that there will be an S in the top

CYK Parsing based on chomsky normal form where all ***things*** go to two non-teriminals and a terminal

need to know both basic regular expressions and the flex extensions


## Types of Grammars

Noam Chomsky created mathematical model of grammars

these are restrictive classes

### T0 Unrestricted

any grammars, no terminal / nontermianl positioanl restrictions

not typically used because algorithsm cannot be developed to parse 


### T1 Context Sensitive

allow for multiple thigns on left hand side of the rule which are called contexts

can only apply rules wihtin contexts

rules only apply in certain states

not efficient to parse

### T2 Context Free

used for CYK parse

can on ly have one non terminal on the left, but anything on the right

good for dealing iwht things like balanced brackets

can put non terminal within braces taht can be expanded into any amount of code

used for most programming languages

chomsky normal form a variation of context free, but adds certain rules

### T3 Regular

regular expressions

flex, awk and other regex pattern recognition tools work with these

Right Linear is the nonterminals are to the right of the terminals

Left Linear if the nonterminals are to the left of the terminals 


## Language Paradigms


### procedural

program works down a logical chain and executes commands

contains globals, locals, functions, loops, etc.

### functional

everythign is a function

a pure function is one where the only inputs come thorugh args

no access to global variables

if a function is called with same args, will produce same results every time regardless

### declarative

declare things to be true (facts)

using network of related facts, can look things up and make predictions

Prolog contains a database search engine to make connections

### object oriented

can create data types with members and functions embedded in them

example: stack object
- members: size, top of stack ptr, etc.
- methods: push, pop

restrict ways of programming to make solving complex problems easier 

### rule based

used in expert systems, which contain a bunch of connections or rules

inputs can modify the rule to serve as machine learning

similar to declarative

### event driven

real time systems that take feedback from the environment and act based on it

## Dyna mic programming

way of solving optimzation problems by creating table and decomposing the orignal string into different patterns 

produces multiple ansers, and select the best possible answer








