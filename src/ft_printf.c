#include "libftprintf.h"
/*
   The z modifier, when applied to a d or i conversion, indicates that the argument
    is of a signed type equivalent in size to a size_t.

 #				For o conversions, the precision of the number is increased
                                to force the first character of the output string to a zero

   `0' (zero)   Zero padding.  For all conversions except n, the converted value is padded on the left with zeros rather than blanks.
   If a precision is given with a numeric conversion (d, i, o, u, i, x, and X), the 0 flag is ignored.


   -    A - overrides a 0 if both are given.

   ` ' (space)  A blank should be left before a positive number produced by a signed conversion (a, A, d, e, E, f, F, g, G, or i).

         `+'          A sign must always be placed before a number produced by a signed conversion.  A + overrides a space if both are used.

   Modifier          d, i           o, u, x, X            n

   hh                signed char    unsigned char         signed char *
   h                 short          unsigned short        short *
   l (ell)           long           unsigned long         long *
   ll (ell ell)      long long      unsigned long long    long long *
   j                 intmax_t       uintmax_t             intmax_t *
   z                 (see note)     size_t                (see note)
 */

// static t_fptr				g_operator[CONV_LEN] =
// {
//      NULL,
//      &ft_string,
//      &ft_long_string, //  Treated as s with the l (ell) modifier
//      &ft_pointer, // The void * pointer argument is printed in hexadecimal (as if by `%#x' or `%#lx')
//      &ft_int,
//      &ft_long_int,
//      &ft_int,
//      &ft_unsigned_octal,
//      &ft_long_unsigned_octal,
//      &ft_unsigned_decimal,
//      &ft_long_unsigned_decimal,
//      &ft_small_hex,
//      &ft_big_hex,
//      &ft_unsigned_char, // The int argument is converted to an unsigned char
//      &ft_long_char // Treated as c with the l (ell) modifier,
// };

void				ft_printf(char * restrict s, ...)
{
	int				i;
	char			*t;
	va_list			argp;
	t_print			print;

	i = 0;
	t = s;
	va_start(argp, s);
	while (t[i])
	{
		if (t[i] != '%')
			ft_putchar(t[i]);
		else if (t[i] == '%' && t[i + 1] == '%')
		{
			ft_putchar(t[i]);
			i++;
		}
		else
		{
			print = parse_format(t, i);
			// g_operator(print.conv)(print, argp);
		}
		i++;
	}
	va_end(argp);
}
