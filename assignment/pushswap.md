# Push_Swap


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

### What is a stack?

A stack is a LIFO data structure

A stack has two operations:
- `push(obj, stack) -> status (incl failure)`
- `pop(stack) -> obj (or null)`

`push` adds an obj `obj` to the top of the stack.
`pop` remove off the stack the obj that is on top of the stack.

### Implementation

How to implement a stack?

#### As a list?

- A list? Where is the top?

list[0]? Makes sense.

- Where's the bottom?

list[n - 1]?

##### How to push onto the stack?

list[0] becomes list[1]. list[1] becomes list[2] and so on...
list[0] host the new object.

##### How to pop off the stack?

list[0] disappears...
and list[1] becomes list[0]. list[2] becomes list[1] and so on...

##### So...

If I want to push/pop an item in a stack implemented as a list, I need to
move all items on the list before?

Isn't that INEFFICIENT AS [damn]? **Why traverse the list EVERY TIME I need**
**to do anything?**

##### Any problem?

- The size of the stack maybe?

But setting like 1024 slots by default should be enough. Even... 4096 if needed.

- The nb of elements there is in the stack right now?

Of course we can keep track of the nb of elements 

#### As a linked list?

- A linked list? Where is the top?

At the head? The node pointed at by the head? OK...

- Where's the bottom?

The last node of the linked list. Still OK.

##### How to push onto the stack?

Create a new node, make it point to the current head. Move the head to
its position.

Use something like `lstaddfront`.

##### How to pop off the stack?

Delete the node pointed by the head. Move head to the node pointed at by the
deleted node.

Use libft `lst` function `lstdelone` (and) more.

And that's it.

##### So...?

Stacks will be implemented as LINKED LISTS. 

The main reason is that stack operations like pushing/popping takes less
operations to perform when the stack is implemented as a linked list.

And it's always true for rotations that reasons I will not develop here.

##### Any problem?

Maybe there is a need to keep track the size of the stack for doing the
rotations operations, by example, or speeding up list/stack traversal...

