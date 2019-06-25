/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:39:28 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/14 17:14:29 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_find(t_list *begin_list, void *content, int (*cmp)())
{
	t_list *tmp;

	tmp = begin_list;
	while (cmp(content, tmp->content) != 0)
		tmp = tmp->next;
	return (tmp);
}
