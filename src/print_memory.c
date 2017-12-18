/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 04:39:19 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/18 13:20:18 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					print_hex_mem(unsigned char *addr, int maj)
{
	size_t				i;
	static char			hex[] = "0123456789abcdef";
	static char			hex_maj[] = "0123456789ABCDEF";

	i = -1;
	while (++i < 64)
	{
		if (maj)
		{
			ft_putchar(hex_maj[(int)addr[i] / 16]);
			ft_putchar(hex_maj[(int)addr[i] % 16]);
		}
		else
		{
			ft_putchar(hex[(int)addr[i] / 16]);
			ft_putchar(hex[(int)addr[i] % 16]);
		}
		ft_putchar(' ');
	}
}
