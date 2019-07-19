/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:29:46 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 11:01:40 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*concat_str;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup((char *) s2));
	else if (!s2)
		return (ft_strdup((char *) s1));
	concat_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!concat_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		concat_str[i] = s1[i];
		i++;
	}
	concat_str = ft_strcat(concat_str, s2);
	return (concat_str);
}

char	*ft_strcat(char *dst, const char *app)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (dst[i] != '\0')
		i++;
	while (app[k] != '\0')
	{
		dst[i] = app[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (dst);
}