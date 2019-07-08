#include "libft.h"

char 		*ft_width(t_printf *tmp, char *line)
{
	char 	*width;
	char	c;

	width = NULL;
	if (tmp->width > 0)
	{
		if (tmp->acc == -1 && ft_flag_find(tmp->flag, '0') && (!ft_flag_find(tmp->flag, '-')))
		{
			width = ft_strnew_n(tmp->width, '0');
			if ((line) && (line)[0] == '-')
			{
				c = line[0];
				line[0] = width[0];
				width[0] = c;
			}
		}
		else
			width = ft_strnew_n(tmp->width, ' ');
	}
	return (width);
}

char 		*ft_tab(t_printf *tmp, char c)
{
	char *tab;

	tab = NULL;
	if (c != '-' && ft_flag_find(tmp->flag, ' ') && (!ft_flag_find(tmp->flag, '+')) &&
		(tmp->type == 'i' || tmp->type == 'd'))
		tab = ft_strdup(" ");
	return (tab);
}

char 		*ft_spec(t_printf *tmp)
{
	char *spec;

	spec = NULL;
	if (ft_flag_find(tmp->flag, '#') && (tmp->type == 'x' || tmp->type == 'X'))
		spec = ft_strdup("0x");
	if (ft_flag_find(tmp->flag, '#') && (tmp->type == 'o'))
		spec = ft_strdup("0");
	return (spec);
}

char 		*ft_sign(t_printf *tmp, char s)
{
	char *sign;

	sign = NULL;
	if (ft_flag_find(tmp->flag, '+') && s != '-')
		sign = ft_strdup("+");
	return (sign);
}

int 		ft_check_zero(const char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

void ft_char_zero(char **width, const char *line, t_printf *tmp)
{
	if (tmp->type == 'c' && (*width) && line && line[0] == '\0')
		(*width)[ft_strlen(*width) - 1] = '\0';
}

char 		*ft_return_width(t_printf *tmp, char *line)
{
	char 	*width;
	char 	*spec;
	char 	*tab;
	char 	*sign;
	char 	*ptr;

	tab = line ? ft_tab(tmp, line[0]) : ft_strdup("");
	spec = ft_spec(tmp);
	sign = line ? ft_sign(tmp, line[0]) : ft_strnew_n(0, 1);
	width = ft_width(tmp, line);
	if ((!ft_flag_find(tmp->flag, '0') || ft_flag_find(tmp->flag, '-')) &&
	(ft_check_zero(line) || ft_strlen(spec) == 1))
		line = ft_strjoin(spec, line);
	else if (ft_check_zero(line))
		ft_strcpy_n(width, spec);
	if (!ft_flag_find(tmp->flag, '0') && tmp->type != 'u')
		line = ft_strjoin(sign, line);
	else if (ft_flag_find(tmp->flag, '+') && tmp->type != 'u')
		ft_strcpy_n(width, sign);
	line = ft_strjoin(tab, line);
	if (tmp->type == '%')
		line = ft_strjoin(line, ft_strnew_n(1, tmp->type));
	if (ft_flag_find(tmp->flag, '-'))
		ft_strcpy_n(width, line);
	else if (tmp->width >= ft_strlen(line))
		ft_strcpy_end(width, line);
	else
		ft_strdel(&width);
	ft_char_zero(&width, line, tmp);
	if (width)
		return (width);
	return (line);
}