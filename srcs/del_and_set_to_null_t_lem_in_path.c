/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_and_set_to_null_t_lem_in_path.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:09:52 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 14:41:37 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	handle_existing_prev_and_existing_next(t_lem_in_path **path)
{
	(*path)->prev->next = (*path)->next;
	(*path)->next->prev = (*path)->prev;
	*path = (*path)->prev;
}

static void	handle_existing_prev_and_null_next(t_lem_in_path **path)
{
	(*path)->prev->next = 0;
	*path = (*path)->prev;
}

static void	handle_null_prev_and_existing_next(t_lem_in_path **path)
{
	(*path)->next->prev = 0;
	*path = (*path)->next;
}

void		del_and_set_to_null_t_lem_in_path(t_lem_in_path **path)
{
	t_lem_in_path *tmp;

	while (*path)
	{
		tmp = *path;
		(*path)->room = 0;
		if ((*path)->prev && (*path)->next)
			handle_existing_prev_and_existing_next(path);
		else if ((*path)->prev && !(*path)->next)
			handle_existing_prev_and_null_next(path);
		else if (!(*path)->prev && (*path)->next)
			handle_null_prev_and_existing_next(path);
		else
		{
			free(tmp);
			*path = NULL;
			return ;
		}
		free(tmp);
		*path = (*path)->next;
	}
}
