/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_t_lem_in_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 15:01:49 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/20 18:51:02 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_lem_in_path	*set_t_lem_in_path(
				t_lem_in_room *room, t_lem_in_path *path, char *target_room)
{
	if (!path)
	{
		DEB
		if (!(path = (t_lem_in_path*)malloc(sizeof(t_lem_in_path))))
			return (0);
		DEB
		while (room->prev && !check_if_str_identical(room->name, target_room))
		{
			DEB
			printf("room->name : {%s} | target_room : {%s}\n", room->name, target_room);
			room = room->prev;
		}
		DEB
		while (room->next && !check_if_str_identical(room->name, target_room))
		{
			DEB
			printf("room->name : {%s} | target_room : {%s}\n", room->name, target_room);
			room = room->next;
		}
		DEB
		if (!check_if_str_identical(room->name, target_room))
		{
			DEB
			return (0);
		}
		path->room = room;
		path->prev = 0;
		path->next = 0;
		return (path);
	}
	while (path->next)
		path = path->next;
	if (!(path->next = set_t_lem_in_path(room, path->next, target_room)))
		return (0);
	path->next->prev = path;
	path = path->next;
	return (path);
}
