#include "libft.h"

char *ft_put_unsigned(unsigned long int n)
{
	int		i;
	char	*c;

	i = 0;
	c = ft_strnew(20);
	if (n == 0)
		c[0] = '0';
	while (n > 0)
	{
		c[i++] = (char)(n % 10 + 48);
		n /= 10;
	}
	return (ft_strrev(c));
}