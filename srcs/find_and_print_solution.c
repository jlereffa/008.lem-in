/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_print_solution.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:48:22 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 14:47:15 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	print_ant_position(char *name, char *room_name)
{
	ft_putstr(name);
	ft_putstr(room_name);
}

static int	set_ant_and_path_pointers(t_lem_in_ant **ptr1, t_lem_in_path **ptr2)
{
	while ((*ptr1)->next && (*ptr1)->escaped)
		*ptr1 = (*ptr1)->next;
	if (!rewind_t_lem_in_path(&(*ptr1)->position->path))
		return (print_error_msg(ER_REWIND));
	*ptr2 = (*ptr1)->position->path;
	return (1);
}

static void	find_best_way(t_lem_in_ant **ptr1, t_lem_in_path **ptr2, int best)
{
	while (*ptr2)
	{
		if ((*ptr2)->room->value < best)
			best = (*ptr2)->room->value;
		*ptr2 = (*ptr2)->next;
	}
	(*ptr2) = (*ptr1)->position->path;
	while ((*ptr2)->room->value != best)
		*ptr2 = (*ptr2)->next;
}

static void	put_space_if_needed(int i, int turn, t_lem_in_ant *ptr1)
{
	if (i + 1 < turn && ptr1->next)
		ft_putstr(" ");
}

int			find_and_print_solution(int ant_nb, t_lem_in_ant *ant)
{
	int				i;
	int				turn;
	int				best_way;
	t_lem_in_ant	*ptr1;
	t_lem_in_path	*ptr2;

	turn = 0;
	while (ant_nb && ++turn && (i = -1))
	{
		ptr1 = ant;
		while (ptr1 && ++i < turn && (best_way = 2147483647))
		{
			if (!set_ant_and_path_pointers(&ptr1, &ptr2))
				return (0);
			find_best_way(&ptr1, &ptr2, best_way);
			ptr1->position = ptr2->room;
			print_ant_position(ptr1->name, ptr1->position->name);
			put_space_if_needed(i, turn, ptr1);
			if (ptr1->position->is_end && !ptr1->escaped && (ptr1->escaped = 1))
				ant_nb--;
			ptr1 = ptr1->next;
		}
		ft_putendl("");
	}
	return (1);
}
