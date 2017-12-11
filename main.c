/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:08:07 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/11 18:04:27 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
/*	char u1 = 0xc3;
        char u2 = 0xa9;
        int c = 0xc3a9;
        static wchar_t nik[] = {0xc3, 0xa9, '\0', '\0'};
        static char tot[3];
        tot[0] = u1;
        tot[1] = u2;
        tot[2] = '\0';
        ft_putstr(tot);
        char *ni = ft_base(c, 16);
        ft_putstr("école");
        // write(1, (char *)&c, 2);

        ft_putchar(u1);
        ft_putchar(u2);
        ft_putchar('\n');
 */
// ******** ********    ******** ********

	// printf("%d\n", n);
	int i =		printf("toto et %+d\n", TEST);
	int j =		ft_printf("toto et %+d\n", TEST);

	printf("VALUE OF I : %d\nVALUE OF J : %d\n", i, j);
	// ft_printf("%u\n", -12);
	// unsigned long long toto = 9171919191929229923;
	// unsigned int nik = -12;
	//
	// #include <limits.h>
	// printf("%u\n", nik);
	// printf("%llo\n", toto);
	// ft_printf("%llo\n", toto);
	// ft_printf("%o\n", 1873);
	// printf("%lo\n", 19191919192029229);
	// ft_printf("%lo\n", 19191919192029229);
	// ft_putstr((char*)nik);
	// printf("%S\n", nik);
	return (0);
}
