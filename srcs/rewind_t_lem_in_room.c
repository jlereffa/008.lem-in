/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewind_t_lem_in_room.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:31:31 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/20 16:41:49 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	rewind_t_lem_in_room(t_lem_in_room **room)
{
	if (!room || !*room)
		return (0);
	while ((*room)->prev)
		*room = (*room)->prev;
	return (1);
}
