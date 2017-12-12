/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:54:19 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/12 17:20:46 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_add_space(int i)
{
	counter(i);
	while (i--)
		ft_putchar(' ');
}

void			ft_pad(char *stuff, t_print print)
{
	int			l;
	int			i;
	int			c;

	i = 0;
	c = 0;
	l = ft_strlen(stuff);
	l = (PRE != -1 && PRE < l) ? PRE : l;
	if (DIR == BEFORE && PAD > l)
		ft_add_space(PAD - l);
	counter(l - i);
	while (i < l)
		ft_putchar(stuff[i++]);
	if (DIR == AFTER && PAD > l)
		ft_add_space(PAD - l);
}

char			*fill_zero(char *stuff, int k, int l)
{
	char		*s;
	int			i;
	int			j;

	i = 0;
	j = k - l;
	s = ft_memalloc(k);
	while (i < j)
		s[i++] = '0';
	j = 0;
	while (stuff[j])
		s[i++] = stuff[j++];
	return s;
}

void			ft_pad_num(char *stuff, t_print print)
{
	int			l;
	int			i;
	int			c;

	i = 0;
	c = 0;
	l = ft_strlen(stuff);
	if (PRE != -1 && PRE > l && print.conv != M)
		stuff = fill_zero(stuff, PRE, l);
	l = ft_strlen(stuff);
	if (DIR == BEFORE && PAD > l)
		ft_add_space(PAD - l);
	counter(l - i);
	while (i < l)
		ft_putchar(stuff[i++]);
	if (DIR == AFTER && PAD > l)
		ft_add_space(PAD - l);
}
