# 7 - Pushswap

# First steps

- [x] Read the subject
	- [x] Search what you don't know...
	- [x] Repeat until the subject and its goals becomes very familiar?

# Foundations

- [x] Find how to implement a stack and ACTUALLY implement one. 
- [x] Implement the basic operations of a stack: pop/push.
- [x] Implement the basic operations that the push_swap game requires
- [x] Implement the stack init from argv. Mind error cases...

# What algorithm to choose?

- [x] Familiarize yourself with the standard sorting algorithms: bubble sort,
selection sort, insertion sort, heapsort, quick sort, merge sort... Learn 
about their principe, their complexity, and so one...
- [x] Implement most of these algorithms to deepen your understanding
- [x] Now that you have implemented them and understand them better, do you
have any idea about which one to choose and how to adapt it to the language
pushswap? Some ideas and observations: 
	- Iteration is done with (rotate/rev rotate) instructions and stack size.
	- Swapping is done with swap instruction.
	- Prefer O(1) to O(n) to O(n * logn)...

# Project core

- [x] Implement a method to substitute every nb in the stack by their rank.
[214, 3, -42] should become [2, 1, 0]...

- [x] Change the way the instructions are printed on stdout. 
	- [x] Create a linked list responsible of storing those instructions

- [x] Implement a is_sorted method.

- [x] Create an algorithm for sorting 3 numbers... in at most than 2
instructions.

- [x] Manage the case 1 and 2 numbers. (Because it will happen too.)

- [x] Create an algorithm for sorting 5 numbers... in at most 11 instructions.
	- [x] Adapt your sort_comp_case2 so it can sort in reverse?
	- [x] Manage the case 4 numbers. (Because it will happen too.)

- [x] Create an algorithm for sorting 100 numbers... in at most 699
instructions.

- [x] Create an algorithm for sorting 500 numbers... in at most 5499
instructions.
- [o] Optimize: 
	- [x] Choose a good pivot
	- [x] Compress instrucs : rb+ra == rr ; rrb+rra == rrr ; sa + sb == ss
	- [x] Try a sorting method different from selection sort
		for the conquer phase.
		- [x] Try a more cost effective insertion sort. 
	- [c] Use the bottom of stack a
	- [c] Compress instructions even more. ra + pb + rra -> sa + pb

# Bonus (or pushswap remix)

- [o] Let's do the checker, in roughly 3 days... 

## Argument management (same as push_swap)

- A checker `checker` takes the same arguments as the program push_swap.
	- [x] If no args, the program stops and displays nothing.
	- [x] If the list is incorrect in the way the list for push_swap is, 
	return an error.  

## Instrs acquisition

- [ ] The checker wait for instructions on its stdin (0), 
- [ ] Analyse their conformity ("valid instr? \n terminated?")
- [ ] Store them in a linked list

How to know if there is no more instrs? Waiting for a SIGPIPE or something that
will close the pipe or the stream like EOF (ctrl + d)
-> Don't need to manage this, just while read or something like this...

## Instrs execution

- [x] Once the instrs are here, init the stacks...
- [ ] ...execute the instrs

## Final check and result

- [ ] Check that b is empty and a is sorted. OK if so, KO otherwise.
