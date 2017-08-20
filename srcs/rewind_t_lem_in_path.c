/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewind_t_lem_in_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:31:31 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/20 16:42:32 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	rewind_t_lem_in_path(t_lem_in_path **path)
{
	if (!path || !*path)
		return (0);
	while ((*path)->prev)
		*path = (*path)->prev;
	return (1);
}
