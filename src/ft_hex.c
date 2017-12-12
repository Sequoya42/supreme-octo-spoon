/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:18:45 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/12 18:51:44 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_hex(t_print print, va_list argp)
{
	char		*value;
	int			r;

	if (print.conv == X || print.conv == L)
		r = va_arg(argp, long);
	value = ft_base(r, 16, print.conv == x ? 'a' : 'A');
	ft_pad(value, print);
}
