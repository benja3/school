# Minic Parser

## Syntax 

start: transunit 

main-decl: declaration of the main function 

body: contents of a function, defined with braces, declarations, etc. 

left vs right recursive: whether the recursion occurs on the left or  the right side of the statement 

limted parsers are a lot faster than more expansive ones 

The less is in a language, the faster compilation is 

recursive definitions used when the length of a string is unknown

*** what is identifier? It is a type or any other syntax used to identify something 

Compilation process breaks down into scanner and parser

Scanner uses regular expressions to locate all the different symbols in teh program
- produces tokens that are sent to parser 
- structure of the program remains the same

Parser takes the tokenized version and breaks it down 

## Derivation Tree

when a program is parsed, a tree is constructed where are internal nodes are rules 

see slide example 

trees are used to convert from higher levels like variables to lower levels like the value of the variable 

parse trees can get massive, so they are built and reduced in stages to prevent the required memory from growing exponentially 

terminals are the leaves of the tree; they are the lowest level symbols that do not reduce to anything else; they appear in the code at the lowest level; non terminals can be broken down further and are the internal nodes of the tree 

keywords like return are terminals 

tokens are symbols that represent keywords such as "while" so the parser does not have to deal with characters (separation of concerns)

## Essential parts of Syntactic analysis 

### Scanning

comes first 

lexical anaysis 

uses regular expressions 

### parsing

syntactic analysis 

top down parse: fill tree from teh top down 
- typically easier

bottom up parse: start with terminals and build up 

## CYK Parsing Algorithm

### Table

Dynamic programming: building parse table and looking at all possible ways to group inputs and find one that works 
- produces all possible ways of parsing a string with the grammar

*** What are applicaitons of this?

construct diagonal table 

If two letters in a square, both are valid -> A | B,C -> AB | AC 

Construct triangular table whos blocks allow for taking the string (bottom of table) and look at all possible ways to parse it 

*** Will have a CYK problem on the test 

use highest level non terminal(s) that corresponds to the terminal 

If something parses to S, it is a complete program in the language 

if top box contains S, string is valid in language 

The capital letters are non terminals like identifiers and loewr case are terminals like ```int```

Example Application: can have if statement with a single line of code with and without brackets 

## Parsing with Flex and Bison

flex and bison most commonly used parsers

see man pages 


















