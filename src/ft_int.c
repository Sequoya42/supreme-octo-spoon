/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:51:23 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/10 19:43:39 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Flags [ PADDING PRECISION MINUS PLUS]
*/
void			ft_int(t_print print, va_list argp)
{
	char		*value;

	value = ft_itoa(va_arg(argp, int));
	ft_pad(value, print);
	// int i = va_arg(argp, int);
	//
	// ft_putnbr(i);
	// ft_putchar('\n');
	// ft_pad(value, print);
}
