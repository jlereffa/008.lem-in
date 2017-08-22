/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimate_if_doable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 19:07:37 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/22 15:38:34 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	estimate_if_doable(t_lem_in_var *v)
{
	/*printf("stated start ? {%d} | stated end ? {%d} | has room ? {%d} | has path ? {%d}\n",
			v->stated_start, v->stated_end, v->has_room, v->has_path);*/
	if (!v->stated_start || !v->stated_end || !v->has_room || !v->has_path)
		return (0);
	return (1);
}
