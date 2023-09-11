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

- [x] Create an algorithm for sorting 3 numbers... in less than 3 instructions.

- [x] Manage the case 1 and 2 numbers. (Because it will happen too.)

- [x] Create an algorithm for sorting 5 numbers... in less than 12 instructions.
	- [x] Adapt your sort_comp_case2 so it can sort in reverse?
	- [x] Manage the case 4 numbers. (Because it will happen too.)

- [ ] Create an algorithm for sorting 100 numbers... in less than 700
instructions.

- [ ] Create an algorithm for sorting 500 numbers... in less than 5500
instructions.