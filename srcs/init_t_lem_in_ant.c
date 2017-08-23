/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_lem_in_ant.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:13:35 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 13:30:55 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_lem_in_ant	*init_t_lem_in_ant(int ant_nb, t_lem_in_room *room)
{
	int				nb;
	t_lem_in_ant	*ant;

	nb = 1;
	ant = 0;
	while (room->prev && !room->is_start)
		room = room->prev;
	while (room->next && !room->is_start)
		room = room->next;
	while (nb <= ant_nb)
	{
		if (!(ant = set_t_lem_in_ant(ant, nb, room)) &&
			!print_error_msg(ER_MALLOC))
			return (0);
		nb++;
	}
	if (!rewind_t_lem_in_ant(&ant) && !print_error_msg(ER_REWIND))
		return (0);
	return (ant);
}
