/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:59:01 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/19 19:05:34 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	main(void)
{
	t_lem_in_var	v;
	t_lem_in_file	*file;

	init_t_lem_in_var(&v);
	if (!(file = stock_content()))
		return (handle_error());
	if (!parse_content_light(&v, file) || !estimate_if_doable(&v, file) ||
		!parse_content_in_depth(&v, file))
		return (handle_error());
	return (0);
}
