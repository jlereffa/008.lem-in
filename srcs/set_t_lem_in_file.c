/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_t_lem_in_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 11:32:33 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/19 11:36:34 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_lem_in_file	*set_t_lem_in_file(t_lem_in_file *file, char *ptr)
{
	if (!file)
	{
		if (!(file = (t_lem_in_file*)malloc(sizeof(t_lem_in_file))))
			return (0);
		file->line = ptr;
		file->prev = NULL;
		file->next = NULL;
		return (file);
	}
	while (file->next)
		file = file->next;
	if (!(file->next = set_t_lem_in_file(file->next, ptr)))
		return (0);
	file->next->prev = file;
	file = file->next;
	return (file);
}
