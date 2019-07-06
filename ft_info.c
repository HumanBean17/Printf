#include "libft.h"

char    *ft_line(t_printf *list, va_list ap)
{
    char *line;

    line = NULL;
    if (list->type == 'c')
        line = ft_putchar_2(va_arg(ap, unsigned));
    else if (list->type == 's')
        line = ft_strdup(va_arg(ap, char *));
    else if (list->type == 'd' || list->type == 'i')
    {
        if (ft_len_check_dioux(list->len) == 0)
            line = ft_putnbr(va_arg(ap, int));
        else if (ft_len_check_dioux(list->len) == 1)
            line = ft_putnbr_short(va_arg(ap, int));
        else if (ft_len_check_dioux(list->len) == 2)
            line = ft_putnbr_long(va_arg(ap, long int));
        else if (ft_len_check_dioux(list->len) == 3)
            line = ft_putnbr_signed(va_arg(ap, int));
        else if (ft_len_check_dioux(list->len) == 4)
            line = ft_putnbr_llong(va_arg(ap, long long int));
    }
    else if (list->type == 'o')
    {
        if (ft_len_check_dioux(list->len) == 0)
            line = ft_base(va_arg(ap, unsigned int), 8);
        else if (ft_len_check_dioux(list->len) == 1)
            line = ft_base_short(va_arg(ap, unsigned int), 8);
        else if (ft_len_check_dioux(list->len) == 2)
            line = ft_base_long(va_arg(ap, unsigned long int), 8);
        else if (ft_len_check_dioux(list->len) == 3)
            line = ft_base_char(va_arg(ap, unsigned int), 8);
        else if (ft_len_check_dioux(list->len) == 4)
            line = ft_base_llong(va_arg(ap, unsigned long long int), 8);
    }
    else if (list->type == 'u')
    {
        if (ft_len_check_dioux(list->len) == 0)
            line = ft_put_unsigned(va_arg(ap, unsigned int));
        else if (ft_len_check_dioux(list->len) == 1)
            line = ft_put_unsigned_short(va_arg(ap, unsigned int));
        else if (ft_len_check_dioux(list->len) == 2)
            line = ft_put_unsigned_long(va_arg(ap, unsigned long int));
        else if (ft_len_check_dioux(list->len) == 3)
            line = ft_put_unsigned_char(va_arg(ap, unsigned int));
        else if (ft_len_check_dioux(list->len) == 4)
            line = ft_put_unsigned_llong(va_arg(ap, unsigned long long int));
    }
    else if (list->type == 'x' || list->type == 'X')
    {
        if (ft_len_check_dioux(list->len) == 0)
            line = ft_base(va_arg(ap, unsigned int), 16);
        else if (ft_len_check_dioux(list->len) == 1)
            line = ft_base_short(va_arg(ap, unsigned int), 16);
        else if (ft_len_check_dioux(list->len) == 2)
            line = ft_base_long(va_arg(ap, unsigned long int), 16);
        else if (ft_len_check_dioux(list->len) == 3)
            line = ft_base_char(va_arg(ap, unsigned int), 16);
        else if (ft_len_check_dioux(list->len) == 4)
            line = ft_base_llong(va_arg(ap, unsigned long long int), 16);
    }
    else if (list->type == 'f' || list->type == 'F')
        line = ft_len_check(list->len) ?
               ft_put_float(va_arg(ap, long double), list->acc) :
               ft_put_float(va_arg(ap, double), list->acc);
    else if (list->type == 'e' || list->type == 'E')
        line = ft_put_exp(va_arg(ap, double), list->acc);
    else if (list->type == 'p')
        line = ft_put_address(va_arg(ap, unsigned long));
    return (line);
}

int		ft_fill_info(const char *str, va_list ap)
{
	t_printf 	*list;
	char 		*field;
	char		*number;
	int 		c;

	list = ft_printf_new();
	c = ft_fill(&list, str) + 1;
	number = ft_line(list, ap);
	//ft_print(list);
	field = ft_return_width(list, number[0], number);
	if (ft_toupper(list->type) == list->type)
		ft_putstr(ft_strupper(field));
	else
		ft_putstr(field);
	c = ft_strlen(field);
	if (number == field)
		ft_strdel(&number);
	else
	{
		ft_strdel(&number);
		ft_strdel(&field);
	}
	ft_printf_del(&list);
	return (c);
}