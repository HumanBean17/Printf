#include "libft.h"

char		*ft_width(t_printf *tmp, int c)
{
	char 	*width;

	width = "";
	if (tmp->width > 0)
	{
		if (tmp->acc == -1 && ft_flag_find(tmp->flag, '0'))
			width = ft_strnew_n(tmp->width - c, '0');
		else
			width = ft_strnew_n(tmp->width - c, ' ');
	}
	return (width);
}

char 		*ft_tab(t_printf *tmp)
{
	char *tab;

	tab = "";
	if (ft_flag_find(tmp->flag, ' ') && (!ft_flag_find(tmp->flag, '+')) &&
		(tmp->type == 'i' || tmp->type == 'd'))
		tab = " ";
	return (tab);
}

char 		*ft_spec(t_printf *tmp)
{
	char *spec;

	spec = "";
	if (ft_flag_find(tmp->flag, '#') && (tmp->type == 'x' || tmp->type == 'X'))
		spec = "0x";
	if (ft_flag_find(tmp->flag, '#') && (tmp->type == 'o'))
		spec = "0";
	return (spec);
}

char 		*ft_sign(t_printf *tmp, char s)
{
	char *sign;

	sign = "";
	if (ft_flag_find(tmp->flag, '+') && s == '+')
		sign = "+";
	return (sign);
}

char		*ft_return_width(t_printf *tmp, char s)
{
	char 	*width;
	char 	*spec;
	char 	*tab;
	char 	*sign;
	char 	*ptr;

	tab = ft_tab(tmp);
	spec = ft_spec(tmp);
	sign = ft_sign(tmp, s);
	width = ft_width(tmp, ft_strlen(tab) + ft_strlen(spec) + ft_strlen(sign));
	/*printf("width = %s %zu\n", width, ft_strlen(width));
	printf("tab = %s %zu\n", tab, ft_strlen(tab));
	printf("spec = %s %zu\n", spec, ft_strlen(spec));
	printf("sign = %s %zu\n", sign, ft_strlen(sign));*/
	width = ft_strjoin(width, tab);
	if (width[0] == spec[0])
		width = ft_strjoin(spec, width);
	else
		width = ft_strjoin(width, spec);
	width = ft_strjoin(width, sign);
	//printf("result %s %zu\n", width, ft_strlen(width));
	return (width);
}