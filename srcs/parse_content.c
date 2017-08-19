/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:09:30 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/19 16:34:34 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	parse_content(t_lem_in_var *v, t_lem_in_file *file)
{
	if (!check_ants_nb(v, file->line))
		return (0);
	file = file->next;
	while (file)
	{
		if (*(file)->line == '#' && !check_command(file))
			return (0);
		else
	}
	return (1);
}
