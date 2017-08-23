/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 11:18:00 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/23 13:19:48 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	handle_error(t_lem_in_file **file, t_lem_in_room **room, t_lem_in_ant **ant)
{
	free_all_struct(file, room, ant);
	write(1, "ERROR\n", 6);
	return (0);
}
