/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <lcrawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:34:19 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/07 16:49:58 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_strdup_n(const char *str, int round)
{
	char	*cp_str;
	int		i;

	if (!str)
	{
		cp_str = ft_strnew(6);
		ft_strcpy(cp_str, "(null)");
		return (cp_str);
	}
	i = 0;
	round = round < 0 ? ft_strlen(str) : round;
	cp_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (cp_str)
	{
		while (str[i] != '\0' && round > 0)
		{
			cp_str[i] = str[i];
			i++;
			round--;
		}
		cp_str[i] = '\0';
	}
	return (cp_str);
}

char	*ft_strdup(const char *str)
{
	char	*cp_str;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	cp_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (cp_str)
	{
		while (str[i] != '\0')
		{
			cp_str[i] = str[i];
			i++;
		}
		cp_str[i] = '\0';
	}
	return (cp_str);
}
