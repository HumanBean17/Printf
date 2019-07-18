#include "libft.h"

char *ft_long_min(long int n)
{
	char *c;

	if (n == -2147483648)
	{
		c = ft_strdup("-2147483648");
		return (c);
	}
	else if (n == (-9223372036854775807 - 1))
	{
		c = ft_strdup("-9223372036854775808");
		return (c);
	}
	return (NULL);
}

char *ft_putnbr_llong(long long int n, int round)
{
	long long int	num;
	int				i;
	char			*c;
	char 			*result;

	if (round == 0 && n == 0)
		return (NULL);
	if (n == -9223372036854775807 - 1)
	{
		c = ft_strdup("-9223372036854775808");
		return (c);
	}
	c = ft_strnew(21);
	i = 0;
	if (n == 0)
		c[0] = '0';
	if (n < 0)
	{
		c[ft_n_len(n)] = '-';
		n *= -1;
	}
	num = (long long int)n;
	while (num > 0)
	{
		c[i++] = (char)(num % 10 + 48);
		num /= 10;
	}
	result = ft_round_dioux(&c, round);
	return (result);
}

char *ft_putnbr_long(long int n, int round)
{
	long int	num;
	int			i;
	char		*c;
	char 		*result;

	if (round == 0 && n == 0)
		return (NULL);
	if ((c = ft_long_min(n)))
		return (c);
	c = ft_strnew(21);
	i = 0;
	if (n == 0)
		c[0] = '0';
	if (n < 0)
	{
		c[ft_n_len(n)] = '-';
		n *= -1;
	}
	num = (long int)n;
	while (num > 0)
	{
		c[i++] = (char)(num % 10 + 48);
		num /= 10;
	}
	result = ft_round_dioux(&c, round);
	return (result);
}

char *ft_putnbr_signed(signed char n, int round)
{
	signed char		num;
	int				i;
	char			*c;
	char 			*result;

	if (round == 0 && n == 0)
		return (NULL);
	if (n == -128)
	{
		c = ft_strdup("-128");
		return (c);
	}
	c = ft_strnew(21);
	i = 0;
	if (n == 0)
		c[0] = '0';
	if (n < 0)
	{
		c[ft_n_len(n)] = '-';
		n *= -1;
	}
	num = (signed char)n;
	while (num > 0)
	{
		c[i++] = (char)(num % 10 + 48);
		num /= 10;
	}
	result = ft_round_dioux(&c, round);
	return (result);
}

char *ft_putnbr_short(short n, int round)
{
	short	num;
	int 	i;
	char 	*c;
	char 	*result;

	if (round == 0 && n == 0)
		return (NULL);
	if (n == -32768)
	{
		c = ft_strdup("-32768");
		return (c);
	}
	c = ft_strnew(21);
	i = 0;
	if (n == 0)
		c[0] = '0';
	if (n < 0)
	{
		c[ft_n_len(n)] = '-';
		n *= -1;
	}
	num = (short)n;
	while (num > 0)
	{
		c[i++] = (char)(num % 10 + 48);
		num /= 10;
	}
	result = ft_round_dioux(&c, round);
	return (result);
}