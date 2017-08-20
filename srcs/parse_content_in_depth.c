/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content_in_depth.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 19:09:43 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/20 15:45:28 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int	check_if_room_has_double(t_lem_in_room *room)
{
	char	*name;
	int		found;

	name = room->name;
	found = 0;
	while (room->prev)
		room = room->prev;
	while (room)
	{
		if (check_if_str_identical(name, room->name))
			found++;
		room = room->next;
	}
	if (found > 1)
		return (0);
	return (1);
}

static int	check_if_room_has_same_coord(t_lem_in_room *room)
{
	int	coord_x;
	int	coord_y;
	int	found;

	coord_x = room->coord_x;
	coord_y = room->coord_y;
	found = 0;
	while (room->prev)
		room = room->prev;
	while (room)
	{
		if (coord_x == room->coord_x && coord_y == room->coord_y)
			found++;
		room = room->next;
	}
	if (found > 1)
		return (0);
	return (1);
}

static int	check_if_room_path_has_double(t_lem_in_path *path)
{
	char			*name;
	int				found;
	t_lem_in_path	*tmp;

	while (path)
	{
		name = path->name;
		found = 0;
		tmp = path;
		while (tmp->prev)
			tmp = tmp->prev;
		while (tmp)
		{
			if (check_if_str_identical(name, tmp->name)
			tmp = tmp->next;
		}

	}
}

int			parse_content_in_depth(t_lem_in_var *v, t_lem_in_room *rooms)
{
	int	start_nb;
	int	end_nb;

	start_nb = 0;
	end_nb = 0;
	if (!rewind_t_lem_in_room(&room))
		return (0);
	while (room)
	{
		if (room->stated_start && start_nb += 1 && start_nb > 1 ||
			room->stated_end && end_nb += 1 && end_nb > 1)
			return (0);
		if (!rewind_t_lem_in_path(&room->path))
			return (0);
		if (!check_if_room_has_double(room))
			return (0);
		if (!check_if_room_has_same_coord(room))
			return (0);
		if (!check_if_room_path_has_double(room->path))
			return (0);
		if ((room->stated_start || room->stated_end) && !room->path)
			return (0);
		room = room->next;
	}
	return (1);
}
