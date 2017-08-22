/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:38:19 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/22 17:11:01 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	give_value(t_lem_in_room *room, int *start_found)
{
	t_lem_in_path	*tmp;

	if (room->path && !rewind_t_lem_in_path(&room->path))
		return ;
	tmp = room->path;
	while (tmp)
	{
		if ((!tmp->room->value ||
			tmp->room->value > room->value + 1) &&
			!tmp->room->is_end)
			tmp->room->value = room->value + 1;
		if (tmp->room->is_start)
			*start_found = 1;
		if (tmp->room->value > room->value)
			give_value(tmp->room, start_found);
		tmp = tmp->next;
	}
}

int			apply_algorithm(t_lem_in_room *room)
{
	int	start_found;

	start_found = 0;
	while (room->prev && !room->is_end)
		room = room->prev;
	while (room->next && !room->is_end)
		room = room->next;
	give_value(room, &start_found);
	if (!start_found)
		return (0);
	return (1);
}
