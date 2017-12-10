/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 04:39:19 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/10 21:26:49 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					print_hex_mem(unsigned char *addr, int maj)
{
	size_t				   i;
	static char			   hex[] = "0123456789abcdef";
	static char			   hexMaj[] = "0123456789ABCDEF";

	i = -1;
	while (++i < 64)
	{
		if (maj)
		{
			ft_putchar(hexMaj[(int)addr[i] / 16]);
			ft_putchar(hexMaj[(int)addr[i] % 16]);
		}
		else
		{
			ft_putchar(hex[(int)addr[i] / 16]);
			ft_putchar(hex[(int)addr[i] % 16]);
		}
		ft_putchar(' ');
	}
}

// void					print_raw_mem(unsigned char *addr)
// {
//      size_t				i;
//
//      i = -1;
//      while (++i < 16)
//      {
//              if (addr[i] > 31 && addr[i] < 127)
//                      ft_putchar(addr[i]);
//              else
//                      ft_putchar('.');
//      }
// }

char					*print_adrr(int i, int base)
{
	unsigned int		j;
	unsigned int		k;
	char				*ret;
	char				*r;

	j = 0;
	k = 0;
	ret = ft_strnew(64);
	r = ft_base(i, base);
	ret[k++] = '0';
	ret[k++] = base == 16 ? 'x' : 'o';
	while (j++ < (4 - ft_strlen(r)))
		ret[k++] = '0';
	j = 0;
	while (r[j])
		ret[k++] = r[j++];
	return (ret);
}
//
// void					print_memory(const void *addr, size_t size)
// {
//      size_t			i;
//
//      i = 0;
//      while (size >= 64)
//      {
//              print_adrr(i);
//              print_hex_mem((unsigned char*)(addr + i), 0);
//              ft_putchar('\n');
//              size -= 64;
//              i += 64;
//      }
// }
