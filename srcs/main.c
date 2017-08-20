/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:59:01 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/20 15:06:17 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	main(void)
{
	t_lem_in_var	v;
	t_lem_in_file	*file;
	t_lem_in_room	*room;

	init_t_lem_in_var(&v);
	if (!(file = stock_content()))
		return (handle_error());
	if (!parse_content_light(&v, file) || (!estimate_if_doable(&v)))
		return (handle_error());
	if (!(room = format_content_into_lst(file)))
		return (handle_error());
	if (!parse_content_in_depth(&v, room))
		return (handle_error());
	return (0);
}
