/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:59:01 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 14:39:22 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	main(void)
{
	t_lem_in_var	v;
	t_lem_in_file	*file;
	t_lem_in_room	*room;
	t_lem_in_ant	*ant;

	file = 0;
	room = 0;
	ant = 0;
	init_t_lem_in_var(&v);
	if (!(file = stock_content()) ||
		(!parse_content_light(&v, file) && (!estimate_if_doable(&v))) ||
		!(room = format_content_into_lst(file)) ||
		!parse_content_in_depth(room) ||
		!apply_algorithm(room) ||
		!(ant = init_t_lem_in_ant(v.ants_nb, room)))
		return (handle_error(&file, &room, &ant));
	if (check_if_start_has_path_to_end(room))
		get_ants_out_easy(ant, room);
	else if (!(find_and_print_solution(v.ants_nb, ant)))
		return (handle_error(&file, &room, &ant));
	free_all_struct(&file, &room, &ant);
	return (0);
}
