/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:30:31 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:30:32 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!(result = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	while (i < size)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}
