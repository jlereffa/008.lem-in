/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:29:54 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:29:55 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_lst;
	t_list		*tmp;
	t_list		*result;
	int			i;

	i = 0;
	while (lst)
	{
		if (i == 0)
		{
			tmp = (*f)(lst);
			new_lst = ft_lstnew(tmp->content, tmp->content_size);
			result = new_lst;
		}
		i++;
		if (lst->next)
		{
			tmp = (*f)(lst->next);
			new_lst->next = ft_lstnew(tmp->content, tmp->content_size);
			new_lst = new_lst->next;
		}
		lst = lst->next;
	}
	return (result);
}
