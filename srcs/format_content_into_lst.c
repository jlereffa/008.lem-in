/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_content_into_lst.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 19:18:36 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/20 18:59:37 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_lem_in_room	*format_content_into_lst(t_lem_in_file *file)
{
	t_lem_in_room	*room;

	room = NULL;
	DEB
	if (!file)
	{
		DEB
		return (0);
	}
	DEB
	while (file)
	{
		DEB
		printf("LOOP : {%s}\n", file->line);
		if (check_if_str_identical(file->line, "##start"))
		{
			DEB
			printf("\033[1;34mSTART : file->next->line : {%s}\n\033[0m", file->next->line);
			if (!(room = set_t_lem_in_room(room, file->next->line, 1, 0)))
			{
				DEB
				return (0);
			}
			file = file->next;
		}
		else if (check_if_str_identical(file->line, "##end"))
		{
			DEB
			printf("\033[1;34mEND : file->next->line : {%s}\n\033[0m", file->next->line);
			if (!(room = set_t_lem_in_room(room, file->next->line, 0, 1)))
			{
				DEB
				return (0);
			}
			DEB
			file = file->next;
		}
		else if (check_room(file->line))
		{
			DEB
			printf("\033[1;34mOTHER : file->next->line : {%s}\n\033[0m", file->line);
			if (!(room = set_t_lem_in_room(room, file->line, 0, 0)))
			{
				DEB
				return (0);
			}
		}
		else if (check_path(file->line))
		{
			DEB
			if (!(add_path_to_room(room, file->line)))
			{
				DEB
				return (0);
			}
		}
		file = file->next;
	}
	return (room);
}
