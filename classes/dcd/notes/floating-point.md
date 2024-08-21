## Floating Point

error is difference between real number and representation

to represent all real nums, need infinite bits

goal is to economically represent numbers with given accuracy

when absolute accuracy required, need fixed point
- decimal does not move from a specific position in the string of bits

different machines might produce different numbers when working with floating point




### absolute error


see formula in slides

floating point value - real value

### relative error

compares absolute error to magnitude of x 

### accuracy

measurement of how close to the target the guess is

see accuracy formulas in slides

### precision

how fine of measurements are we working with

### represenation

for all real numbers, there are thresholds where reals that are too precise will all map to the same floating point number

normalization: shifting and adding to create the most efficient representaito

the reason floating point numbers are dsiplayed as 8.53E23 is to display the fraction and exponent

lots of fun tricks to handle floating point arithmetic at the bit level to make it memory and computationally efficient

All formats normalized, which means that the decimal is put in a specific spot. If not in the location, shifting will occur to put it in that place.

want the decimal to be to the right of the most signiciant decimal digit -> 8.3243, 0.0023, 1.234, NOT 2342.2342

if result not normalized (23423.2342), must do some shifting in the exponent and mantissa to make it so

slide examples have the decimal to the left of the most significant digit: .0110101

hidden bit: when bits encoded in memory, start with the 0 and the rest of the bits, assuming that a 1 comes before the 0 
- this bit is the most significant 1's bit

most significant 1's bit in a well known position

## Precision

A 32 bit machine can only do arithmetic with 32 bit numbers. Some double precision will be lost

Single: 23 bit fraction and 8 bit exponent

Double: 52 bit fration 11 bit exponent

exponent bias: add a bias value to the exponent to make all values positive

## Range

magnitude of nomralied fraction has absolute value in range 1/r < |f| < 1

all normalized numbers must have fraction > 1/2 because of hidden 1 bit

special representation needed for 0

exponent will experience overflow or underflow beyond a certain point

most formats use all 0's to represent 0

## Biased Exponents

advantages, sign bit ignored when comparing exponents

to multply floating point numbers, multiply fractions and add exponents
- these can be hardware parallelized

a zero may not actually be a 0 but extremely close to 0. To be a perfect 0, all bits in the number must be 0. 

## Implementation

floating point is more complicated by nature

can use same hardware structures as fixed point with some slight modifications and enhancements

## Floating Point Multiplicatoin

fraction of 2 operands are multiplied like fixed pt numbers and exponents are added

these two operations are done iwth parallel

exponent binary = exponent true value + bias

in fixed point multiplication, use double precision because the product can be larger than the bit widths of the 2 nums

normalization shifts the bits over so the hidden 1 is in its place


## Round off Schemes

ususally lose bits when mapping number ot 32 bit format

product of length 2m must be rounded to m digits

rouding needs to be performant, if not, then not worht it

### Truncation

Fast, no extra hardware required

poor accuracy

truncated value will always be less than orignal

max error: 2.99999 -> 2

### Rounding up

obtained by adding 0.1 base 2 (0.5 base 10) and truncating

max error when 2.5 -> 3

bias: when you hit 1/2, round up

### Round to nearest even

## IEEE Standard

denomralized: can store extra small numbers when exponent is 0; will not just be 1

### double

see slides for table details

### guard round sticky

sticky digit: like a guard digit (extra bit at the right)

if a 1 is shifted into the sticky digit, it will stay a 1 forever despite other operations on the data







