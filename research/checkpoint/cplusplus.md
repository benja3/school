# C++ Programming Reference

https://www.youtube.com/watch?v=Bt3zcJZIalk&list=PLHTh1InhhwT4TJaHBVWzvBOYhp27UO7mI

## Features

### General

the ```auto``` type can automatically assign a type to a variable

for each loop: for(int value : values)

Use delete to free memory associated with a pointer instead of free()


### I/O

cout << <string>;

### Iterators

https://cplusplus.com/reference/iterator/

object that has the ability to iterate through a range of elements

different classes contain iterator members

to get value, must dereference iterator

### Vectors

https://cplusplus.com/reference/vector/vector/

Dynamically resizable array

#include <vector>

syntax: vector<type> <name>;

Important Functions:
- front(): return front
- back()
- at(int index): return contents at index
- size()
- empty()
- capacity(): max number of items before resize
- push_back(): add to end
- pop_back(): remove from end and return
- clear(): remove all members
- swap(&vector x): swaps content of this vector with x

To iterate, can use standard for loop with integer index or 

Can index vector with []

### Smart Pointers

