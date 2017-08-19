/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:09:30 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/19 19:01:29 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	parse_content(t_lem_in_var *v, t_lem_in_file *file)
{
	int	ret;
	int	ret2;

	ret = 0;
	if (!check_ants_nb(v, file->line) || !(file = file->next))
		return (0);
	while (file)
	{
		if (!file->line || !*(file)->line || *(file)->line == '#' &&
			!check_command_and_comments(v, file))
			return (0);
		else
		{
			if (!ret && !(ret = check_if_room_or_path(file->line) &&
				!(ret2 = ret)))
				return (0);
			else if (ret && ret > ret2 = check_if_room_or_path(file->line))
				return (0);
			v->has_room = ret2 == 1 ? 1 : v->has_room;
			v->has_path = ret2 == 2 ? 1 : v->has_path;
		}
		file = file->next;
	}
	return (1);
}
