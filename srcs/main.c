/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:59:01 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/22 19:35:42 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	main(void)
{
	t_lem_in_var	v;
	t_lem_in_file	*file;
	t_lem_in_room	*room;
	t_lem_in_ant	*ant;

	init_t_lem_in_var(&v);
	if (!(file = stock_content(&v->has_file)))
		return (handle_error());
	if (!parse_content_light(&v, file) || (!estimate_if_doable(&v)))
		return (handle_error());
	if (!(room = format_content_into_lst(file, &v->has_room)))
		return (handle_error());
	if (!parse_content_in_depth(room))
		return (handle_error());
	if (!(apply_algorithm(room)))
		return (handle_error());
	if (!(ant = init_t_lem_in_ant(v.ants_nb, room)))
		return (handle_error());
	if (!(find_and_print_solution(v.ants_nb, ant)))
		return (handle_error());
	return (0);
}
