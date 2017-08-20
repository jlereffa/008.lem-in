/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands_and_comments.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:33:11 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/20 16:29:32 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	check_commands_and_comments(t_lem_in_var *v, t_lem_in_file *file)
{
	if (check_if_str_identical(file->line, "##start"))
	{
		if (!file->next || !file->next->line || !check_room(file->next->line))
			return (0);
		v->stated_start = 1;
		ft_putendl(file->line);
	}
	else if (check_if_str_identical(file->line, "##end"))
	{
		if (!file->next || !file->next->line || !check_room(file->next->line))
			return (0);
		v->stated_end = 1;
		ft_putendl(file->line);
	}
	else if (*(file)->line + 1 && (*(file)->line + 1 != '#' ||
			(*(file)->line + 2 && *(file)->line + 1 == '#' &&
			*(file)->line + 2 == '#')))
		ft_putendl(file->line);
	return (1);
}
