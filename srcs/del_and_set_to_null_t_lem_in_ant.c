/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_and_set_to_null_t_lem_in_ant.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:09:52 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 14:41:31 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	handle_existing_prev_and_existing_next(t_lem_in_ant **ant)
{
	(*ant)->prev->next = (*ant)->next;
	(*ant)->next->prev = (*ant)->prev;
	*ant = (*ant)->prev;
}

static void	handle_existing_prev_and_null_next(t_lem_in_ant **ant)
{
	(*ant)->prev->next = 0;
	*ant = (*ant)->prev;
}

static void	handle_null_prev_and_existing_next(t_lem_in_ant **ant)
{
	(*ant)->next->prev = 0;
	*ant = (*ant)->next;
}

void		del_and_set_to_null_t_lem_in_ant(t_lem_in_ant **ant)
{
	t_lem_in_ant *tmp;

	while (*ant)
	{
		tmp = *ant;
		free((*ant)->name);
		(*ant)->position = NULL;
		if ((*ant)->prev && (*ant)->next)
			handle_existing_prev_and_existing_next(ant);
		else if ((*ant)->prev && !(*ant)->next)
			handle_existing_prev_and_null_next(ant);
		else if (!(*ant)->prev && (*ant)->next)
			handle_null_prev_and_existing_next(ant);
		else
		{
			free(tmp);
			*ant = NULL;
			return ;
		}
		free(tmp);
		*ant = (*ant)->next;
	}
}
