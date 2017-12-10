/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:18:45 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/10 19:19:28 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_hex(t_print print, va_list argp)
{
	char		*value;

	value = ft_itoa(va_arg(argp, int));
	ft_pad(value, print);
}
