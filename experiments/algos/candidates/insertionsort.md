# Algorithm andidates - Insertion sort

# Project Presentation

Push swap is an algorithmic project whose goal is to sort a stack of ints
[a] using and auxilliary stack [b] and a limited number of push_swap
instructions.

The limits varies according to the stack initial size:

- 3 numbers -> 3 instructions max.
- 5 numbers -> 12 instructions max.
- 100 numbers -> 700 instructions max.
- 500 numbers -> 5500 instructions max.

# Insertion sort presentation

Insertion sort is a comparison algorithm too.

On a list of size n, n passes are done.

The size of the "sorted zone" increase by one at every pass. So at the first
pass, only one element is touched, at the second, two elements... 

During a pass, the rightmost element of the "sorted zone" is compared with the
one that comes before. If the rightmost element is inferior, the twos are
swapped. This operation is repeated until the first element of the list is
eventually reached.

# Insertion sort adaptation

The core, the composants, the magic of insertion sort:
	- Iteration, roughly (n * (n / 4)) times
	- Comparison, between the right most element of the sorted zone and
	everything that comes before...
	- Swapping, between the rightmost element and the ones that comes before,
	if necessary.
	- Random access, as at every new pass, it's the pass th position that's
	accessed.

The goal: adaptating all these operations in the least amount of push swap
instructions.

## Iteration

### Second variation

- [a] 1 2 3
(rra - to the bottom)
- [a] 3 1 2
(rra)
- [a] 2 3 1
(rra)
- [a] 1 2 3

### (*) Third variation

- [a] 1 2 3 [b] *
(pb)
- [a] 2 3 [b] 1

The third one, as insertion sort should start from a empty/sorted array.

## Comparison

### (*) third variation

- [a] 1 2 3 [b] *
last_top = 1;
(sa)
- [a] 2 1 3 [b] *
comp(peek(a), last_top)

Its the third one for sure, because it's the only one that's compatible with
the iteration method i've chosen.

## Swapping

## (*) First variation

- [a] 1 2 3 [b] *
(sa)

## Second variation

- [a] 1 2 3 [b] *
(pb)
- [a] 2 3 [b] 1
(ra, pa, rra)
- [a] 2 1 3 [b] *

(This is complex af)

# Insertion sort for push_swap

# Tools

- pushswap instructions
- size(b) size(a)
- isempty(a) isempty(b)
- max(b) max(a) min(b) min(a)
- peek(b) peek(a)

## Observations

- [a] and [b] are sorted when: [a] 1 2 3 [b] 3 2 1
- The last element of a stack can be easily accessed from the top 
via 1 rra/rrb/rrr instruction.

- An interesting optimatisation consists of tracking the minimum and maximum
nb in [b] and put the new nb on top or at the bottom of the max/min.

# Proposition 1

-> [a] 2 1 3 6 5 8 [b] * 

while (++i < size)
	if (peek(b) == NULL || (peek(a) > peek(b) && peek(b) == max_b))
		(pb)
	else
		if (size(b) == 1)
			(pb) (rb)
		else if (peek(a) > peek(b))
			while (peek(b) != max(b))
				(rrb)
		else
			while (peek(a) < peek(b))
				(rb)
			(pb)
	if (peek(b) > max_b)
		max_b = peek(b)

while (peek(b) != max_b)
	(rrb)

while (peek(b))
	(pa)

-> [a] * [b] 8 6 5 3 2 1
max_b = 8

[pb ; pb rb ; pb ; pb ; rb pb ; rrb pb ;]
[pa pa pa pa pa pa;]

15/12 instructions. (Not terrible)

# Proposition 2

- An interesting optimatisation consists of tracking the minimum and maximum
nb in [b] and put the new nb on top or at the bottom of the max/min.

