/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_lem_in_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:12:54 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 13:24:26 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	init_t_lem_in_var(t_lem_in_var *v)
{
	v->ants_nb = 0;
	v->stated_start = 0;
	v->stated_end = 0;
	v->has_room = 0;
	v->has_path = 0;
}
