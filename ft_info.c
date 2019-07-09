#include "libft.h"

char    *ft_line(t_printf *list, va_list ap)
{
    char *line;

    line = NULL;
    if (list->type == 'c')
        line = ft_putchar_2(va_arg(ap, unsigned));
    else if (list->type == 's')
        line = ft_strdup_n(va_arg(ap, char *), list->acc);
    else if (list->type == 'd' || list->type == 'i')
    {
        if (ft_len_check_dioux(list->len) == 0)
            line = ft_putnbr(va_arg(ap, int), list->acc);
        else if (ft_len_check_dioux(list->len) == 1)
            line = ft_putnbr_short(va_arg(ap, int), list->acc);
        else if (ft_len_check_dioux(list->len) == 2)
            line = ft_putnbr_long(va_arg(ap, long int), list->acc);
        else if (ft_len_check_dioux(list->len) == 3)
            line = ft_putnbr_signed(va_arg(ap, int), list->acc);
        else if (ft_len_check_dioux(list->len) == 4)
            line = ft_putnbr_llong(va_arg(ap, long long int), list->acc);
    }
    else if (list->type == 'o')
    {
        if (ft_len_check_dioux(list->len) == 0)
            line = ft_base(va_arg(ap, unsigned int), 8, list->acc);
        else if (ft_len_check_dioux(list->len) == 1)
            line = ft_base_short(va_arg(ap, unsigned int), 8, list->acc);
        else if (ft_len_check_dioux(list->len) == 2)
            line = ft_base_long(va_arg(ap, unsigned long int), 8, list->acc);
        else if (ft_len_check_dioux(list->len) == 3)
            line = ft_base_char(va_arg(ap, unsigned int), 8, list->acc);
        else if (ft_len_check_dioux(list->len) == 4)
            line = ft_base_llong(va_arg(ap, unsigned long long int), 8, list->acc);
    }
    else if (list->type == 'u')
    {
        if (ft_len_check_dioux(list->len) == 0)
            line = ft_put_unsigned(va_arg(ap, unsigned int), list->acc);
        else if (ft_len_check_dioux(list->len) == 1)
            line = ft_put_unsigned_short(va_arg(ap, unsigned int), list->acc);
        else if (ft_len_check_dioux(list->len) == 2)
            line = ft_put_unsigned_long(va_arg(ap, unsigned long int), list->acc);
        else if (ft_len_check_dioux(list->len) == 3)
            line = ft_put_unsigned_char(va_arg(ap, unsigned int), list->acc);
        else if (ft_len_check_dioux(list->len) == 4)
            line = ft_put_unsigned_llong(va_arg(ap, unsigned long long int), list->acc);
    }
    else if (list->type == 'x' || list->type == 'X')
    {
        if (ft_len_check_dioux(list->len) == 0)
            line = ft_base(va_arg(ap, unsigned int), 16, list->acc);
        else if (ft_len_check_dioux(list->len) == 1)
            line = ft_base_short(va_arg(ap, unsigned int), 16, list->acc);
        else if (ft_len_check_dioux(list->len) == 2)
            line = ft_base_long(va_arg(ap, unsigned long int), 16, list->acc);
        else if (ft_len_check_dioux(list->len) == 3)
            line = ft_base_char(va_arg(ap, unsigned int), 16, list->acc);
        else if (ft_len_check_dioux(list->len) == 4)
            line = ft_base_llong(va_arg(ap, unsigned long long int), 16, list->acc);
    }
    else if (list->type == 'f' || list->type == 'F')
    {
		//line = ft_put_float(va_arg(ap, double), list->acc);
    	if (ft_len_check(list->len) == 2)
			line = ft_put_float(va_arg(ap, long double), list->acc);
    	else
			line = ft_put_float(va_arg(ap, double), list->acc);
	}
    else if (list->type == 'e' || list->type == 'E')
        line = ft_put_exp(va_arg(ap, double), list->acc);
    else if (list->type == 'p')
        line = ft_put_address(va_arg(ap, unsigned long), list->acc);
    return (line);
}

int		ft_fill_info(const char *str, va_list ap)
{
	t_printf 	*list;
	char 		*field;
	char		*number;
	int 		c;

	list = ft_printf_new();
	ft_fill(&list, str);
	//ft_print(list);
	number = ft_line(list, ap);
	//printf("num = %s\n", number);
	field = ft_return_width(list, number);
	c = ft_printf_putstr(list->type, field, number);
	//printf("%s %s\n", number, field);
	ft_do_del(&list, &number, &field);
	return (c);
}