/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_room_or_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 18:38:59 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/22 17:04:59 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	check_if_room_or_path(char *s)
{
	if (check_room(s))
		return (1);
	else if (check_path(s))
		return (2);
	return (0);
}
