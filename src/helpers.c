/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:13:19 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/18 13:18:39 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_exit(char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
	exit(0);
}

int					is_in(char c, char *str)
{
	int				i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
		{
			return (1);
		}
	}
	return (0);
}

int					find_index(char *s, char c)
{
	int			i;

	i = 0;
	while (s[i] != c)
	{
		i++;
	}
	return (i);
}

int					counter(int n)
{
	static int i = 0;

	i += n;
	return (i);
}
