/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_content_into_lst.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 19:18:36 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/19 20:48:27 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_lem_in_room	*set_t_lem_in_room(
				t_lem_in_room *room, int is_start_or_end)
{

}

int	format_content_into_lst(t_lem_in_file *file)
{
	t_lem_in_room	*room;

	room = NULL;
	if (!file)
		return (0);
	while (file)
	{
		if (check_if_str_strictly_identical(file->line, "##start"))
		{
			if (!set_t_lem_in_room(room, file->next->line, 1))
				return (0);
			file = file->next;
		}
		else if (check_if_str_strictly_identical(file->line, "##end"))
		{
			if (!set_t_lem_in_room(room, file->next->line, 2))
				return (0);
			file = file->next;
		}
		else if (check_room(file->line))
		{
			if (!set_t_lem_in_room(room, file->next->line, 0))
				return (0);
		}
		else if (check_path(file->line))
		{
			if (add_path_to_room(room, file->line))
		}
		file = file->next;
	}
	return (1);
}
