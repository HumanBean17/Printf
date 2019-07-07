#include "libft.h"

char *ft_put_unsigned_llong(unsigned long long int n, int round)
{
    int		i;
    char	*c;
    char 	*result;

	if (round == 0 && n == 0)
		return (NULL);
    i = 0;
    c = ft_strnew(20);
    if (n == 0)
        c[0] = '0';
    while (n > 0)
    {
        c[i++] = (char)(n % 10 + 48);
        n /= 10;
    }
	result = ft_round_dioux(&c, round);
	return (result);
}

char *ft_put_unsigned_long(unsigned long int n, int round)
{
    int		i;
    char	*c;
    char 	*result;

	if (round == 0 && n == 0)
		return (NULL);
    i = 0;
    c = ft_strnew(20);
    if (n == 0)
        c[0] = '0';
    while (n > 0)
    {
        c[i++] = (char)(n % 10 + 48);
        n /= 10;
    }
	result = ft_round_dioux(&c, round);
	return (result);
}

char *ft_put_unsigned_char(unsigned char n, int round)
{
    int		i;
    char	*c;
    char 	*result;

	if (round == 0 && n == 0)
		return (NULL);
    i = 0;
    c = ft_strnew(20);
    if (n == 0)
        c[0] = '0';
    while (n > 0)
    {
        c[i++] = (char)(n % 10 + 48);
        n /= 10;
    }
	result = ft_round_dioux(&c, round);
	return (result);
}

char *ft_put_unsigned_short(unsigned short int n, int round)
{
    int		i;
    char	*c;
    char 	*result;

	if (round == 0 && n == 0)
		return (NULL);
    i = 0;
    c = ft_strnew(20);
    if (n == 0)
        c[0] = '0';
    while (n > 0)
    {
        c[i++] = (char)(n % 10 + 48);
        n /= 10;
    }
	result = ft_round_dioux(&c, round);
	return (result);
}

char *ft_put_unsigned(unsigned int n, int round)
{
	int		i;
	char	*c;
	char 	*result;

	if (round == 0 && n == 0)
		return (NULL);
	i = 0;
	c = ft_strnew(20);
	if (n == 0)
		c[0] = '0';
	while (n > 0)
	{
		c[i++] = (char)(n % 10 + 48);
		n /= 10;
	}
	result = ft_round_dioux(&c, round);
	return (result);
}