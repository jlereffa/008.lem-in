/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:59:01 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/21 19:35:44 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	recap(t_lem_in_var *v, t_lem_in_room *room, t_lem_in_ant *ant)//
{
	t_lem_in_path *tmp_path;

	printf("---------RECAP--------\n");
	if (!rewind_t_lem_in_room(&room))
	{
		printf("Error rewinding room\n");
		return ;
	}
	printf("Ants number : %d\n", v->ants_nb);
	printf("Stated_start : %d\n", v->stated_start);
	printf("Stated_end : %d\n", v->stated_end);
	printf("Has_room : %d\n", v->has_room);
	printf("Has_path : %d\n", v->has_path);
	while (room)
	{
		if (room->path && !rewind_t_lem_in_path(&room->path))
		{
			printf("Error rewinding path\n");
			return ;
		}
		tmp_path = room->path;
		printf("\033[1;36mROOM : {%s}\n\033[0m", room->name);
		printf("COORD_X {%d} | COORD_Y {%d}\n", room->coord_x, room->coord_y);
		printf("\033[1;36mVALUE : %d\033[0m\n", room->value);
		printf("PATH LIST : \n");
		while (tmp_path)
		{
			printf("=> ROOM {%s} - ROOM {%s}\n", room->name, tmp_path->room->name);
			tmp_path = tmp_path->next;
		}
		room = room->next;
	}
	while (ant)
	{
		printf("ANT NAME : {%s}\n", ant->name);
		printf("ANT POSITION : {%s}\n", ant->position->name);
		ant = ant->next;
	}
	printf("-----END_OF_RECAP-----\n");
}

int	main(void)
{
	t_lem_in_var	v;
	t_lem_in_file	*file;
	t_lem_in_room	*room;
	t_lem_in_file	*tmp;//
	t_lem_in_ant	*ant;

	init_t_lem_in_var(&v);
	if (!(file = stock_content()))
	{
		DEB
		return (handle_error());
	}
	tmp = file;
	while (tmp)
	{
		printf("file line : {%s}\n", tmp->line);
		tmp = tmp->next;
	}
	DEB
	if (!parse_content_light(&v, file) || (!estimate_if_doable(&v)))
	{
		DEB
		return (handle_error());
	}
	DEB
	if (!(room = format_content_into_lst(file)))
	{
		DEB
		return (handle_error());
	}
	DEB
	if (!parse_content_in_depth(room))
	{
		DEB
		return (handle_error());
	}
	DEB
	if (!(apply_algorithm(room)))
	{
		DEB
		return (handle_error());
	}
	DEB
	if (!(ant = init_t_lem_in_ant(v.ants_nb, room)))
	{
		DEB
		return (handle_error());
	}
	DEB
	print_file(file);
	recap(&v, room, ant);
	return (0);
}
