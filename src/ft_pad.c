/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:54:19 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/19 15:48:21 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_add_space(int i, char fill, t_print print)
{
	int			j;
	int			k;

	j = -1;
	k = 0;
	counter(i);
	if (print.conv == d && fill == '0' &&
	    (print.str[0] == '+' || print.str[0] == '-'))
	{
		ft_putchar(print.str[0]);
		k = 1;
		// i -= 1;
	}
	while (++j < i)
	{
		if (j == 1 && FILL == '0' && (print.conv == x || print.conv == X)
		    && IS_SET(SHARP) && ft_atoi(print.str) != 0)
			ft_putchar(print.conv == x ? 'x' : 'X');
		else
			ft_putchar(fill);
	}
	return (k);
}


char			*fill_zero(char *value, int pre, int l, t_print print)
{
	(void)print;
	char		*s;
	int			i;
	int			j;

	i = 0;
	s = ft_memalloc(pre + 1);
	if (value[0] == '+' || value[0] == '-')
	{
		s[0] = value[0];
		value += 1;
		i = 1;
		l -= 2;
	}
	j = pre - l;
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

char			*choose_prepend(t_print print, char *value)
{
	if (print.conv == x)
		value = ft_strjoin("0x", value);
	else if (print.conv == X)
		value = ft_strjoin("0X", value);
	else if (print.conv == o || print.conv == O)
		value = ft_strjoin("0", value);
	return (value);
}

void			ft_pad_num(char *value, t_print print)
{
	int			l;
	int			i;
	int			k;

	i = 0;
	k = 0;
	if (PRE != -1)
		print.flags[ZERO] = -1;
	if (PRE == 0 && ((print.conv == x || print.conv == X)
			 || (print.conv == o && !IS_SET(SHARP)) ||
			 (print.conv == d && ft_atoi(value) == 0)))
		return (void)ft_add_space(PAD != -1 ? PAD : 0, ' ', print);
	l = ft_strlen(value);
	if (PRE >= l && print.conv != M)
		value = fill_zero(value, PRE, l, print);
	print.str = value;
	if (IS_SET(SHARP) && ft_atoi(value) != 0 && FILL != '0')
		value = choose_prepend(print, value);
	l = ft_strlen(value) - i;
	if (DIR == BEFORE && PAD > l)
		k = ft_add_space(PAD - l, FILL, print);
	counter(l - i);
	if (k == 1)
		i++;
	while (i < l)
		ft_putchar(value[i++]);
	if (DIR == AFTER && PAD > l)
		ft_add_space(PAD - l, FILL, print);
}
