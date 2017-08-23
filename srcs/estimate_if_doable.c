/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimate_if_doable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 19:07:37 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 18:22:00 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	estimate_if_doable(t_lem_in_var *v)
{
	if (!v->stated_start)
		print_error_msg(ER_START_NOT_DEFINED);
	if (!v->stated_end)
		print_error_msg(ER_END_NOT_DEFINED);
	if (!v->has_room)
		print_error_msg(ER_HAS_NO_ROOM);
	if (!v->has_path)
		print_error_msg(ER_HAS_NO_PATH);
	if (!v->stated_start || !v->stated_end || !v->has_room || !v->has_path)
		return (print_error_msg(ER_NOT_DOABLE));
	return (1);
}
