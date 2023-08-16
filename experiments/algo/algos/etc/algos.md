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
