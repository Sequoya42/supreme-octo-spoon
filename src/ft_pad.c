/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:54:19 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/18 22:13:01 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_add_space(int i, char fill, t_print print)
{
	int			j;

	j = -1;
	counter(i);
	while (++j < i)
	{
		if (j == 1 && FILL == '0' && (print.conv == x || print.conv == X)
		    && IS_SET(SHARP) && ft_atoi(print.str) != 0)
			ft_putchar(print.conv == x ? 'x' : 'X');
		else
			ft_putchar(fill);
	}
}


char			*fill_zero(char *value, int k, int l, t_print print)
{
	(void)print;
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

void			ft_pad(char *value, t_print print)
{
	int			l;
	int			i;

	i = 0;
	l = ft_strlen(value);
	l = (PRE != -1 && PRE < l) ? PRE : l;
	l = l == 0 && print.conv == c && value[0] == 0 ? 1 : l;
	if (DIR == BEFORE && PAD > l)
		ft_add_space(PAD - l, FILL, print);
	counter(l - i);
	while (i < l)
		ft_putchar(value[i++]);
	if (DIR == AFTER && PAD > l)
		ft_add_space(PAD - l, FILL, print);
}

void			ft_pad_num(char *value, t_print print)
{
	int			l;
	int			i;

	i = 0;
	if (PRE == 0 && print.conv != M)
	{
		return ft_add_space(PAD != -1 ? PAD : 0, ' ', print);
	}
	l = ft_strlen(value);
	if (PRE > l && print.conv != M)
		value = fill_zero(value, PRE, l, print);
	print.str = value;
	if (IS_SET(SHARP) && ft_atoi(value) != 0 && FILL != '0'
	    &&  (print.conv == x || print.conv == X))
		value = ft_strjoin(print.conv == x ? "0x" : "0X", value);
	l = ft_strlen(value);
	if (DIR == BEFORE && PAD > l)
		ft_add_space(PAD - l, FILL, print);
	counter(l - i);
	while (i < l)
		ft_putchar(value[i++]);
	i++;
	if (DIR == AFTER && PAD > l)
		ft_add_space(PAD - l, FILL, print);
}
