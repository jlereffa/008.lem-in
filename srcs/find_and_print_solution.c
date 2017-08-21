/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_print_solution.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:48:22 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/21 20:10:48 by jlereffa         ###   ########.fr       */
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
	DEB
	while (ant_nb)
	{
		DEB
		ptr = ant;
		while (ptr && i < turn)
		{
			DEB
			if (ptr->position->path && !rewind_t_lem_in_path(&ptr->position->path))
			{
				DEB
				return 0;
			}
			DEB
			best_way = 2147483647;
			while (ptr->position->path)
			{
				DEB
				if (ptr->position->path->room->value &&
					ptr->position->path->room->value < best_way)
				{
					DEB
					best_way = ptr->position->path->room->value;
				}
				ptr->position->path = ptr->position->path->next;
			}
			DEB
			if (ptr->position->path && !rewind_t_lem_in_path(&ptr->position->path))
			{
				DEB
				return (0);
			}
			while (ptr->position->path->room->value != best_way)
			{
				DEB
				ptr->position->path = ant->position->path->next;
			}
			DEB
			ptr->position = ptr->position->path->room;
			ft_putstr(ant->name);
			ft_putstr(ant->position->name);
			ft_putstr(" ");
			i++;
			ptr = ptr->next;
		}
		ft_putendl("");
		i = 0;
		turn++;
		ant_nb--;
		DEB
	}
	DEB
	return (1);
}
