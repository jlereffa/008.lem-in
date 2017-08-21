/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:38:19 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/21 17:22:53 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	give_value(t_lem_in_room *room, int *start_found)
{
	t_lem_in_path	*tmp;
	//printf("%s | room->name : {%s}\n", __FILE__, room->name);
	if (room->path && !rewind_t_lem_in_path(&room->path))
		return ;
	tmp = room->path;
	while (tmp)
	{
		//printf("\033[1;36mroom[%s]->room[%s]\n\033[0m", room->name, room->path->room->name);
		if ((!tmp->room->value ||
			tmp->room->value > room->value + 1) &&
			!tmp->room->is_end)
			tmp->room->value = room->value + 1;
		if (tmp->room->is_start)
			*start_found = 1;
		else
		{
			if (tmp->room->value > room->value)
				give_value(tmp->room, start_found);
		}
		tmp = tmp->next;
	}
	DEB
}

int	apply_algorithm(t_lem_in_room *room)
{
	int	start_found;

	start_found = 0;
	DEB
	while (room->prev && !room->is_end)
		room = room->prev;
	DEB
	while (room->next && !room->is_end)
		room = room->next;
	DEB
	give_value(room, &start_found);
	DEB
	if (!start_found)
	{
		DEB
		return (0);
	}
	DEB
	return (1);
}
