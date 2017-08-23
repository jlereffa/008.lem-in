/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:45:03 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:45:04 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*result;
	size_t		i;

	i = 0;
	if (!(result = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= size)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}
