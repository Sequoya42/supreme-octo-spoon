/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:08:07 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/10 21:46:31 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
// #include <xlocale.h>
// #include <wchar.h>
// #include <wctype.h>

int main(void)
{

	int str = 12;

	// ft_putstr(s);
	// ft_putchar('\n');

	ft_printf("%o\n", str);
	printf("%o\n", str);
	// printf("%o\n", 3);
	// printf("%s\n", str);
	// printf("%+d", 5);
	// ft_printf("%p\n", str);
	// printf("%s\n%s", "des bails", "dautre bails\n");
	// printf("%ld\n", 12);
	// ft_printf("%s:\t %-20.2s\n", "%-20.2s",  "Des bailsF");
	// printf("%s:\t %20.2s\n", "%20.2s",  "des bails");
	// //
	// ft_printf("%s:\t %20.2s\n", "%20.2s",  "Des bailsF");
	//
	// ft_printf("%s: %-20.2s\n", "%-20.2s\n",  "des bails");
	// ft_printf("%s: %20.2s\n", "%20.2s\n",  "des bails");
	// int i = ft_atoi("23etdesbails");
	// printf("%S", L"ابتثجحخدذرزسشصضطظعغفقكلمنهوي");
	// printf("%d\n", i);
	// ft_printf("Truc\n");
	// ft_printf("Stuff\n");
}
