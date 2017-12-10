/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:30:49 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/10 18:54:23 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** flags: [MINUS PADDING PRECISION]
*/

void			ft_string(t_print print, va_list argp)
{
	char		*value;

	(void)print;
	value = va_arg(argp, char *);
	ft_pad(value, print);
}
