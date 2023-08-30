# Tests

## Special cases

An already ordered list:
`./push_swap 1 2 3 4 5`

A list comprised of 1 number
`./push_swap 1`

## Error cases

No list:
`./push_swap`
-> Program displays nothing and just terminates

A list comprised of non numbers:
`./push_swap 1 2 trois 4 5`
`./push_swap "" "" "" ""`
`./push_swap ""`
`./push_swap a b c`
`./push_swap 420 x y`
`./push_swap "help me nigga"`

A list with numbers that are not ints:
`./push_swap -2147483649 58 -69 420`

A list with duplicate numbers:
`./push_swap -6 -6 -6`

-------------------------

WTF is this ?

`./push_swap "1 2 3"`