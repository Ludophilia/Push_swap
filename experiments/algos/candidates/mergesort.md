# Algorithm candidates - Merge sort

# Merge sort

Merge sort is a divide and conquer algorithm that also includes
comparisons.

As its algorithmic type suggest, any array of size n used as an input will go
through two distinct phases.

In the first "divide" phase, the array of size n will be
recursively divided into 2 distinct arrays of sizes n/2 and
size - n/2 until each subarray have a size 1.

In the second "conquer" phase, these subarrays of size 1
will be merged 2 by 2 in the reversed order in which they have been splitted.

Each subarray is merged following those rules:
- Two "pointers" i and j track the two sub arrays. They start
at the beginning.
- The two values they are pointing at are compared
- The smallest is added to the merged array, and its pointer moves to the 
next one
- The latest operation is repeated until one sub array reaches its end.
- If one sub has reached its end before the other, the remaining values are
added without comparison.
