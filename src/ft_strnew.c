/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:48:18 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/10 19:02:11 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strnew(size_t size)
{
	void	*str;

	str = ft_memalloc(size + 1);
	if (str == NULL)
		return (NULL);
	return ((char *)str);
}
