# Flex and Bison 

## Regex in Flex

regular expressions form base for flex token recognizer

most strings are regular expressions that just match with themselves only

can use \ as an escape key in regex

see table 1 chapter 6 for regex building blocks

can have states where certain rules apply

### Input Structure

can specify C code to execute when a regex match occurs

code returns to the parser 

tokens are just integers that represent different terminals 

### Output

output is a file lex.yy.c
- yy comes from yacc 

scanning function called yylex

### Sample file 

contains two columns, one with the regex and the other with code to execute 

see slies for file and output 

the flex file prints out the tokens corresponding to the strings in the code file

compilers generally do not pay attention to white space or comments 

### Bison and Tokens

flex creates function called yylex()

bison produces parser as function yyparse()

## Bison

general purpose parser generator that convets grammar description into c code to parse the grammar

produces yyparse() function 

user must provide rwapper code such as main and other functions like error reporting, etc. 

### Pragmatics of Bison

1. specify grammar in bison grammar files

2. write or generate lexical analyzer 

see slides for more 

does not include semantics, which decide what the tokens actually mean



### Conveying Grammar to Bison

parser generated in form of bison grammar file 

non terminals represented as lower case identifiers

terminals are upper case 

want terminals to be obvious 

input files end in .y

must state rules of grammar in bison file 

should never include .c file; handle all that in the compiler becuase including .c files can do weird stuff behind the scences 

need default error handler called yyerror(), 

## Overall project

Lexical analyzers do not contain main function

yyparse is called within main 

yyparse parses the entire file 

could want to do more complicated stuff before the parsing begins, and can implement this in main  

## Walt's Filesystem

threading much more optimized now than in the 90s

can create flags that make certain rules active in certain states: <CODE>, <COMMENT>

Can specify whether tokens are represented by integers or characters 





