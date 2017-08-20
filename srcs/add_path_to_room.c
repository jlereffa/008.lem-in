/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path_to_room.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 15:02:19 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/20 16:40:10 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int	get_rooms_names(char *line, char **room_1_name, char **room_2_name)
{
	int	i;

	i = 0;
	while (line[i] != '-')
		i++;
	if (!(*room_1_name = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	i = -1;
	while (*line != '-' && (++i || !i) && ((*room_1_name)[i] = *line))
		line++;
	(*room_1_name)[i] = '\0';
	i = 0;
	line++;
	while (line[i])
		i++;
	if (!(*room_2_name = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	i = -1;
	while (*line && (++i || !i) && ((*room_2_name)[i] = *line))
		line++;
	(*room_2_name)[i] = '\0';
	return (1);
}

int	add_path_to_room(t_lem_in_room *room, char *line)
{
	char	*room_1_name;
	char	*room_2_name;

	if (!get_rooms_names(line, &room_1_name, &room_2_name))
		return (0);
	while (room->prev && !check_if_str_identical(room->name, room_1_name))
		room = room->prev;
	while (room->next && !check_if_str_identical(room->name, room_1_name))
		room = room->next;
	if (!check_if_str_identical(room->name, room_1_name))
		return (0);
	if (!(room->path = set_t_lem_in_path(room, room->path, room_2_name)))
		return (0);
	while (room->prev && !check_if_str_identical(room->name, room_2_name))
		room = room->prev;
	while (room->next && !check_if_str_identical(room->name, room_2_name))
		room = room->next;
	if (!check_if_str_identical(room->name, room_2_name))
		return (0);
	if (!(room->path = set_t_lem_in_path(room, room->path, room_1_name)))
		return (0);
	return (0);
}
