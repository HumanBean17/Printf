/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:34 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/08 13:18:45 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (n == -2147483648)
	{
		c = ft_strdup("-2147483648");
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

char *ft_putnbr(int n, int round)
{
	int                     num;
	int					    i;
	char				    *c;
	char 					*result;

	if (round == 0 && n == 0)
		return (NULL);
	if (n == -2147483648)
	{
		c = ft_strdup("-2147483648");
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
	num = (int)n;
	while (num > 0)
	{
		c[i++] = (char)(num % 10 + 48);
		num /= 10;
	}
	result = ft_round_dioux(&c, round);
	return (result);
}

char *ft_round_dioux(char **num, int round)
{
	char 			*r;
	char 			*result;
	int 			len;
	int 			flag;

	len = ft_strlen(*num);
	flag = 0;
	ft_strrev(*num);
	if ((*num)[0] == '-')
	{
		flag = 1;
		round++;
	}
	r = round - len > 0 ? ft_strnew_n(round - len, '0') : ft_strnew(1);
	r[0] = flag == 1 && r[0] != '\0' ? '-' : r[0];
	(*num)[0] = round - len > 0 && flag == 1 ? '0' : (*num)[0];
	result = ft_strjoin(r, *num);
	ft_strdel(&r);
	ft_strdel(num);
	return (result);
}
