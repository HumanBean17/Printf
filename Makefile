# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 12:22:56 by lcrawn            #+#    #+#              #
#    Updated: 2019/07/19 11:04:20 by lcrawn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.c

SRC_O = *.o

NAME = libftprintf.a

HDR = libft.h

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -o ft_printf $(SRC)

clean:
		rm -f ft_printf

fclean: clean
		rm -f ft_printf libftprintf.a

re: fclean all
