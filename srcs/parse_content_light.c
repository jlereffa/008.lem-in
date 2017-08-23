/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:09:30 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 13:41:37 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	set_room_and_path_counters(int *has_room, int *has_path, int ret2)
{
	*has_room = ret2 == 1 ? 1 : *has_room;
	*has_path = ret2 == 2 ? 1 : *has_path;
}

int			parse_content_light(t_lem_in_var *v, t_lem_in_file *file)
{
	int	ret;
	int	ret2;

	ret = 0;
	if (!check_ants_nb(v, file->line) || !(file = file->next))
		return (0);
	while (file)
	{
		if (!file->line || !*(file)->line || (*(file)->line == '#' &&
			!check_commands_and_comments(v, &file)))
			return (0);
		else
		{
			if (file && !ret && !(ret = check_if_room_or_path(file->line) &&
				!(ret2 = ret)))
				return (print_error_msg(ER_NOT_A_VALID_LINE));
			else if (file && ret && ret > (ret2 =
					check_if_room_or_path(file->line)))
				return (print_error_msg(ER_ROOM_IN_PATH));
			set_room_and_path_counters(&v->has_room, &v->has_path, ret2);
		}
		file ? ft_putendl(file->line) : 0;
		file = file ? file->next : file;
	}
	return (1);
}
