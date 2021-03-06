/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 11:15:41 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/22 14:46:14 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_lem_in_file	*stock_content(void)
{
	char			*ptr;
	int				ret;
	int				line_nb;
	t_lem_in_file	*file;

	file = 0;
	line_nb = 0;
	while ((ret = get_next_line(0, &ptr)) > 0)
	{
		line_nb++;
		if (!(file = set_t_lem_in_file(file, ptr)))
			return (0);
	}
	if (ret == -1 || line_nb < 6)
		return (0);
	if (!rewind_t_lem_in_file(&file))
		return (0);
	return (file);
}
