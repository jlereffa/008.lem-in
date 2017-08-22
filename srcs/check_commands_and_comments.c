/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands_and_comments.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:33:11 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/22 17:06:57 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int	check_start_end_room(t_lem_in_var *v, t_lem_in_file **file, char *s)
{
	ft_putendl(s);
	while (*file)
	{
		ft_putendl((*file)->line);
		if (check_if_str_identical((*file)->line, "##start") ||
			check_if_str_identical((*file)->line, "##end") ||
			(*(*file)->line != '#' && !check_room((*file)->line)))
			return (0);
		if (check_room((*file)->line))
		{
			v->has_room = 1;
			return (1);
		}
		*file = (*file)->next;
	}
	return (0);
}

int			check_commands_and_comments(t_lem_in_var *v, t_lem_in_file **file)
{
	while (*file && *(*file)->line == '#')
	{
		if (check_if_str_identical((*file)->line, "##start"))
		{
			if (!(*file)->next || !(*file)->next->line ||
				!check_start_end_room(v, &(*file)->next, "##start"))
				return (0);
			v->stated_start = 1;
			if (*file)
				*file = (*file)->next;
		}
		else if (check_if_str_identical((*file)->line, "##end"))
		{
			if (!(*file)->next || !(*file)->next->line ||
				!check_start_end_room(v, &(*file)->next, "##end"))
				return (0);
			v->stated_end = 1;
			if (*file)
				*file = (*file)->next;
		}
		else
			ft_putendl((*file)->line);
		*file = (*file)->next;
	}
	return (1);
}
