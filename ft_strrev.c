/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:25:02 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 10:11:52 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char				*ft_strrrev(char *str, int flag)
{
	int i;
	int k;

	i = (flag == -1) ? 1 : 0;
	k = (flag == -1) ? 1 : 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (i > k)
	{
		str[k] += str[i];
		str[i] = str[k] - str[i];
		str[k] -= str[i];
		k++;
		i--;
	}
	return (str);
}
