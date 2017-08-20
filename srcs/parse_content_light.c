/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:09:30 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/20 17:10:06 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	parse_content_light(t_lem_in_var *v, t_lem_in_file *file)
{
	int	ret;
	int	ret2;

	ret = 0;
	DEB
	if (!check_ants_nb(v, file->line) || !(file = file->next))
		return (0);
	DEB
	while (file)
	{
		DEB
		if (!file->line || !*(file)->line || (*(file)->line == '#' &&
			!check_commands_and_comments(v, &file)))
		{
			DEB
			return (0);
		}
		else
		{
			DEB
			if (file && !ret && !(ret = check_if_room_or_path(file->line) &&
				!(ret2 = ret)))
			{
				DEB
				return (0);
			}
			else if (file && ret && ret > (ret2 = check_if_room_or_path(file->line)))
			{
				DEB
				return (0);
			}
			v->has_room = ret2 == 1 ? 1 : v->has_room;
			v->has_path = ret2 == 2 ? 1 : v->has_path;
		}
		DEB
		file = file ? file->next : file;
	}
	DEB
	return (1);
}
