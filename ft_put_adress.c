#include "libft.h"

char 	*ft_put_address(unsigned long s)
{
    char *base;
    char *result;

    base = ft_base(s, 16, 0);
    result = ft_strjoin("0x", base);
    ft_strdel(&base);
	return (result);
}