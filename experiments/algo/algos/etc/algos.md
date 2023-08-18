# Sorting algorithms

# Bubble sort

Bubble sort is a comparison algorithm.

On a list of size n, n passes are done.

During a pass, every number n is compared against his n + 1 and so on until
n + 1 becomes the rightmost list member.
If (n > n + 1), those number are swapped so n appears after n + 1.

The first pass touches every member of the list, but, as every pass sorts the
rightmost number at its correct place, the subsequent passes touches only
(every member - number of passes already done).

# Selection sort

Selection sort is a comparison algorithm.

On a list of size n, n passes are done.

During a pass, the smallest nb is searched for and swapped to the (pass)th
position of the list.

Each pass starts at the (pass)th position of the list as the (pass)th 
leftmost positions are always sorted.

# Insertion sort 

Selection sort is a comparison algorithm too.

On a list of size n, n passes are done.

The size of the "sorted zone" increase by one at every pass. So at the first
pass, only one element is touched, at the second, two elements... 

During a pass, the rightmost element of the "sorted zone" is compared with the
one that comes before. If the rightmost element is inferior, the twos are
swapped. This operation is repeated until the first element of the list is
eventually reached.

# Merge sort

Merge sort is a divide and conquer algorithm that also includes
comparisons.

As its algorithmic type suggest, any array of size n used as an input will go through two distinct phases.

In the first "divide" phase, the array of size n will be
recursively divided into 2 distinct arrays of sizes n/2 and
size - n/2 until each subarray have a size 1.

In the second "conquer" phase, these subarrays of size 1
will be merged 2 by 2 in the reversed order in which they have been splitted.

Each subarray is merged following those rules:
- Two "pointers" i and j track the two sub arrays. They start
at the beginning.
- The two values they are pointing at are compared
- The smallest is added to the merged array, and its pointer moves to the next one
- The latest operation is repeated until one sub array reaches its end.
- If one sub has reached its end before the other, the remaining values are added without comparison.

# Radix sort
