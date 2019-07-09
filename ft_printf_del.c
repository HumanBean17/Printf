#include "libft.h"

static void	ft_del(t_flags **tmp)
{
	if (*tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
}

static void	ft_flag_del(t_flags **alst)
{
	t_flags	*tmp;
	t_flags *cur;

	cur = *alst;
	while (cur)
	{
		tmp = cur;
		ft_del(&cur);
		cur = tmp->flag_next;
	}
	*alst = NULL;
}

void		ft_printf_del(t_printf **to_del)
{
	if (*to_del)
	{
		//ft_flag_del(&((*to_del)->flag));
		free(*to_del);
		*to_del = NULL;
	}
}