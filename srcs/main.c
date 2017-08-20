/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:59:01 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/20 18:53:20 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	main(void)
{
	t_lem_in_var	v;
	t_lem_in_file	*file;
	t_lem_in_room	*room;
	t_lem_in_file	*tmp;//

	init_t_lem_in_var(&v);
	if (!(file = stock_content()))
	{
		DEB
		return (handle_error());
	}
	tmp = file;
	while (tmp)
	{
		printf("file line : {%s}\n", tmp->line);
		tmp = tmp->next;
	}
	DEB
	if (!parse_content_light(&v, file) || (!estimate_if_doable(&v)))
	{
		DEB
		return (handle_error());
	}
	DEB
	if (!(room = format_content_into_lst(file)))
	{
		DEB
		return (handle_error());
	}
	DEB
	if (!parse_content_in_depth(room))
	{
		DEB
		return (handle_error());
	}
	DEB
	return (0);
}
