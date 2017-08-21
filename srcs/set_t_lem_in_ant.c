/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_t_lem_in_ant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:30:24 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/21 19:31:34 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static char		*get_ant_name(int nb)
{
	char	*ptr;
	char	*name;
	char	*name_final;
	int		len;

	len = 0;
	if (!(name = ft_itoa(nb)))
		return (0);
	while (name[len])
		len++;
	if (!(name_final = (char*)malloc(sizeof(char) * len + 2)))
		return (0);
	ptr = name;
	len = 1;
	name_final[0] = 'L';
	while (*name)
	{
		name_final[len] = *name;
		name++;
		len++;
	}
	name_final[len] = '\0';
	return (name_final);
}

t_lem_in_ant	*set_t_lem_in_ant(
				t_lem_in_ant *ant, int nb, t_lem_in_room *room)
{
	if (!ant)
	{
		if (!(ant = (t_lem_in_ant*)malloc(sizeof(t_lem_in_ant))))
			return (0);
		if (!(ant->name = get_ant_name(nb)))
			return (0);
		ant->position = room;
		ant->prev = 0;
		ant->next = 0;
		return (ant);
	}
	while (ant->next)
		ant = ant->next;
	if (!(ant->next = set_t_lem_in_ant(ant->next, nb, room)))
		return (0);
	ant->next->prev = ant;
	ant = ant->next;
	return (ant);
}
