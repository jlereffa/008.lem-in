/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands_and_comments.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:33:11 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/20 17:03:30 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	check_commands_and_comments(t_lem_in_var *v, t_lem_in_file **file)
{
	DEB
	if (check_if_str_identical((*file)->line, "##start"))
	{
		DEB
		if (!(*file)->next || !(*file)->next->line || !check_room((*file)->next->line))
		{
			DEB
			return (0);
		}
		v->stated_start = 1;
		ft_putendl((*file)->line);
		*file = (*file)->next;
	}
	else if (check_if_str_identical((*file)->line, "##end"))
	{
		DEB
		if (!(*file)->next || !(*file)->next->line || !check_room((*file)->next->line))
		{
			DEB
			return (0);
		}
		v->stated_end = 1;
		ft_putendl((*file)->line);
		*file = (*file)->next;
	}
	else if (*(*file)->line + 1 && (*(*file)->line + 1 != '#' ||
			(*(*file)->line + 2 && *(*file)->line + 1 == '#' &&
			*(*file)->line + 2 == '#')))
	{
		DEB
		ft_putendl((*file)->line);
		*file = (*file)->next;
	}
	DEB
	return (1);
}
