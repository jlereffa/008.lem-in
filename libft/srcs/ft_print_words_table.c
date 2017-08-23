/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:32:58 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:32:59 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_words_table(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		write(1, array[i], ft_strlen(array[i]));
		write(1, "\n", 1);
		i++;
	}
}
