#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/11 17:48:47 by rbaum             #+#    #+#              #
#    Updated: 2015/06/12 22:24:47 by rbaum            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

CFLAG = -Wall -Werror -Wextra

NAME = libftprintf.a

INC_PATH =	./inc/

OBJ_PATH = ./obj/

SRC_PATH = ./src/

SRC_NAME = ft_printf.c \
			parse_format.c\
			ft_putchar.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_strlen.c \
			ft_atoi.c \
			ft_isdigit.c\


OBJ_NAME = $(SRC_NAME:.c=.o)

SRC =		$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =		$(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: 		$(NAME)

$(NAME): 	$(OBJ)
			@ar rcs $@ $^
			@echo "compile done !"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
			@mkdir -p $(OBJ_PATH)
			@$(CC) $(CFLAG) -I$(INC_PATH) -o $@ -c $<

clean:
			@rm -rf $(OBJ)
			@echo "clean done !"

fclean:		clean
			@rm -rf $(NAME)
			@echo "fclean done !"

re: 		fclean all
