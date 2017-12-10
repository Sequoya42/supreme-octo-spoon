/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:18:45 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/10 21:44:51 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_hex(t_print print, va_list argp)
{
	char		*value;
	int r;

	r = va_arg(argp, unsigned int);
	value = ft_base(r, 16);
	ft_pad(value, print);
}
