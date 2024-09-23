# Fast Multipliers

## Booth Recoding

when there are a lot of 1's, do a lot of additions

when there a lot of 0's just shift for each instead of add

00011110 -> 00 +1 000 - 1 0

for the -1, subtract the multiplier

table: set up all possible values for bits

2^0 2^-1    B
0   0       0
0   1       +1
1   0       -1
1   1       0

0 1 represent the left most 1 in a string of 1's

1 0 is the right most end of the string

slide down the multiplier with a bit width of 2 and compare the two bit words to the table entries


