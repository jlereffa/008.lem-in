/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:08:49 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/21 19:10:07 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	print_file(t_lem_in_file *file)
{
	if (!rewind_t_lem_in_file(&file))
		return ;
	while (file)
	{
		ft_putendl(file->line);
		file = file->next;
	}
	ft_putendl("");
}
