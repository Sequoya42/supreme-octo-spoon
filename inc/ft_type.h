/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 00:04:52 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/12 15:55:45 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPE_H
# define FT_TYPE_H

# define CONVS		"sSpdDioOuUxXcC%"
# define FLAGS		"#0+-. hljz123456789"

# define TEST			-12
# define ARG(x)			va_arg(argp, x)
# define IS_SET(x)		(print.flags[x] != -1)
# define PRE			print.flags[PRECISION]
# define DIR			print.flags[MINUS]
# define PAD			print.flags[PADDING]
# define BEFORE		-1
# define AFTER		1

typedef enum ft_type		t_type;
typedef enum e_conv			t_conv;
typedef enum e_flag			t_flag;
typedef struct s_change		t_change;

enum						e_conv
{
	s, S, p, d, D, i, o, O, u, U, x, X, c, C, M,
	CONV_LEN
};

enum						e_flag
{
	SHARP, ZERO, MINUS, PLUS, SPACE,
	HH, H, L, LL, J, Z,
	PRECISION, PADDING,
	FLAG_LEN
};

enum						e_type
{
	FT_INT,
	FT_UNSIGNED_INT,
	FT_UNSIGNED_LONG,
	FT_UNSIGNED_LONG_LONG,
	FT_UNSIGNED_CHAR,
	FT_UNSIGNED_LONG_CHAR,
};

#endif
