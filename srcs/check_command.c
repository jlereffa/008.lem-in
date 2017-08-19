/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:33:11 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/19 16:33:26 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	check_command(t_lem_in_var *v, t_lem_in_file *file)
{
	if (check_if_str_strictly_identical(file->line, "##start"))
	{
		//check line->next, has to be a correct room.
		if (!)
			return (0);
		v->stated_start = 1;
	}
	else if (check_if_str_strictly_identical(file->line, "##end"))
	{
		//check line->next, has to be a correct room.
		if (!)
			return (0);
		v->stated_end = 1;
	}
}
