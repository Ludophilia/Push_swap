# Algorithm candidates - Counting sort

# Project Presentation

Push swap is an algorithmic project whose goal is to sort a stack of ints
[a] using and auxilliary stack [b] and a limited number of push_swap
instructions.

The limits varies according to the stack initial size:

- 3 numbers -> 3 instructions max.
- 5 numbers -> 12 instructions max.
- 100 numbers -> 700 instructions max.
- 500 numbers -> 5500 instructions max.

# Counting sort presentation

Counting sort is a non comparative sorting algorithm that works on
**non-negative integer arrays** and relies on operations done an auxilliary frequency/position array of size of the max number stored in the input 
buffer/array.

This positional array contains all possible numbers up to the max number in the
input buffer/array. When iterating on the input array, the position on the
frequency array corresponding to the number is incremented by one.

At the end of the process, the frequency array is transformed into a positional
array by adding to the current frequency the sum of every frequency that
came before.

After that, two techniques can be performed to construct the new array:

- 1. Iterating on the input array from the end. In this case, the positional
array represent the position (not the index, for that we should substract one)
of the last occurence of the number
and will be decremented every time this number is added to the new array.

- 2. Iterating on the input array from the beginning. The values in the position
array are then  shifted to the right (with a 0 at index 0) represent the
starting index of a particular number. Every time a number is added to the new
arr, it's starting index is incremented by one.

Complexity: O(n + k) where n is the size of the input array and k, the size of
the frequency/positional array.

# Example, with the first technique.

-> [2, 2, 1, 4, 2] - Input array to be sorted.

[0 1 3 0 1] - frequency array of size max(input) where the index represent a 
potential num in the list. The num indicates how much time the number
represented by the index appears in the input array. Here, 0 appears 0 times, 
1, 1 time, 2, 3 times...

[0 1 4 4 5] - The frequency array is transformed to a positionnal array
where every number indicate the last position (not index) of the associated
number.

-> [* * * * *] - A new array is constructed by iterating reversely over the
original unsorted one. 

[0 0 1 4 4] - Updated positional array

-> [1 2 3 2 4] - freq_arr[input_arr[i]]. The position of the number is searched
in the positional array created before and converted into an index by removing
one to it. Each time a number is inserted in the new array, its last position
in the position array is decremented by one..

# Problems

The complexity of counting sort is O(n + k). 
- k has the size of highest number in the input buffer. If k is a big number
like let's say 2147483647, the positional array size will be 2147483647 + 1.
This shit will be a nightmare to iterate on... and I am talking from 
experience here.

k has to be as small as possible.

# Counting sort adaptation
