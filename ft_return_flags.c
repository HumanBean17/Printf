#include "libft.h"

char 		*ft_width(t_printf *tmp)
{
	char 	*width;

	width = NULL;
	if (tmp->width > 0)
	{
		if (tmp->acc == -1 && ft_flag_find(tmp->flag, '0') && (!ft_flag_find(tmp->flag, '-')))
			width = ft_strnew_n(tmp->width, '0');
		else
			width = ft_strnew_n(tmp->width, ' ');
	}
	return (width);
}

char 		*ft_tab(t_printf *tmp)
{
	char *tab;

	tab = NULL;
	if (ft_flag_find(tmp->flag, ' ') && (!ft_flag_find(tmp->flag, '+')) &&
		(tmp->type == 'i' || tmp->type == 'd'))
		tab = " ";
	return (tab);
}

char 		*ft_spec(t_printf *tmp)
{
	char *spec;

	spec = NULL;
	if (ft_flag_find(tmp->flag, '#') && (tmp->type == 'x' || tmp->type == 'X'))
		spec = "0x";
	if (ft_flag_find(tmp->flag, '#') && (tmp->type == 'o'))
		spec = "0";
	return (spec);
}

char 		*ft_sign(t_printf *tmp, char s)
{
	char *sign;

	sign = NULL;
	if (ft_flag_find(tmp->flag, '+') && s == '+')
		sign = "+";
	return (sign);
}

char *ft_return_width(t_printf *tmp, char *line)
{
	char 	*width;
	char 	*spec;
	char 	*tab;
	char 	*sign;
	char 	*ptr;

	tab = ft_tab(tmp);
	spec = ft_spec(tmp);
	sign = line ? ft_sign(tmp, line[0]) : ft_strnew_n(0, 1);
	width = ft_width(tmp);
	//printf("%s|\n", width);
	line = ft_strjoin(spec, line);
	line = ft_strjoin(line, sign);
	line = ft_strjoin(line, tab);
	if (tmp->type == '%')
		line = ft_strjoin(line, ft_strnew_n(1, tmp->type));
	if (ft_flag_find(tmp->flag, '-'))
		ft_strcpy_n(width, line);
	else
		ft_strcpy_end(width, line);
	//printf("%zu\n", ft_strlen(width));
	if (width)
		return (width);
	return (line);
}