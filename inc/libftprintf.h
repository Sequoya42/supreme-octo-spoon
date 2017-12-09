#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdarg.h>

# define CONVS "sSpdDioOuUxXcC"
# define FLAGS "#0+- hljz123456789"

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
	char					conv;
	int						length;
	int						flags[FLAG_LEN];
	char					*str;
	char					*precision;
};

typedef void				(*t_fptr)(t_print print);

void						ft_printf(char *restrict s, ...);

void						ft_putchar(char c);
void						ft_putnbr(int n);
void						ft_putstr(char const *s);
size_t						ft_strlen(const char *s);
int							ft_atoi(const char *str);
int							ft_isdigit(int c);

/*
 ** parse_format.c
*/

t_print							parse_format(char *t, int i);

#endif
