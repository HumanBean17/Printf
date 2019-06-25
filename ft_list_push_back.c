/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:31:42 by lcrawn            #+#    #+#             */
/*   Updated: 2019/04/14 17:09:16 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_back(t_list **begin_list,
		void *content, size_t content_size)
{
	t_list *tmp;

	tmp = *begin_list;
	if (tmp == 0)
		tmp = ft_lstnew(content, content_size);
	while (tmp->next != 0)
		tmp = tmp->next;
	tmp->next = ft_lstnew(content, content_size);
}
