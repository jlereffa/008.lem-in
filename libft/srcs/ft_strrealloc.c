/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:46:47 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:46:49 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char **str, size_t new_size)
{
	char		*new_str;
	size_t		i;

	i = 0;
	if (!(new_str = (char*)malloc(sizeof(char) * new_size + 1)))
		return (NULL);
	while (i < new_size)
	{
		if (str[0][i])
			new_str[i] = str[0][i];
		else
			new_str[i] = '\0';
		i++;
	}
	new_str[i] = '\0';
	free(*str);
	*str = new_str;
	return (new_str);
}
