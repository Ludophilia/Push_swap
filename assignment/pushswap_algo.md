# Push Swap - The Algorithm Problem

# What is this ?

`./push_swap <integers>`

push_swap is a program which takes as arguments a list of integers, ordered
or not.

Those args are then stored on a stack `a` with the first arg is on top, last
arg is on the bottom, and sorted with the help of a second stack `b`.

The algorithm used to sort the stack `a` should exclusively use the following
instructions:

- push instructions: `pa`, `pb`
- swap instructions: `sa`, `sb`, `ss`
- rotate instructions: `ra`, `rb`, `rr`
- reverse rotate instructions: `rra`, `rrb`, `rrr`

The instructions used to sort the stack `a` filled with the `<integers>` will
be printed on stdout.
Beware the stack should be sorted in less than 8 instructions (12 in 
the assignment) whatever its content.

# Project Presentation

Push swap is an algorithmic project whose goal is to sort a stack of ints
[a] using and auxilliary stack [b] and a limited number of push_swap
instructions.

The limits varies according to the stack initial size:

- 3 numbers -> 3 instructions max.
- 5 numbers -> 12 instructions max.
- 100 numbers -> 700 instructions max.
- 500 numbers -> 5500 instructions max.

## Optimization techniques

- A different aglo for sorting 3, 5, 100 and 500 numbers?

- Choose an algorithm or algorithms with the lowest time complexity.

- Work on indexes instead of raw numbers...  [0, 1, 7, -27, -1, 2147483647]
becomes [2, 3, 4, 0, 1, 5].

- Leave 3 or 5 nbs in the stack... and use the custom made algo to sort 3
or 5 elements.

- Store the instructions in a buffer before writing them on stdout. That way
they can be optimized further: rb ra could be written rr for example, and
operations that cancel themselves (like ra + rra, sa + sa...) can be
removed. (Also... ra + pb + rra = sa + pb).

- Calculate different possible moves and choose the cheapest one to execute.
- Maybe you'll need to index the elements of the stack?

- Use the top and the bottom of the stack. The top and the bottom can 
communicate very easily thanks to rotate/reverse rotate instructions.

- Use chuncking: instead on working on 100 elements, works only on 20,
5 times, 50, 2 times.

- Calculate the median in the stack for chuncking, among others...

- Violate the stack data structure: your program have to output push swap
instructions, that does not mean you have to perfectly respect the stack
limitations while computing the cheapest move by example.

- Check what if the stack is already sorted. Do nothing in this case...

## Algorithmic candidate - 2 numbers

### Goal

2 numbers in less than 1 instructions
-> target: 01

### Cases

2 permutations of 2 numbers, so 2 possibilities

0 1 // [Already sorted] (min max)
1 0 // sa (max min)

## Algorithmic candidate - 3 numbers

### Goal

3 numbers in less than 3 instructions
-> target: 012

### Cases

3 permutations of 3 numbers, so 6 possibilities

0 1 2 // [Already sorted] (min mid max)
0 2 1 // rra sa (min max mid)

1 2 0 // rra (mid max min)
1 0 2 // sa (mid min max)

2 0 1 // ra (max min mid)
2 1 0 // sa rra (max mid min)

### Logic

What should be used for the logic?

- Check min, max, mid.
- Do a different thing according to the position of min/max in
stack.

## Algorithmic candidate - 5 numbers

### Goal

5 numbers in less than 12 instructions
-> target: 0 1 2 3 4

### Cases

5 permutations of 5 numbers, so 120 possibilities (oof)

1 2 3 4 5 (sorted)
1 2 3 5 4

1 2 4 3 5
1 2 4 5 3

1 2 5 4 3
1 2 5 3 4

2 1 3 4 5
2 1 3 5 4

2 1 4 3 5
2 1 4 5 3

2 1 5 4 3
2 1 5 3 4

(...) (I won't list them all, you serious or what?)

### Logic

[a] 4 3 2 1 5 [b] *

- push 2 nbs out of stack a
-> [a] 2 1 5 [b] 3 4
(pa) (pa) | 2 max

- sort them individually (b in reverse)
-> [a] 1 2 5 [b] 4 3
(sa) | 2 max + (sb) | 1 max (ss opti possible)

- insertion sort
-> [a] 1 2 5 [b] 4 3
(rra)
-> [a] 5 1 2 [b] 4 3 (peek(a) > peek(b))
 (pa) (pa)
-> [a] 3 4 5 1 2 [b] *

- rotate till minimum (0 for me)
-> [a] 1 2 3 4 5 [b] *
(rra) (rra)

9 / 12 instructions in this case

## Algorithmic candidates - 100/500 numbers

PROPOSITION 1

- Do nothing if the stack is already sorted.

- A custom algo for 3 nbs. 3 instructions max.

- A custom for 5 that relies on the one used for sorting 3 numbers. 12 
instructions max.

- For 100 and 500, a mix of quick sort + insertion sort? I've watched videos of
push swap solvers and read medium papers, this combination seems efficient
enough to score under 5500 for 500 nbs, and 700 for 100 numbers... We will see.

Two phases:

0. Pre optimisations: 
	- Sort the position of the numbers; not the numbers directly. That can be
	used to speed up some operations. (ex: if you have found 0 or size - 1...)
	- Store the push swap instructions in a buffer instead of writing them
	directly on stdout.

1. Pre sorting on stack b.
	- define a pivot (and a sub pivot). Those numbers will be used to determine
	if a nb should be pushed to b and what position they should
	have on the stack. (> sub nb -> bottom b, < sub nb -> top b) 
	- Push onto stack b everything that is > to the pivot
	- repeat the operation with higher pivots until there is only
	3 or 5 nbs left in stack a.
 
1.5. Sort those 3-5 numbers with the custom made 3 or 5 sorting algo.

2. Insertion sort from stack b to stack a. 
	- Take the number on top on stack b and push it to stack a if inferior 
	to the one on top on a, otherwise rotate a to place it to its correct
	position. It shouldnt cost to much as phase 1. made the nbs very close to
	each other.

3. Post optimisations:
	- Write a subroutine that is capable of analysing instructions and 
	optimizing them by spotting the one that can be cancelled, the rotations
	r* r* that can be replaced by rr, the combinations that can be simplified.
