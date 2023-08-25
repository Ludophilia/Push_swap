# Algorithm candidates - Selection sort


# Selection sort

Selection sort is a comparison algorithm.

On a list of size n, n passes are done.

During a pass, the smallest nb is searched for and swapped to the (pass)th
position of the list.

Each pass starts at the (pass)th position of the list as the (pass)th 
leftmost positions are always sorted.

# Abstract

- Push every element from [a] to [b].
	- Update max_nb;
- Seek max_nb in [b] and (pa)
- Seek again max_nb (i < size) in [b] and (pa)
- repeat until [b] is empty

Looks very costly, especially the pa pa pa ; pb pb pb.
The iteration/searching part too.

It's a O(n²) algorithm. For every item, the whole stack is traversed.

Let's look for something better...


