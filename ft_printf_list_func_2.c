#include "libft.h"

int 	ft_width_mod(t_printf **elem, int i, char *str)
{
	(*elem)->width = ft_atoi(str + i);
	return (ft_n_len((*elem)->width) - 1);
}