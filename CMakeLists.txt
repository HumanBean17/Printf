cmake_minimum_required(VERSION 3.13)
project(printf C)

set(CMAKE_C_STANDARD 11)

include_directories(header)
include_directories(libft)

add_executable(printf
        libft.h
        ft_longarifm.c
        ft_atoi.c
        ft_bzero.c
        ft_isalnum.c
        ft_isalpha.c
        ft_isascii.c
        ft_isdigit.c
        ft_isprint.c
        ft_itoa.c
        ft_list_find.c
        ft_list_foreach_if.c
        ft_list_push_back.c
        ft_list_reverse.c
        ft_lstadd.c
        ft_lstdel.c
        ft_lstdelone.c
        ft_lstiter.c
        ft_lstmap.c
        ft_lstnew.c
        ft_memalloc.c
        ft_memccpy.c
        ft_memchr.c
        ft_memcmp.c
        ft_memcpy.c
        ft_memdel.c
        ft_memmove.c
        ft_memset.c
        ft_putchar.c
        ft_putchar_fd.c
        ft_putendl.c
        ft_putendl_fd.c
        ft_putnbr.c
        ft_putnbr_fd.c
        ft_putstr.c
        ft_putstr_fd.c
        ft_strcat.c
        ft_strchr.c
        ft_strclr.c
        ft_strcmp.c
        ft_strcpy.c
        ft_strdel.c
        ft_strdup.c
        ft_strequ.c
        ft_striter.c
        ft_striteri.c
        ft_strjoin.c
        ft_strlcat.c
        ft_strlen.c
        ft_strmap.c
        ft_strmapi.c
        ft_strncat.c
        ft_strncmp.c
        ft_strncpy.c
        ft_strnequ.c
        ft_strnew.c
        ft_strnstr.c
        ft_strrchr.c
        ft_strrev.c
        ft_strsplit.c
        ft_strstr.c
        ft_strsub.c
        ft_strtrim.c
        ft_tolower.c
        ft_toupper.c
        libft.h
        main.c
        ft_printf.c ft_check.c ft_info.c ft_printf_list_func.c ft_atoi_base.c
        ft_put_unsigned.c ft_printf_del.c ft_strupper.c ft_put_float.c
        ft_pows.c ft_put_exp.c ft_put_adress.c)
