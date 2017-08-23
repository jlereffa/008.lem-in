/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc_more.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:57:07 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/26 00:58:36 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the ft_strrealloc_more function receives a string and realloc it as
** it's previous size + more_bytes.
*/

char	*ft_strrealloc_more(char **str, size_t more_bytes)
{
	char	*new_s;

	if (!*str)
	{
		if (!(new_s = ft_strnew(more_bytes + 1)))
			return (NULL);
	}
	else
	{
		if (!(new_s = ft_strnew(ft_strlen(*str) + more_bytes + 1)))
			return (NULL);
	}
	if (*str)
		new_s = ft_strcpy(new_s, *str);
	free(*str);
	*str = new_s;
	return (new_s);
}
