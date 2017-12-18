/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:30:49 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/18 21:37:14 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** flags: [MINUS PADDING PRECISION]
*/

void			ft_string(t_print print, va_list argp)
{
	char		*value;

	value = va_arg(argp, char *);
	if (!value)
		value = "(null)";
	ft_pad(value, print);
}
