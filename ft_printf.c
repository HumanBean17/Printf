/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 12:58:03 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/07 13:06:26 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	const char 	*percent;
	int 		print;

	va_start(ap, str);
	print = 0;
	while (*str)
	{
		if ((char)(*str) == '%')
		{
			print += ft_fill_info(str, ap);
			str++;
			while (!ft_type_or(*str))
				str++;
			str++;
		}
		ft_putchar(*str);
		if (*str)
		{
			str++;
			print++;
		}
	}
	va_end(ap);
	return (print);
}
