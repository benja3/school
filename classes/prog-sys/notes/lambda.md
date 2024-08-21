# Lambda

## Lamda calculus 

basis for computation bsed on defining and using programs

very simple syntax but powerful semantics; with little code, can describe complex situations

allows functions do be applied themselves, leading to natural recursion

languages: LISP, ML, OCAML

syntactic sugar: use syntax to abstract a more complex definition

syntax only has 4 productions

## Turing Machine Analogy

Turing proposed an idea

Turing machine: finite state machine with an infinitely long tape that can move in any direction, and a head that can read from or write to the tape 

theoretical construct that allows for the discussion of runtime of algorithms

## Relations and Function

Binary relation: R: a -> b

a function is a special case of a relation where f: x -> y and all x must evaluate to a unique y

functions can return objects that are more complex than just an integer

### Example

square: int -> int

square(n) = n^2

## Production

Expression ::= variable | constant | (expression expression) | (lambda variable.expression)

### combination


