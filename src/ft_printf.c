/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:30:08 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/11 18:05:23 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static t_fptr				g_operator[CONV_LEN] =
{
	&ft_string, //s
	&ft_string, //S //  Treated as s with the l (ell) modifier
	&ft_pointer, //p // The void * pointer argument is printed in hexadecimal (as if by `%#x' or `%#lx')
	&ft_int,// d
	&ft_int, // D //long_int
	&ft_int, // i
	&ft_octal, //o //  &ft_unsigned_octal,
	&ft_octal, //O //  &ft_long_unsigned_octal,
	&ft_int, //u // &ft_unsigned_decimal,
	&ft_int, //U // &ft_long_unsigned_decimal,
	&ft_hex, //x //  &ft_small_hex,
	&ft_hex, //X // &ft_big_hex,
	&ft_int, //c // &ft_unsigned_char, // The int argument is converted to an unsigned char
	&ft_int, //C // &ft_long_char // Treated as c with the l (ell) modifier,
};

int				ft_printf(char * restrict s, ...)
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
		if (t[i] != '%' && counter(1))
			ft_putchar(t[i]);
		else if (t[i] == '%' && t[i + 1] == '%' && counter(1))
			ft_putchar(t[i++]);
		else
		{
			print = parse_format(t, i);
			i = print.length;
			g_operator[print.conv](print, argp);
		}
		i++;
	}
	va_end(argp);
	return (counter(0));
}
