cmake_minimum_required(VERSION 3.13)
project(printf C)

set(CMAKE_C_STANDARD 11)

include_directories(header)
include_directories(libft)

add_executable(printf
        ft_atoi.c
        ft_atoi_base.c
        ft_check.c
        ft_check_2.c
        ft_cpy.c
        ft_info.c
        ft_isdigit.c
        ft_itoa.c
        ft_longarifm.c
        ft_longarifm_2.c
        ft_longarifm_3.c
        ft_memalloc.c
        ft_memset.c
        ft_pows.c
        ft_printf
        ft_printf.c
        ft_printf.dSYM
        ft_printf_del.c
        ft_printf_list_func.c
        ft_put_adress.c
        ft_put_float.c
        ft_put_unsigned.c
        ft_putchar.c
        ft_putnbr.c
        ft_putstr.c
        ft_return_flags.c
        ft_return_num.c
        ft_strdup.c
        ft_strjoin.c
        ft_strlen.c
        ft_strnew.c
        ft_strupper.c
        libft.h
        main.c ft_round_dioux.c ft_put_int.c ft_conditions.c ft_flag_funcs.c ft_printf_list_func_2.c)
