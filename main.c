/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:47:24 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/18 21:50:36 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

/*todo
   hex stuff first 42filechecker*/
int			main(void)
{
	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("@moulitest: %#.x %#.0x\n", 0, 0);
}
