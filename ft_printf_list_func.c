#include "libft.h"

static t_flags		*ft_flag_create(const char c)
{
	t_flags *tmp;

	tmp = NULL;
	tmp = (t_flags *)malloc(sizeof(t_flags));
	if (tmp)
	{
		tmp->flag = c;
		tmp->flag_next = NULL;
	}
	return (tmp);
}

static void			ft_flag_push(t_flags **elem, const char c)
{
	t_flags *tmp;

	tmp = *elem;
	while (tmp->flag_next)
		tmp = tmp->flag_next;
	tmp->flag_next = ft_flag_create(c);
}

static void			ft_flag_new(t_printf **elem, const char c)
{
	if (!(*elem)->flag)
	{
		(*elem)->flag = ft_flag_create(c);
		return ;
	}
	ft_flag_push(&(*elem)->flag, c);
}

int 				ft_n_len(int num)
{
	int len;

	len = 0;
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int					ft_fill(t_printf **elem, const char *str)
{
	int 		i;
	int 		c;

	i = 1;
	c = -1;
	while (str[i] != '\0' && ft_type_and(str[i]))
	{
		if (ft_flag(str[i]) && (*elem)->acc == -1)
			ft_flag_new(elem, str[i]);
		else if (ft_isdigit(str[i]) && (*elem)->acc == -1 && (*elem)->width == 0)
		{
			(*elem)->width = ft_atoi(str + i);
			i += ft_n_len((*elem)->width) - 1;
		}
		else if (str[i] == '.' && (*elem)->acc == -1)
		{
			(*elem)->acc = ft_atoi(str + i + 1);
			i += ft_n_len((*elem)->width) - 1;
		}
		else if (ft_len(str[i]) && ++c < 2)
		{
			if ((str[i] == 'h' || str[i] == 'l') && str[i + 1] != 'h' && str[i + 1] != 'l')
			{
				(*elem)->len[c] = str[i];
				c += 10;
			}
			else
				(*elem)->len[c] = str[i];
		}
		i++;
	}
	if (ft_type_or(str[i]))
		(*elem)->type = str[i];
	return (i);
}

t_printf		*ft_printf_new(void)
{
	t_printf *tmp;

	tmp = NULL;
	tmp = (t_printf *)malloc(sizeof(t_printf));
	if (tmp)
	{
		tmp->flag = NULL;
		tmp->width = 0;
		tmp->acc = -1;
		tmp->len[0] = 0;
		tmp->len[1] = 0;
		tmp->type = 0;
	}
	return (tmp);
}