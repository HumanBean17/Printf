# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 12:22:56 by lcrawn            #+#    #+#              #
#    Updated: 2019/07/19 12:00:00 by lcrawn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_atoi_base.c ft_check.c ft_check_2.c \
		ft_conditions.c ft_cpy.c ft_flag_funcs.c ft_info.c \
		ft_isdigit.c ft_longarifm.c ft_longarifm_2.c ft_longarifm_3.c \
		ft_memalloc.c ft_memset.c ft_pows.c \
		ft_printf.c ft_printf_del.c ft_printf_list_func.c ft_printf_list_func_2.c \
		ft_put_adress.c ft_put_float.c ft_put_int.c ft_put_unsigned.c \
		ft_putchar.c ft_putnbr.c ft_putstr.c ft_return_flags.c \
		ft_return_num.c ft_round_dioux.c ft_strdup.c ft_strjoin.c \
		ft_strlen.c ft_strnew.c ft_strrev.c ft_strupper.c

SRC_O = ft_atoi.o ft_atoi_base.o ft_check.o ft_check_2.o \
		ft_conditions.o ft_cpy.o ft_flag_funcs.o ft_info.o \
		ft_isdigit.o ft_longarifm.o ft_longarifm_2.o ft_longarifm_3.o \
		ft_memalloc.o ft_memset.o ft_pows.o \
		ft_printf.o ft_printf_del.o ft_printf_list_func.o ft_printf_list_func_2.o \
		ft_put_adress.o ft_put_float.o ft_put_int.o ft_put_unsigned.o \
		ft_putchar.o ft_putnbr.o ft_putstr.o ft_return_flags.o \
		ft_return_num.o ft_round_dioux.o ft_strdup.o ft_strjoin.o \
		ft_strlen.o ft_strnew.o ft_strrev.o ft_strupper.o

NAME = libftprintf.a

HDR = libftprintf.h

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -c -I $(HDR) $(SRC)
		ar rc $(NAME) $(SRC_O)

clean:
		rm -f $(SRC_O)

fclean: clean
		rm -f $(NAME)

re: fclean all
