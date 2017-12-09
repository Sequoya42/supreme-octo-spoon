#include "libftprintf.h"

int					is_in(char c, char *str)
{
	int				i;

	i = -1;

	while (str[++i])
	{
		if (str[i] == c)
		{
			return (1);
		}
	}
	return (0);
}

void				add_more_flags(t_print *print, char *t, int i)
{
	if (t[i] == 'h' && t[i + 1] == 'h' && (i += 2))
		print->flags[HH] = 1;
	else if (t[i] == 'h' && i++)
		print->flags[H] = 1;
	if (t[i] == 'l' && t[i + 1] == 'l' && (i += 2))
		print->flags[LL] = 1;
	else if (t[i] == 'l' && i++)
		print->flags[L] = 1;
	if (t[i] == '.' && i++)
		print->flags[PRECISION] = ft_atoi(t + i);

}

void				add_flag(t_print *print, char *t, int i)
{
	if (t[i] == '#' && i++)
		print->flags[SHARP] = 1;
	if (t[i] == '0' && i++)
		print->flags[ZERO] = 1;
	if (t[i] == '-' && i++)
		print->flags[MINUS] = 1;
	if (t[i] == '+' && i++)
		print->flags[PLUS] = 1;
	if (t[i] == ' ' && i++)
		print->flags[SPACE] = 1;
	if (t[i] == 'j' && i++)
		print->flags[J] = 1;
	if (t[i] == 'z' && i++)
		print->flags[Z] = 1;
	add_more_flags(print, t, i);
}

t_print				parse_format(char *t, int i)
{
	t_print			print;

	while (!is_in(t[++i], CONVS))
	{
		if (!is_in(t[i], FLAGS))
		{
			ft_putstr("Unknown flag");
			exit(0);
		}
		else
		{
			add_flag(&print, t, i);
		}
	}
	print.conv = t[i];
	return (print);
}
