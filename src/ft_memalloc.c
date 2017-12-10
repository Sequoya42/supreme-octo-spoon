/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:42:24 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/10 19:02:06 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*mem;
	char	*t;

	i = 0;
	if ((mem = (void *)malloc(size * sizeof(void))) == NULL)
		return (NULL);
	t = (char *)mem;
	if (mem != NULL)
	{
		while (i < size)
		{
			*t++ = 0;
			i++;
		}
	}
	return (mem);
}
