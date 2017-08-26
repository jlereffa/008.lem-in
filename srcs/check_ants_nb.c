/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ants_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:31:46 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/26 12:50:25 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	check_ants_nb(t_lem_in_var *v, char *s)
{
	char		*ptr;
	intmax_t	tmp;

	ptr = s;
	if (!s || !*s)
		return (0);
	while (*ptr)
	{
		if (!(*ptr >= '0' && *ptr <= '9'))
			return (print_error_msg(ER_ANT));
		ptr++;
	}
	if ((tmp = ft_atointmax(s)) > 2147483647)
		return (print_error_msg(ER_ANT_NB_TOO_BIG));
	v->ants_nb = tmp;
	ft_putendl(s);
	return (1);
}
