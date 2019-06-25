#include "libft.h"

static void	ft_flag_del(t_flags **alst)
{
	t_flags	*tmp;

	while (*alst)
	{
		tmp = *alst;
		free(alst);
		*alst = tmp->flag_next;
	}
}

void		ft_printf_del(t_printf **to_del)
{
	if (*to_del)
	{
		ft_flag_del(&(*to_del)->flag);
		free(*to_del);
	}
}