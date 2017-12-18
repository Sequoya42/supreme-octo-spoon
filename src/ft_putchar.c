/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:05:23 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/18 21:59:22 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_char(t_print print, va_list argp)
{
	char n;
	char		*value;

	(void)print;
	value = ft_memalloc(3);
	n = va_arg(argp, int);
	// ft_putchar(n);
	value[0] = n;
	ft_pad(value, print);
}
