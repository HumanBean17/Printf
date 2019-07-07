/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:34 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/07 14:59:14 by lcrawn           ###   ########.fr       */
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

	len = ft_strlen(*num);
	if (round - len > 0)
		r = ft_strnew_n(round - len, '0');
	else
		r = ft_strnew(1);
	ft_strrev(*num);
	result = ft_strjoin(r, *num);
	ft_strdel(&r);
	ft_strdel(num);
	return (result);
}
