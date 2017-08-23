/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants_out_easy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:54:27 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 18:25:09 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	get_ants_out_easy(int *ant_nb, t_lem_in_ant *ant, t_lem_in_room *room)
{
	while (room->prev && !room->is_end)
		room = room->prev;
	while (room->next && !room->is_end)
		room = room->next;
	while (*ant_nb)
	{
		ft_putstr(ant->name);
		ft_putstr(room->name);
		if (ant->next)
			ft_putstr(" ");
		ant = ant->next;
		(*ant_nb)--;
	}
	ft_putendl("");
}
