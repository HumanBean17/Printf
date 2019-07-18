#include "libft.h"

int 	ft_len(const char c)
{
	if (c == 'h' || c == 'l' || c == 'L')
		return (1);
	return (0);
}

int     ft_len_check(const char c[])
{
	if (c[0] == 'l' || c[1] == 'l')
		return (1);
	else if (c[0] == 'L' || c[1] == 'L')
		return (2);
	return (0);
}