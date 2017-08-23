/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path_to_room.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 15:02:19 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 17:13:12 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int	free_no_matter_what_and_return_null(char **s1, char **s2)
{
	if (*s1)
		free(*s1);
	if (*s2)
		free(*s2);
	return (0);
}

static int	get_rooms_names(char *line, char **room1_name, char **room2_name)
{
	int	i;

	i = 0;
	while (line[i] != '-')
		i++;
	if (!(*room1_name = (char*)malloc(sizeof(char) * i + 1)))
		return (print_error_msg(ER_MALLOC));
	i = -1;
	while (*line != '-' && (++i + 1) && ((*room1_name)[i] = *line))
		line++;
	(*room1_name)[i + 1] = '\0';
	i = 0;
	line++;
	while (line[i])
		i++;
	if (!(*room2_name = (char*)malloc(sizeof(char) * i + 1)))
		return (print_error_msg(ER_MALLOC));
	i = -1;
	while (*line && (++i + 1) && ((*room2_name)[i] = *line))
		line++;
	(*room2_name)[i + 1] = '\0';
	return (1);
}

int			add_path_to_room(t_lem_in_room *room, char *line)
{
	char	*room1_name;
	char	*room2_name;

	room1_name = NULL;
	room2_name = NULL;
	if (!get_rooms_names(line, &room1_name, &room2_name))
		return (0);
	while (room->prev && !check_if_str_identical(room->name, room1_name))
		room = room->prev;
	while (room->next && !check_if_str_identical(room->name, room1_name))
		room = room->next;
	if (!check_if_str_identical(room->name, room1_name))
		return (free_no_matter_what_and_return_null(&room1_name, &room2_name));
	if (!(room->path = set_t_lem_in_path(room, room->path, room2_name)))
		return (free_no_matter_what_and_return_null(&room1_name, &room2_name));
	while (room->prev && !check_if_str_identical(room->name, room2_name))
		room = room->prev;
	while (room->next && !check_if_str_identical(room->name, room2_name))
		room = room->next;
	if (!check_if_str_identical(room->name, room2_name))
		return (free_no_matter_what_and_return_null(&room1_name, &room2_name));
	if (!(room->path = set_t_lem_in_path(room, room->path, room1_name)))
		return (free_no_matter_what_and_return_null(&room1_name, &room2_name));
	free_no_matter_what_and_return_null(&room1_name, &room2_name);
	return (1);
}
