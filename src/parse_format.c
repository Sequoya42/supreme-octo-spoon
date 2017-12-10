/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:34:00 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/10 19:13:44 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				add_flag(t_print *print, char *t, int *i, int flag)
{
	print->flags[flag] = ft_atoi(t + *i);
	while (ft_isdigit(t[*i]))
		(*i)++;
}

int					add_more_flags(t_print *print, char *t, int i)
{
	if (t[i] == 'h' && t[i + 1] == 'h' && (i += 2))
		print->flags[HH] = 1;
	else if (t[i] == 'h' && i++)
		print->flags[H] = 1;
	if (t[i] == 'l' && t[i + 1] == 'l' && (i += 2))
		print->flags[LL] = 1;
	else if (t[i] == 'l' && i++)
		print->flags[L] = 1;
	if (ft_isdigit(t[i]))
		add_flag(print, t, &i, PADDING);
	if (t[i] == '.' && i++)
		add_flag(print, t, &i, PRECISION);
	return (i);
}

int					add_flags(t_print *print, char *t, int i)
{
	if (t[i] == '#' && i++)
		print->flags[SHARP] = 1;
	if (t[i] == '0' && i++)
		print->flags[ZERO] = 1;
	if (t[i] == '-' && i++)
		print->flags[MINUS] = 1;
	if (t[i] == '+' && i++)
		print->flags[PLUS] = 1;
	if (t[i] == ' ' && i++)
		print->flags[SPACE] = 1;
	if (t[i] == 'j' && i++)
		print->flags[J] = 1;
	if (t[i] == 'z' && i++)
		print->flags[Z] = 1;
	return (add_more_flags(print, t, i));
}


void				clear_flags(t_print *print)
{
	int				i;

	i = 0;
	while (i < FLAG_LEN)
	{
		print->flags[i++] = -1;
	}
}

t_print				parse_format(char *t, int i)
{
	t_print			print;

	clear_flags(&print);
	while (t[i] && !is_in(t[++i], CONVS))
	{
		if (!is_in(t[i], FLAGS))
			ft_exit("Unknown flag\n");
		else
			i = add_flags(&print, t, i) - 1;
	}
	if (is_in(t[i], CONVS))
	{
		print.conv = find_index(CONVS, t[i]);
		print.length = i;
	}
	else
		ft_exit("Unknown conv\n");
	return (print);
}
