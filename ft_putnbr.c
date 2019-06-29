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

char 	*ft_putnbr(int n)
{
	unsigned long int	num;
	int					i;
	char				*c;

	c = ft_strnew(21);
	i = 0;
	if (n == -2147483648)
	{
		c = "-2147483648";
		return (0);
	}
	if (n == 0)
		c[0] = '0';
	if (n < 0)
	{
		c[ft_n_len(n)] = '-';
		n *= -1;
	}
	num = (unsigned long int)n;
	while (num > 0)
	{
		c[i++] = (char)(num % 10 + 48);
		num /= 10;
	}
	return (ft_strrev(c));
}
