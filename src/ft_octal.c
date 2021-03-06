/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:45:44 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/18 14:19:03 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					ft_octal(t_print print, va_list argp)
{
	char				*value;
	unsigned long		r;

	if (print.conv == O || IS_SET(L))
		r = va_arg(argp, unsigned long);
	else if (IS_SET(LL))
		r = va_arg(argp, unsigned long long);
	else
		r = va_arg(argp, unsigned int);
	value = ft_base(r, 8, 'a');
	ft_pad_num(value, print);
}
