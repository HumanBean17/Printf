/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 12:58:03 by lcrawn            #+#    #+#             */
/*   Updated: 2019/06/04 12:45:11 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	const char 	*percent;
	int 		print;

	va_start(ap, str);
	print = 1;
	while (*str)
	{
		if ((char)(*str) == '%')
			str += ft_fill_info(str, ap);
		ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (0);
}
