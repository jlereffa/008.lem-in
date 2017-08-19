/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_lem_in_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:12:54 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/19 18:39:57 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	init_t_lem_in_var(t_lem_in_var *v)
{
	v->ants_nb = 0;
	v->start_stated = 0;
	v->end_stated = 0;
	v->has_room = 0;
	v->has_path = 0;
}
