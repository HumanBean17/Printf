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
        line = ft_putnbr(va_arg(ap, int));
    else if (list->type == 'o')
        line = ft_base(va_arg(ap, unsigned int), 8);
    else if (list->type == 'u')
        line = ft_len_check(list->len) ? ft_put_unsigned(va_arg(ap, unsigned long)) :
               ft_put_unsigned(va_arg(ap, unsigned));
    else if (list->type == 'x' || list->type == 'X')
        line = ft_base(va_arg(ap, unsigned int), 16);
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
	char		*line;
	int 		c;

	list = ft_printf_new();
	c = ft_fill(&list, str) + 1;
    //ft_print(list);
	line = ft_line(list, ap);
	if (ft_toupper(list->type) == list->type)
		ft_putstr(ft_strupper(line));
	else
		ft_putstr(line);
	ft_strdel(&line);
	ft_printf_del(&list);
	return (c);
}