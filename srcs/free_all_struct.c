/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 12:51:24 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 15:05:58 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	free_all_struct(t_lem_in_file **file, t_lem_in_room **room,
		t_lem_in_ant **ant)
{
	rewind_t_lem_in_file(file);
	rewind_t_lem_in_room(room);
	rewind_t_lem_in_ant(ant);
	if (file)
		del_and_set_to_null_t_lem_in_file(file);
	if (room)
		del_and_set_to_null_t_lem_in_room(room);
	if (ant)
		del_and_set_to_null_t_lem_in_ant(ant);
}
