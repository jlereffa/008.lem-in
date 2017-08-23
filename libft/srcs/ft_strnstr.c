/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:45:17 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:45:25 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_stack(const char *s1, const char *s2, size_t i, size_t n)
{
	size_t	j;

	j = 0;
	while (s1[i] && s2[j] && i < n)
	{
		if (s1[i] != s2[j])
			return (0);
		i++;
		j++;
	}
	if (s2[j] == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < n)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_check_stack(haystack, needle, i, n) == 1)
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
