/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <lcrawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:04:32 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/06 16:38:51 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_strcpy_end(char *destination, const char *source)
{
	int end_d;
	int end_s;

	end_d = ft_strlen(destination) - 1;
	end_s = ft_strlen(source) - 1;
	while (end_s >= 0 && end_d >= 0)
	{
		destination[end_d] = source[end_s];
		end_d--;
		end_s--;
	}
	return (destination);
}

char	*ft_strcpy_n(char *destination, const char *source)
{
	int i;

	i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}

char	*ft_strcpy(char *destination, const char *source)
{
	int i;

	i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = source[i];
	return (destination);
}
