/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 21:59:40 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/10 21:40:10 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char							*ft_base(long n, int b)
{
	char						*ret;
	char						*r;
	int							i;
	int							j;

	ret = ft_memalloc(128);
	r = ft_memalloc(128);
	j = 0;
	i = 0;
	while (n)
	{
		if (n % b < 10)
			ret[i++] = (n % b) + 48;
		else
			ret[i++] = (n % b) + 'a' - 10;
		n /= b;
	}
	while (i--)
		r[j++] = ret[i];
	return (r);
}
