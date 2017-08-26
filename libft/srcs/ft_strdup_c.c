/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:33:57 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/03 15:36:18 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strdup_c function returns an allocated with malloc '\0' terminating
** copy of the 's' string until the 'c' character is found, or NULL if the 'c'
** character is not found.
*/

#include "libft.h"

char	*ft_strdup_c(char *s, char c)
{
	int		i;
	char	*new_s;
	char	*ptr;

	i = 0;
	if (!(ptr = ft_strchr(s, c)))
		return (NULL);
	if (!(new_s = (char*)malloc(sizeof(char) * (ptr - s) + 1)))
		return (NULL);
	while (s[i] != c)
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
