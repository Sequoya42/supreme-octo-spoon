The z modifier, when applied to a d or i conversion, indicates that the argument
is of a signed type equivalent in size to a size_t.

For o conversions, the precision of the number is increased

to force the first character of the output string to a zero

```
`0' (zero) Zero padding. For all conversions except n, the converted value is padded on the left with zeros rather than blanks.
If a precision is given with a numeric conversion (d, i, o, u, i, x, and X), the 0 flag is ignored.

* A - overrides a 0 if both are given.

` ' (space) A blank should be left before a positive number produced by a signed conversion (a, A, d, e, E, f, F, g, G, or i).

`+' A sign must always be placed before a number produced by a signed conversion. A + overrides a space if both are used.

Modifier d, i o, u, x, X n
```

hh signed char unsigned char signed char _
h short unsigned short short _
l (ell) long unsigned long long _
ll (ell ell) long long unsigned long long long long _
j intmax_t uintmax_t intmax_t \*
z (see note) size_t (see note)
