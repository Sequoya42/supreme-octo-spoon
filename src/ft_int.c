/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:51:23 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/11 01:58:49 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Flags [ PADDING PRECISION MINUS PLUS]
*/
void			ft_int(t_print print, va_list argp)
{
	char		*value;

	if (print.conv == u || print.conv == U)
		value = ft_unsigned_itoa(va_arg(argp, unsigned int));
	else
		value = ft_itoa(va_arg(argp, int));
	ft_pad(value, print);
}
