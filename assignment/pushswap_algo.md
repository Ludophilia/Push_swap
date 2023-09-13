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

- For 100 and 500, a mix of quick sort + insertion sort? I've watched videos of
push swap solvers and read medium papers, this combination seems efficient
enough to score under 5500 for 500 nbs, and 700 for 100 numbers... We will see.

0. Pre optimisations: 
	- [x] Sort the position of the numbers; not the numbers directly. That can be
	used to speed up some operations. (ex: if you have found 0 or size - 1...)
	- [x] Store the push swap instructions in a buffer instead of writing them
	directly on stdout.

1. Pre sorting on stack b.
	- Define a pivot (large) and a sub pivot. Those numbers will be used to
	determine if a nb should be pushed to b and what position they should
	have on the stack. (nb < subpivot -> top b, nb > subpivot -> bottom b) 
	- Push onto stack b everything that is inferior (>) to the pivot
	- Repeat the operation with higher pivots until there is only
	3 nbs left in stack a. (those nbs should be the highest stackA->size - 1,
	stackA->size - 2, stackA->size - 3)

	The goal is roughly to create something like this in the stack b:
		- bucket 4 (ex: nbs from 83-103) [Turn #2t - Everything from 83 to 124, nb < pivot / 2, ]
		- bucket 2 (ex: nbs from 41-61) [Turn #1t - Everything from 41 to 82, nb < pivot / 2, ]
		- bucket 0 (ex: nbs from 0-19) [Turn #0t - Everything from 0 to 40, nb < pivot / 2, ]
		- bucket 1 (ex: nbs from 20-40) [Turn #0b - Everything from 0 to 40, nb >= pivot / 2]
		- bucket 3 (ex: nbs from 62-82) [Turn #1b - Everything from 41 to 82, nb < pivot / 2, ]

	It's more efficient than a design like the one below because while the buckets 
	have roughly the same size (20 nbs), the number of elements considered in stack
	a in every turn is twice the bucket size (40nbs), that means less rotations to
	find the correct numbers to push to b:
		- bucket 4 (nbs from 83-103) [Turn #4]
		- bucket 3 (nbs from 62-82) [Turn #3]
		- bucket 2 (nbs from 41-61) [Turn #2]
		- bucket 1 (nbs from 20-40) [Turn #1]
		- bucket 0 (nbs from 0-19) [Turn #0]

2. Sort those 3 numbers on stack a with the custom made 3 sorting algo.

3. Selection sort
	- At this point we have the highest numbers sorted in stack a. Why not
	**search stack b** for the nb that immediately comes before the one on
	**stack a's head**? We know it exists, because we are sorting ranks,
	not numbers...
		- It's possible however that this strategy costs too much rotations
		on B because the next lowest is too far away from the head...
		So what to do?
			- Normally it won't be too far thanks to chunking.

	- Why not use insertion sort then? We take the nb on **top on stack b**
	and **search/smart rotate stack a** to insert it into a.

	- The solution will certainly be an arbitration between selection and
	insertion sort. The one which costs the less wins...

	- One problem... It's easy with selection sort to stay within the bounds
	of the bucket, but with insertion sort?
		- I don't think insertion sort is a good idea as it disrupts the flow
		of selection sort. If the top of stack a is 110, and I look for 109,
		but it's too far, should I then put 98 that is on top of stack b?
		And what should I do next turn? Find 97?
		- One alternative approach would be to use the bottom of stack a to
		store those numbers.
			- [a] 102 103 104 105
			- [b] 98 97 96 ... 101

			- [a] 102 103 104 105
			- [b] 98 97 96 ... 101

	(We will come back with more experience...)

Each turn, there is an arbitration done between selection sort and insertion?

4. Post optimisations:
	- Write a subroutine that is capable of analysing instructions and 
	optimizing them by spotting the one that can be cancelled, the rotations
	r* r* that can be replaced by rr, the combinations that can be simplified.
