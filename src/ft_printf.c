/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:30:08 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/12 17:18:03 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_fptr				g_operator[CONV_LEN] =
{
	&ft_string,
	&ft_string,
	&ft_pointer,
	&ft_int,
	&ft_int,
	&ft_int,
	&ft_octal,
	&ft_octal,
	&ft_int,
	&ft_int,
	&ft_hex,
	&ft_hex,
	&ft_int,
	&ft_int,
	&ft_int,
};

int					ft_printf(char *restrict s, ...)
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
