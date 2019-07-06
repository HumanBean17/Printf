/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:29:46 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/06 15:16:53 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*concat_str;

	i = 0;
	concat_str = NULL;
	if (!s1 || !s2)
		return (NULL);
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

char 	*ft_freejoin(char **s1, char **s2)
{
	char *result;
	char *ptr;

	ptr = ft_strdup(*s1);
	ft_strdel(s1);
	result = ft_strjoin(ptr, *s2);
	ft_strdel(s2);
	ft_strdel(&ptr);
	return (result);
}