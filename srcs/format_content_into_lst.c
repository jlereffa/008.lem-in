/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_content_into_lst.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 19:18:36 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/22 17:16:43 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int		check_file_line(t_lem_in_file **file, t_lem_in_room **room)
{
	if (check_if_str_identical((*file)->line, "##start"))
	{
		if (!(*room = set_t_lem_in_room(*room, (*file)->next->line, 1, 0)))
			return (0);
		*file = (*file)->next;
	}
	else if (check_if_str_identical((*file)->line, "##end"))
	{
		if (!(*room = set_t_lem_in_room(*room, (*file)->next->line, 0, 1)))
			return (0);
		*file = (*file)->next;
	}
	else if (check_room((*file)->line))
	{
		if (!(*room = set_t_lem_in_room(*room, (*file)->line, 0, 0)))
			return (0);
	}
	else if (check_path((*file)->line))
	{
		if (!(add_path_to_room(*room, (*file)->line)))
			return (0);
	}
	return (1);
}

t_lem_in_room	*format_content_into_lst(t_lem_in_file *file)
{
	t_lem_in_room	*room;

	room = NULL;
	if (!file)
		return (0);
	while (file)
	{
		if (!(check_file_line(&file, &room)))
			return (0);
		file = file->next;
	}
	return (room);
}
