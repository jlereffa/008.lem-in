/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path_to_room.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 15:02:19 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/22 14:48:21 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int	get_rooms_names(char *line, char **room_1_name, char **room_2_name)
{
	int	i;

	i = 0;
	putf("line : {", line);
	putf("}\n", "");
	while (line[i] != '-')
		i++;
	if (!(*room_1_name = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	i = -1;
	while (*line != '-' && (++i + 1) && ((*room_1_name)[i] = *line))
		line++;
	//printf("i : {%d}\n", i);
	(*room_1_name)[i + 1] = '\0';
	//printf("room_1_name : {%s}\n", *room_1_name);
	i = 0;
	line++;
	while (line[i])
		i++;
	if (!(*room_2_name = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	i = -1;
	while (*line && (++i + 1) && ((*room_2_name)[i] = *line))
		line++;
	(*room_2_name)[i + 1] = '\0';
	return (1);
}

int	add_path_to_room(t_lem_in_room *room, char *line)
{
	char	*room_1_name;
	char	*room_2_name;

	DEB
	if (!get_rooms_names(line, &room_1_name, &room_2_name))
		return (0);
	/*printf("\033[35m");
	printf("%s | room_1_name : {%s}\n",__FILE__, room_1_name);
	printf("%s | room_2_name : {%s}\n",__FILE__, room_2_name);
	printf("\033[0m");
	*/DEB
	while (room->prev && !check_if_str_identical(room->name, room_1_name))
		room = room->prev;
	DEB
	while (room->next && !check_if_str_identical(room->name, room_1_name))
		room = room->next;
	DEB
	if (!check_if_str_identical(room->name, room_1_name))
	{
		DEB
		//printf("%s | room->name : {%s} | room_1_name {%s}\n", __FILE__, room->name, room_1_name);
		return (0);
	}
	DEB
	if (!(room->path = set_t_lem_in_path(room, room->path, room_2_name)))
	{
		DEB
		return (0);
	}
	DEB
	while (room->prev && !check_if_str_identical(room->name, room_2_name))
		room = room->prev;
	DEB
	while (room->next && !check_if_str_identical(room->name, room_2_name))
		room = room->next;
	DEB
	if (!check_if_str_identical(room->name, room_2_name))
	{
		DEB
		return (0);
	}
	DEB
	if (!(room->path = set_t_lem_in_path(room, room->path, room_1_name)))
	{
		DEB
		return (0);
	}
	DEB
	return (1);
}
