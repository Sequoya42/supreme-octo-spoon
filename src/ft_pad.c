/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:54:19 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/10 18:55:42 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


void			ft_add_space(int i)
{
	while (i--)
		ft_putchar(' ');
}

void			ft_pad(char *stuff, t_print print)
{
	int			l;
	int			i;

	i = 0;
	l = ft_strlen(stuff);
	l = (PRE != -1 && PRE < l) ? PRE : l;
	if (DIR == BEFORE && PAD > l)
		ft_add_space(PAD - l);
	while (i < l)
		ft_putchar(stuff[i++]);
	if (DIR == AFTER && PAD > l)
		ft_add_space(PAD - l);
}
