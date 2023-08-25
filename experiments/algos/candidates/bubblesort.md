# Algorithm candidates - Bubble sort

# Project Presentation

Push swap is an algorithmic project whose goal is to sort a stack of ints
[a] using and auxilliary stack [b] and a limited number of push_swap
instructions.

The limits varies according to the stack initial size:

- 3 numbers -> 3 instructions max.
- 5 numbers -> 12 instructions max.
- 100 numbers -> 700 instructions max.
- 500 numbers -> 5500 instructions max.

# Bubble sort presentation

Bubble sort is a comparison algorithm.

On a list of size n, n passes are done.

During a pass, every number n is compared against his n + 1 and so on until
n + 1 becomes the rightmost list member.

If (n > n + 1), those number are swapped so n appears after n + 1.

The first pass touches every member of the list, but, as every pass push the
most superior unsorted number at its correct place, the subsequent passes
touches only (every member - number of passes already done).

# Bubble sort adaptation

The core, the composants, the magic of bubble sort:
	- Iteration, roughly (n * (n / 2)) times
	- Comparison between one element and the one that comes after
	- Swapping between one element and the one that comes after

The goal: adaptating all these operations in the least amount of push swap
instructions.

## Iteration

### First variation

- [a] 1 2 3
(ra - to the top)
- [a] 2 3 1
(ra)
- [a] 3 1 2
(ra)
- [a] 1 2 3

### (*) Second variation

- [a] 1 2 3
(rra - to the bottom)
- [a] 3 1 2
(rra)
- [a] 2 3 1
(rra)
- [a] 1 2 3

### Third variation

- [a] 1 2 3 [b] *
(pb)
- [a] 2 3 [b] 1

### Which one cost less?

First or second, third requires 2x more iterations as the data 
has to come back to [a].

So first or second.

## Comparison

### First variation

- [a] 1 2 3 [b] *
(pb)
- [a] 2 3 [b] 1
comp(peek(a), peek(b))

### (*) Second variation

- [a] 1 2 3 [b] *
last_top = 1;
(ra - to the top)
- [a] 2 3 1 [b] *
comp(peek(a), last_top)

### third variation

- [a] 1 2 3 [b] *
last_top = 1;
(sa)
- [a] 2 1 3 [b] *
comp(peek(a), last_top)

### Which one cost less?

Both uses 1 operation. But the first one uses the second stack, which
implies that another pa instruction will be necessary to complete the
challenge...

So maybe the second one? It has also the benefit to include the cheapest
way to iterate on a stack.

## Swapping

- [a] 1 2 3 [b] *
(sa)

# Bubble sort for push_swap  

## Tools

- pushswap instructions
- size(b) size(a)
- isempty(a) isempty(b)
- max(b) max(a) min(b) min(a)
- peek(b) peek(a)

## Observations

- [a] and [b] are sorted when: [a] 1 2 3 [b] 3 2 1
- The last element of a stack can be easily accessed from the top 
via 1 rra/rrb/rrr instruction.

## First proposition

- Iteration with: (ra - to the top)
- comp: Use variable to store the last last_top combined with the last ra
instruction.
- swap if necessary

- [a] 15 3 -5 7 [b] *

while (++i < size):
	while (++j < size - i):
		last_top = peek(a)
		(rra)
		if (peak(a) > last_top): (sa)

-> [a] 3 7 15 -5 [b] *

ins: [
	rra ; rra ; rra sa ; rra ;
	rra ; rra ; rra
	rra ; rra ;
	rra ;] 

11 instructions. And a lot of useless ones...

(rra)
-> [a] -5 3 7 15 [b] *

### Problems

- Lots of useless instructions: the algo iterates on the stack (n * (n / 2))
times but it was not necessary at all.
	-> Maybe find a mechanism to check if the stack is sorted so we can break
	out of the algorithm when needed?

- Plus the list, although sorted, does not point to the minimum int at the
end...
	-> Maybe because of the differences between stack/list and the method
	used to iterate?
	-> With a mechanism type variables min; max, it would be possible
	to correct that... with extra rra/ra to set top to min at the end/

But won't go any further for now (21/08). 

I won't try to improve an O(n²) algorithm... and I want to test different ones...  