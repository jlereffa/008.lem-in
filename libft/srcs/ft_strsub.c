/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:49:56 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:49:57 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*result;

	i = 0;
	result = NULL;
	if (!(result = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	return (result);
}
