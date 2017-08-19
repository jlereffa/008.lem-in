/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ants_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:31:46 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/19 18:58:04 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	check_ants_nb(t_lem_in_var *v, char *s)
{
	char	*ptr;

	ptr = s;
	if (!s || !*s)
		return (0);
	while (*ptr)
	{
		if (!(*ptr >= '0' && *ptr <= '9'))
			return (0);
		ptr++;
	}
	v->ants_nb = ft_atoi(s);
	if (!v->ants_nb)
		return (0);
	ft_putendl(s);
	return (1);
}
