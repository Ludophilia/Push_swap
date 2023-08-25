# Algorithm candidates - Bucket sort

# Project Presentation

Push swap is an algorithmic project whose goal is to sort a stack of ints
[a] using and auxilliary stack [b] and a limited number of push_swap
instructions.

The limits varies according to the stack initial size:

- 3 numbers -> 3 instructions max.
- 5 numbers -> 12 instructions max.
- 100 numbers -> 700 instructions max.
- 500 numbers -> 5500 instructions max.

# Bucket sort presentation

[24/08 - edit please]

A sorting algorithm that relies on "buckets" to sort data.
A bucket is a buffer (list, linked list...) that stores elements that 
are within a certain interval. (ex: 0-9, 10-19, 20-29...) 

- A list (or buffer) of n elements is traversed.
- Each element is added to its corresponding bucket (ex: 7 goes to 0-9)
- Each bucket is sorted using bucket sort recursively or an auxilliary 
sorting algorithm like insertion sort.
- Each bucket is traversed in the right order to gather every sorted element
and put them in a new or the original array.

Complexity: O(n + n²/k +  k) -> O(n²) (case where every element is in one
bucket)
