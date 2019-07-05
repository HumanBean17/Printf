/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:34 by lcrawn            #+#    #+#             */
/*   Updated: 2019/06/07 17:00:56 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_putnbr_llong(long long int n)
{
    long long int           num;
    int					    i;
    char				    *c;

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
    return (ft_strrev(c));
}

char 	*ft_putnbr_long(long int n)
{
    long int                num;
    int					    i;
    char				    *c;

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
    return (ft_strrev(c));
}

char 	*ft_putnbr_signed(signed char n)
{
    signed char             num;
    int					    i;
    char				    *c;

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
    return (ft_strrev(c));
}

char 	*ft_putnbr_short(short n)
{
    short                   num;
    int					    i;
    char				    *c;

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
    return (ft_strrev(c));
}

char 	*ft_putnbr(int n)
{
	int                     num;
	int					    i;
	char				    *c;

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
	return (ft_strrev(c));
}
