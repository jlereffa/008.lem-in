/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_print_solution.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:48:22 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/21 20:01:58 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	find_and_print_solution(int ant_nb, t_lem_in_ant *ant)
{
	int				i;
	int				turn;
	int				best_way;
	t_lem_in_ant	*ptr;

	i = 0;
	turn = 1;
	while (ant_nb)
	{
		ptr = ant;
		while (ant && i < turn)
		{
			if (ant->position->path && !rewind_t_lem_in_path(&ant->position->path))
				return 0;
			best_way = 2147483647;
			while (ant->position->path)
			{
				if (ant->position->path->room->value < best_way)
					best_way = ant->position->path->room->value;
				ant->position->path = ant->position->path->next;
			}
			if (!rewind_t_lem_in_path(&ant->position->path))
				return (0);
			while (ant->position->path->room->value != best_way)
				ant->position->path = ant->position->path->next;
			ant->position = ant->position->path->room;
			ft_putstr(ant->name);
			ft_putstr(ant->position->name);
			ft_putstr(" ");
			i++;
			ant = ant->next;
		}
		ft_putendl("");
		i = 0;
		turn++:
	}
}
