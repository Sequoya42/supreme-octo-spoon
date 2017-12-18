/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:54:19 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/18 14:30:48 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_add_space(int i, char fill)
{
	counter(i);
	while (i--)
		ft_putchar(fill);
}

void			ft_pad(char *value, t_print print, char fill)
{
	int			l;
	int			i;
	int			c;

	i = 0;
	c = 0;
	l = ft_strlen(value);
	l = (PRE != -1 && PRE < l) ? PRE : l;
	if (DIR == BEFORE && PAD > l)
		ft_add_space(PAD - l, fill);
	counter(l - i);
	while (i < l)
		ft_putchar(value[i++]);
	if (DIR == AFTER && PAD > l)
		ft_add_space(PAD - l, fill);
}

char			*fill_zero(char *value, int k, int l)
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
	while (value[j])
		s[i++] = value[j++];
	return (s);
}

void			ft_pad_num(char *value, t_print print)
{
	int			l;
	int			i;
	int			c;

	i = 0;
	c = 0;
	if (IS_SET(SHARP) && (print.conv == x || print.conv == X))
		value = ft_strjoin(print.conv == x ? "0x" : "0X", value);
	l = ft_strlen(value);
	if (PRE != -1 && PRE > l && print.conv != M)
		value = fill_zero(value, PRE, l);
	l = ft_strlen(value);
	if (DIR == BEFORE && PAD > l)
		ft_add_space(PAD - l, FILL);
	counter(l - i);
	while (i < l)
		ft_putchar(value[i++]);
	if (DIR == AFTER && PAD > l)
		ft_add_space(PAD - l, FILL);
}
