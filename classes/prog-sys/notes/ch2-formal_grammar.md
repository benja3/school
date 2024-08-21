# Chapter 2 Part 1: Formal Grammars 

## Programs are Strings 

see program on slide 2

Maximize whitespace in code to make it more readable
- yes it looks cool and smart to have dense code, but it is a nightmare to read 

all programs could be written on a single line with separators, but are not for obvious reasons 

Source code is just a sequence of symbols

## Formal Grammars 

A grammar and a language are two ways of explaining the same thing 

See slide 6 for details 

can use grammar to generate or parse 

## Language Compiler

Compilers contain parsers to take the grammar and analyze the syntax of the program written

compiler will parse the program and generate low level machine instructions based on results 

## What are Grammars?

Parsing involves the creation of a parse tree

Similar to breaking down sentences in english class 
- parsed sentences based on the grammar 

Concepts of sentences in english are similar to lines of code 

### Formal Definition


A grammar consists of 4 entities:
- set of primitive symbols that are the building blocks
- non-terminal symbols are are used as intermediates to define rules 
- a set of possible productions 
- a start symbol at the top of the tree that everything reduces too



## Alphabets 

list of words and symbols that can be used to forms words and sentences (or lines of code)

In math, can declare an alphabet as a list of symbols V = {a,b,c}

Finite languages: can only have a specific number of possible arrangements 

Infinite lanuguages: unlimited possible combinations
- valid to have one letter of the alphabet repeat infinitely 

## Closure

defined as V+ = V U V^2 U ...

V^2 is all pairs from the alphabet V

V* is V+ U empty set 

## Application Modes 

### Generative 

Grammar is used to create a string of terminal symbols

Will results in a sentence 

### Analytical 

given a sentence, need to figure out if the sentence is in the grammar and more information

## Languages 

A subset L of VT is a language 

VT is set of all combinations, L is set of valid combindation for a language. Not all combinations are valid in a language 

Any symbol with a capital letter is non terminal 

## Grammar Types 

Developed by Chomsky

### TO

all possible grammars and all possible touring computable languages 

Alan Touring came up with computability 

Touring Computable: any algorithm that can be computed on a machine 

Universal set 

### T1

context sensitive 

grammars that cannot be computed or parsed 

weird alpha beta formula: 

these grammars are very capable but cannot be parsed and are therefore not useful 

### T2

Most useful

context free grammar 

push down automata: like turing machine but has a stack ***

left hand side is one non terminal 

### T3

Regular grammars 

not as expressive as T2

corresponds to regular expressions 

regular expressions used to parse in compilers

Tokens: identifiable units in a T3 grammar 

left hand side must be one non terminal, right hand side must be 

### Examples

a*b*: can have any number of a's that come before any number of b's

a^nb^n: must have the name number of a's and b's 
- example: for n open parentheses, must have n closed parantheses 

a^nb^nc^n: 3 sets of chars that must match 

## Why Important 

Context free languages and grammars most accurately represent modern programming languages 

## Regular Languages

T3 Languages what can be represented with regular expressions 

lexical analysis: compiler scanning for tokens 

## Regular Expressions

describing strings from regular langauges 

### Atoms 

basic symbols like 'a'

when included in a regex, this symbol will be included in the results

### Concatentation

if two atoms are next to each other 'ab', must appear in this order

### Alternation

use a|b to represent a selection of one or the other 

### Kleene Star

typical * operator that can be subbed for any string 

### Parentheses

represents grouping and scope 

### Examples 

see slides because it is too much to write 

### Tool Additions

a+: one or more copies of a
ab(2,5): between 2 and 5 copied of ab
\[a-z\]: range of characters between a and z
- like a lot of |

## Finite State Automata

*** review 

Could design a hardware state machine for any regular expression or T3 grammar 

## Derivation / Parse Tree

Root of tree is starting symbol S

Leaf node are terminals 

Interior nodes are non terminals 

children of a node represent the right hand side of a production P















