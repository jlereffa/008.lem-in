/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_and_set_to_null_t_lem_in_file.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:09:52 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 13:33:52 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	handle_existing_prev_and_existing_next(t_lem_in_file **file)
{
	(*file)->prev->next = (*file)->next;
	(*file)->next->prev = (*file)->prev;
	*file = (*file)->prev;
}

static void	handle_existing_prev_and_null_next(t_lem_in_file **file)
{
	(*file)->prev->next = 0;
	*file = (*file)->prev;
}

static void handle_null_prev_and_existing_next(t_lem_in_file **file)
{
	(*file)->next->prev = 0;
	*file = (*file)->next;
}

void		del_and_set_to_null_t_lem_in_file(t_lem_in_file **file)
{
	t_lem_in_file *tmp;

	while (*file)
	{
		tmp = *file;
		free((*file)->line);
		if ((*file)->prev && (*file)->next)
			handle_existing_prev_and_existing_next(file);
		else if ((*file)->prev && !(*file)->next)
			handle_existing_prev_and_null_next(file);
		else if (!(*file)->prev && (*file)->next)
			handle_null_prev_and_existing_next(file);
		else
		{
			free(tmp);
			*file = NULL;
			return ;
		}
		free(tmp);
		*file = (*file)->next;
	}
}
