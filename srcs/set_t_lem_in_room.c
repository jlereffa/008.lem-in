/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_t_lem_in_room.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 14:03:06 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/20 16:35:34 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static char		*get_name_from_line(char *line)
{
	char	*name;
	int		i;

	i = 0;
	while (line[i] != ' ')
		i++;
	if (!(name = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (line[i] != ' ')
	{
		name[i] = line[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

static int		get_coord_x_from_line(char *line)
{
	while (*line != ' ')
		line++;
	line++;
	return (ft_atoi(line));
}

static int		get_coord_y_from_line(char *line)
{
	while (*line != ' ')
		line++;
	line++;
	while (*line != ' ')
		line++;
	line++;
	return (ft_atoi(line));
}

t_lem_in_room	*set_t_lem_in_room(
				t_lem_in_room *room, char *line, int is_start, int is_end)
{
	if (!room)
	{
		if (!(room = (t_lem_in_room*)malloc(sizeof(t_lem_in_room))))
			return (0);
		if (!(room->name = get_name_from_line(line)))
			return (0);
		room->coord_x = get_coord_x_from_line(line);
		room->coord_y = get_coord_y_from_line(line);
		room->is_start = is_start;
		room->is_end = is_end;
		room->path = NULL;
		room->prev = NULL;
		room->next = NULL;
		return (room);
	}
	while (room->next)
		room = room->next;
	if (!(room->next = set_t_lem_in_room(room->next, line, is_start, is_end)))
		return (0);
	room->next->prev = room;
	room = room->next;
	return (room);
}
