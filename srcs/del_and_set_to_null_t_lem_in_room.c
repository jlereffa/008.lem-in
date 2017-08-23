/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_and_set_to_null_t_lem_in_room.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:09:52 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 13:36:21 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	handle_existing_prev_and_existing_next(t_lem_in_room **room)
{
	(*room)->prev->next = (*room)->next;
	(*room)->next->prev = (*room)->prev;
	*room = (*room)->prev;
}

static void	handle_existing_prev_and_null_next(t_lem_in_room **room)
{
	(*room)->prev->next = 0;
	*room = (*room)->prev;
}

static void handle_null_prev_and_existing_next(t_lem_in_room **room)
{
	(*room)->next->prev = 0;
	*room = (*room)->next;
}

void		del_and_set_to_null_t_lem_in_room(t_lem_in_room **room)
{
	t_lem_in_room *tmp;

	while (*room)
	{
		tmp = *room;
		free((*room)->name);
		del_and_set_to_null_t_lem_in_path(&(*room)->path);
		if ((*room)->prev && (*room)->next)
			handle_existing_prev_and_existing_next(room);
		else if ((*room)->prev && !(*room)->next)
			handle_existing_prev_and_null_next(room);
		else if (!(*room)->prev && (*room)->next)
			handle_null_prev_and_existing_next(room);
		else
		{
			free(tmp);
			*room = NULL;
			return ;
		}
		free(tmp);
		*room = (*room)->next;
	}
}
