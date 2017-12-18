/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:18:45 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/18 14:25:59 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_hex(t_print print, va_list argp)
{
	char			*value;
	unsigned long long	r;
	uintmax_t			j;

	if (IS_SET(J))
	{
		j = va_arg(argp, uintmax_t);
		value = ft_uint_base(j, 16, print.conv == x ? 'a' : 'A');
	}
	else
	{
		r = va_arg(argp, unsigned long);
		if (IS_SET(L))
			value = ft_long_base(r, 16, print.conv == x ? 'a' : 'A');
		else if (IS_SET(LL))
			value = ft_llong_base(r, 16, print.conv == x ? 'a' : 'A');
		else
			value = ft_base(r, 16, print.conv == x ? 'a' : 'A');

	}
	ft_pad_num(value, print);
}
