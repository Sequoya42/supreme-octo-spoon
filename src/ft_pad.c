/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:54:19 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/19 12:26:57 by rbaum            ###   ########.fr       */
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
	s = ft_memalloc(k + 1);
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

int				choose_start(t_print print, char *value)
{
	if ((PRE > (int)ft_strlen(value) || FILL == '0') &&
	    (value[0] == '+' || value[0] == '-'))
	{
		counter(1);
		ft_putchar(value[0]);
		return (1);
	}
	return (0);
}

void			ft_pad_num(char *value, t_print print)
{
	int			l;
	int			i;

	i = choose_start(print, value);
	if (PRE == 0 && ((print.conv == x || print.conv == X)
			 || (print.conv == o && !IS_SET(SHARP))))
		return ft_add_space(PAD != -1 ? PAD : 0, ' ', print);
	l = ft_strlen(value);
	if (PRE > l && print.conv != M)
		value = fill_zero(value, PRE, l, print);
	print.str = value;
	if (IS_SET(SHARP) && ft_atoi(value) != 0 && FILL != '0')
		value = choose_prepend(print, value);
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
