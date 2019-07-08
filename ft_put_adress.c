#include "libft.h"

char 	*ft_put_address(unsigned long s)
{
    char *base;
    char *result;

    base = ft_base_long(s, 16, 0);
    if (base)
    	result = ft_strjoin("0x", base);
    else
    	result = ft_strdup("0x0");
    if (base)
    	ft_strdel(&base);
	return (result);
}