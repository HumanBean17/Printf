#include "libft.h"

int		ft_fill_info(const char *str, va_list ap)
{
	t_printf 	*list;
	char		*line;
	int 		c;

	list = ft_printf_new();
	c = ft_fill(&list, str) + 1;
	line = NULL;
	//ft_print(list);
	if (list->type == 'd' || list->type == 'i')
		line = ft_putnbr(va_arg(ap, int));
	else if (list->type == 'o')
		line = ft_base(va_arg(ap, unsigned int), 8);
	else if (list->type == 'u')
		line = ft_put_unsigned(va_arg(ap, unsigned int));
	else if (list->type == 'x' || list->type == 'X')
		line = ft_base(va_arg(ap, unsigned int), 16);
	else if (list->type == 'f' || list->type == 'F')
		line = ft_put_float(va_arg(ap, double), list->acc);
	else if (list->type == 'e' || list->type == 'E')
		line = ft_put_exp(va_arg(ap, double), list->acc);
	else if (list->type == 'p')
		line = ft_put_address(va_arg(ap, void*));
	if (ft_toupper(list->type) == list->type)
		ft_putstr(ft_strupper(line));
	else
		ft_putstr(line);
	ft_strdel(&line);
	ft_printf_del(&list);
	return (c);
}