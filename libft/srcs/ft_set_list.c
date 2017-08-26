/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:37:45 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:37:47 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_set_list(t_list *lst, void *content, size_t content_size)
{
	t_list		*tmp;

	if (!lst)
	{
		if (!(lst = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		lst->content = content;
		lst->content_size = content_size;
		lst->next = NULL;
		return (lst);
	}
	else
	{
		tmp = lst;
		while (lst->next)
			lst = lst->next;
		lst->next = ft_set_list(lst->next, content, content_size);
	}
	return (tmp);
}
