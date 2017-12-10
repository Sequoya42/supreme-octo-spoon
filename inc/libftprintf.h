/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:30:52 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/10 19:38:59 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdarg.h>

# define CONVS	"sSpdDioOuUxXcC"
# define FLAGS	"#0+-. hljz123456789"

#define PRE		print.flags[PRECISION]
#define DIR		print.flags[MINUS]
#define PAD		print.flags[PADDING]
#define BEFORE	-1
#define AFTER	1

typedef enum e_conv			t_conv;
typedef enum e_flag			t_flag;
typedef	struct s_print		t_print;

enum						e_conv
{
	s, S, p, d, D, i, o, O, u, U, x, X, c, C,
	CONV_LEN
};

enum						e_flag
{
	SHARP, ZERO, MINUS, PLUS, SPACE,
	HH, H, L, LL, J, Z,
	PRECISION, PADDING,
	FLAG_LEN
};

struct						s_print
{
	t_conv					conv;
	int						length;
	int						flags[FLAG_LEN];
	void					*kind;
	char					*str;
};

typedef void				(*t_fptr)(t_print print, va_list argp);

void						ft_printf(char *restrict s, ...);
void						ft_pad(char *stuff, t_print print);

/*
** Library functions
*/
char						*ft_itoa(int n);
char						*ft_itoa(int n);
void						ft_putchar(char c);
void						ft_putnbr(int n);
void						ft_putstr(char const *s);
size_t						ft_strlen(const char *s);
int							ft_atoi(const char *str);
int							ft_isdigit(int c);
char						*ft_strnew(size_t size);
void						*ft_memalloc(size_t size);
char						*ft_base(unsigned int n, int b);
char						*print_adrr(int i, int base);




/*
** conversions
*/
void						ft_string(t_print print, va_list argp);
void						ft_pointer(t_print print, va_list argp);
void						ft_int(t_print print, va_list argp);


/*
** helpers
*/

void						ft_exit(char *s);
int							is_in(char c, char *str);
int							find_index(char *s, char c);


/*
 ** parse_format.c
*/

t_print							parse_format(char *t, int i);

#endif
