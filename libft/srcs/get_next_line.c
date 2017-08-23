/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 12:12:22 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 11:26:35 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_gnl	*ft_set_list_gnl(t_gnl *lst, int fd)
{
	if (!lst)
	{
		if (!(lst = (t_gnl*)malloc(sizeof(t_gnl))))
			return (NULL);
		lst->fd = fd;
		lst->ret = 0;
		lst->rest = NULL;
		lst->tmp = NULL;
		lst->ptr = NULL;
		lst->prev = NULL;
		lst->next = NULL;
		return (lst);
	}
	while (lst->prev && lst->fd != fd)
		lst = lst->prev;
	while (lst->next && (lst->fd != fd))
		lst = lst->next;
	if (lst->fd != fd)
	{
		if (!(lst->next = ft_set_list_gnl(lst->next, fd)))
			return (NULL);
		lst->next->prev = lst;
		return (lst->next);
	}
	return (lst);
}

static void		ft_remove_lst_fd(t_gnl **lst)
{
	t_gnl		*tmp;

	tmp = *lst;
	if ((*lst)->prev && (*lst)->next)
	{
		(*lst)->prev->next = (*lst)->next;
		(*lst)->next->prev = (*lst)->prev;
		*lst = (*lst)->prev;
	}
	else if ((*lst)->prev && !(*lst)->next)
	{
		(*lst)->prev->next = NULL;
		*lst = (*lst)->prev;
	}
	else if (!(*lst)->prev && (*lst)->next)
	{
		(*lst)->next->prev = NULL;
		*lst = (*lst)->next;
	}
	else
		*lst = NULL;
	free(tmp);
}

static int		handle_rest(t_gnl *lst, char **line)
{
	if (!(*line = ft_strdup_n(lst->rest, (lst->ptr - lst->rest))))
		return (-1);
	lst->tmp = lst->rest;
	lst->rest = lst->ptr;
	if (*(lst->rest + 1))
	{
		if (!(lst->rest = ft_strdup(lst->rest + 1)))
			return (-1);
	}
	else
		lst->rest = NULL;
	free(lst->tmp);
	return (1);
}

static int		handle_last_flush(t_gnl **lst, char **line)
{
	if (!(*line = ft_strdup((*lst)->rest)))
		return (-1);
	free((*lst)->rest);
	ft_remove_lst_fd(lst);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*lst;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!(lst = ft_set_list_gnl(lst, fd)))
		return (-1);
	*line = NULL;
	if (lst->rest && (lst->ptr = ft_strchr(lst->rest, '\n')))
		return (handle_rest(lst, line));
	while ((lst->ret = read(lst->fd, lst->buf, BUFF_SIZE)) > 0)
	{
		if (!(ft_strrealloc_more(&lst->rest, lst->ret)))
			return (-1);
		lst->rest = ft_strncat(lst->rest, lst->buf, lst->ret);
		if ((lst->ptr = ft_strchr(lst->rest, '\n')))
			return (handle_rest(lst, line));
	}
	if (lst->ret < 0)
		return (-1);
	if (lst->rest)
		return (handle_last_flush(&lst, line));
	return (0);
}
