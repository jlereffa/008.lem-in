/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_start_has_path_to_end.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:26:32 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 14:32:16 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	check_if_start_has_path_to_end(t_lem_in_room *room)
{
	t_lem_in_path	*tmp;

	while (room->prev && !room->is_start)
		room = room->prev;
	while (room->next && !room->is_start)
		room = room->next;
	tmp = room->path;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		if (tmp->room->is_end)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
