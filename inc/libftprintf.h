/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:30:52 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/19 12:19:43 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "ft_type.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdarg.h>

typedef	struct s_print		t_print;

struct						s_print
{
	t_conv					conv;
	int						length;
	int						flags[FLAG_LEN];
	void					*kind;
	char					*str;
};

typedef void				(*t_fptr)(t_print print, va_list argp);

int							ft_printf(char *restrict s, ...);
void						ft_pad(char *stuff, t_print print);
void						ft_pad_num(char *stuff, t_print print);

/*
** Library functions
*/
char						*ft_itoa(long n);
char						*ft_unsigned_itoa(unsigned long n);
void						ft_putchar(char c);
void						ft_putnbr(int n);
void						ft_un_putnbr(unsigned int nb);
void						ft_putstr(char const *s);
size_t						ft_strlen(const char *s);
int							ft_atoi(const char *str);
int							ft_isdigit(int c);
char						*ft_strnew(size_t size);
void						*ft_memalloc(size_t size);
char						*ft_base(unsigned int n, int b, char type);
char						*ft_long_base(unsigned long n, int b, char t);
char						*ft_llong_base(unsigned long long n, int b, char type);
char						*ft_uint_base(uintmax_t n, int b, char type);
char						*print_adrr(int i, int base);
void						print_hex_mem(unsigned char *addr, int maj);
char						*ft_strjoin(char const *s1, char const *s2);

/*
** conversions
*/
void						ft_string(t_print print, va_list argp);
void						ft_pointer(t_print print, va_list argp);
void						ft_int(t_print print, va_list argp);
void						ft_hex(t_print print, va_list argp);
void						ft_octal(t_print print, va_list argp);
void						ft_char(t_print print, va_list argp);

/*
** helpers
*/

void						ft_exit(char *s);
int							is_in(char c, char *str);
int							find_index(char *s, char c);
int							counter(int n);

/*
 ** parse_format.c
*/

t_print						parse_format(char *t, int i);

#endif
