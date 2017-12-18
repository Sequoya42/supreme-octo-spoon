/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:51:23 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/18 22:35:26 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Flags [ SHARP PADDING PRECISION MINUS PLUS l ll]
*/

static char		*choose_type(t_print print, va_list argp)
{
	char		*value;

	if (print.conv == U || (print.conv == u && IS_SET(L)))
		value = ft_unsigned_itoa(ARG(unsigned long));
	else if (print.conv == u)
		value = ft_unsigned_itoa(ARG(unsigned int));
	else if (print.conv == d && IS_SET(L))
		value = ft_itoa(ARG(long));
	else if (print.conv == d && IS_SET(LL))
		value = ft_itoa(ARG(long long));
	else
		value = ft_itoa(ARG(int));
	return (value);
}

void			ft_int(t_print print, va_list argp)
{
	char		*value;

	if (print.conv == M)
		value = "%";
	else
		value = choose_type(print, argp);
	if (IS_SET(PLUS) && (print.conv == d || print.conv == i)
	    && ft_atoi(value) >= 0)
		value = ft_strjoin("+", value);
	else if (value[0] != '-' && IS_SET(SPACE) &&
		 (print.conv == d || print.conv == i))
		value = ft_strjoin(" ", value);
	ft_pad_num(value, print);
}
