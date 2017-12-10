/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:16:24 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/10 21:40:43 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** flags: [PADDING MINUS]
*/
void			ft_pointer(t_print print, va_list argp)
{
	char		*value;
	long r;

	r = va_arg(argp, long);
	value = ft_strjoin("0x", ft_base(r, 16));
	ft_pad(value, print);
}
