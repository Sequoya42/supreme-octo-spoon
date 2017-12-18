/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:47:24 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/18 22:44:02 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

/*todo
   hex stuff first 42filechecker*/
int			main(void)
{
	int i = ft_printf("%0+5d\n", -42);
	// ft_putnbr(ft_printf("%0+5d\n", -42));
	//   ft_printf("@moulitest: %.o %.0o", 0, 0);
	// ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
	// printf("@moulitest: %#.o %#.0o\n", 0, 0);
}
