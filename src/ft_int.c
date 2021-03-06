/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:51:23 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/19 15:59:02 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Flags [ SHARP PADDING PRECISION MINUS PLUS l ll]
*/

static char		*choose_basic(t_print print, va_list argp)
{
	if (IS_SET(L))
		return (ft_itoa(ARG(long)));
	else if (IS_SET(LL))
		return (ft_itoa(ARG(long long)));
	else if (IS_SET(H))
		return (ft_itoa((short)ARG(int)));
	else if (IS_SET(HH))
		return (ft_itoa((signed char)ARG(int)));
	else if (IS_SET(J))
		return (ft_itoa((intmax_t)ARG(intmax_t)));
	else if (IS_SET(Z))
		return (ft_itoa((long)ARG(int*)));
	else
		return (ft_itoa(ARG(int)));
}


static char		*choose_type(t_print print, va_list argp)
{
	char		*value;

	if (print.conv == U || (print.conv == u && IS_SET(L)))
		value = ft_unsigned_itoa(ARG(unsigned long));
	else if (print.conv == U || (print.conv == u && IS_SET(LL)))
		value = ft_unsigned_itoa(ARG(unsigned long long));
	else if (print.conv == U || (print.conv == u && IS_SET(J)))
		value = ft_unsigned_itoa(ARG(uintmax_t));
	else if (print.conv == u)
		value = ft_unsigned_itoa(ARG(unsigned int));
	else if ((print.conv == u) && IS_SET(H))
		value = ft_unsigned_itoa((unsigned short)ARG(int));
	else if ((print.conv == u) && IS_SET(HH))
		value = ft_unsigned_itoa((unsigned char)ARG(int));
	else if (print.conv == d || print.conv == i)
		value = choose_basic(print, argp);
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
	else if (value[0] != '-' && IS_SET(SPACE) && PRE < (int)ft_strlen(value) &&
		 (print.conv == d || print.conv == i))
		value = ft_strjoin(" ", value);
	ft_pad_num(value, print);
}
