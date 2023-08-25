# Algorithm andidates - Radix sort

# Project Presentation

Push swap is an algorithmic project whose goal is to sort a stack of ints
[a] using and auxilliary stack [b] and a limited number of push_swap
instructions.

The limits varies according to the stack initial size:

- 3 numbers -> 3 instructions max.
- 5 numbers -> 12 instructions max.
- 100 numbers -> 700 instructions max.
- 500 numbers -> 5500 instructions max.

# Radix sort presentation

A non comparative sorting algorithm (does not rely on comparisons between numbers) algorithm that sorts elements (numbers...)

by repeatedly placing them into "buckets" representing their radix/base, namely the potential elements
(for numbers, digits 0-9...), used to represent them.

This bucketing process on a bucket of size (k) is repeated
length of the max number (d) times for every member of the list (n).

(subroutine sorting algorithm like counting sort, )

Complexity: O(d * (n + k)) where n is the number of elements in the input list,
d is the length of longest number in the list, k is the length 
(ex: 12345 has length 5). 

// (how to sort negative numbers?)

# Example

[158, 0, 13, 31, 7, 900]

-> [900, 0, 31, 13, 7, 158] (sorts 10**0)
[0	1	2	3	4	5	6	7	8	9] (same bucket)

-> [900, 0, 7, 13, 31, 158] (sorts 10**1)
[0	1	2	3	4	5	6	7	8	9] (same bucket)

-> [0, 7, 13, 31, 158, 900] (sorts 10**2)
[0	1	2	3	4	5	6	7	8	9] (same bucket)
