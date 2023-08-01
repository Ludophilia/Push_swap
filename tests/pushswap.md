# Pushswap

# What is this ?

`./push_swap <integers>`

push_swap is a program which takes as arguments a list of integers, ordered
or not.

Those args are then stored on a stack `a` with the first arg is on top, last
arg is on the bottom, and sorted with the help of a second stack `b`.

The algorithm used to sort the stack `a` should exclusively use the following
instructions:

- push instructions: `pa`, `pb`
- swap instructions: `sa`, `sb`, `ss`
- rotate instructions: `ra`, `rb`, `rr`
- reverse rotate instructions: `rra`, `rrb`, `rrr`

The instructions used to sort the stack `a` filled with the `<integers>` will
be printed on stdout.
Beware the stack should be sorted in less than 8 instructions (12 in 
the assignment) whatever its content.

# How to do that?

## The Stack Problem

- [ ] How to implement a stack? Do I really need one? Can't I just use lists?

## The Algorithm Problem

- [o] Sorting algorithms? Should I use one? Only one?

	"Trier des valeurs c’est simple. Les trier le plus vite possible, c’est 
	moins simple vu que, d’une configuration des entiers à trier à une autre,
	un même algorithme de tri n’est pas forcément le plus efficace."
	So, according to the assigment, more than one will be used

- [ ] Does standard sorting algorithms (qsort, bsort...) works on those
stacks, how to adapt them to the language pushswap if needed? Start with a
simple one to see.

# Bonus

`./checker <integers>`

The checker is a fairly simple program. It takes as an argument the same list 
of integers than push_swap.

The program reads the push_swap instructions on its `stdin` (0), executes then
on the stacks `a` `b`, and then check if stack `a` is sorted (and the stack
`b` is empty of course).

Of course **the special cases** and **the errors** should be checked as well...

That's it, really, not a big deal. It more a matter of rigor than anything
else...

# Tests

## Special cases

An already ordered list:
`./push_swap 1 2 3 4 5`

A list comprised of 1 number
`./push_swap 1`

## Error cases

A list comprised of non numbers:
`./push_swap 1 2 trois 4 5`
`./push_swap "" "" "" ""`
`./push_swap a b c`

A list with numbers that are not ints:
`./push_swap -2147483649 58 -69 420`

A list with duplicate numbers:
`./push_swap -6 -6 -6`
