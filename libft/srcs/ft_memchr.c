/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:30:57 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:30:58 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	cpy_c;
	int		i;

	str = (char*)s;
	cpy_c = (char)c;
	i = 0;
	while (n)
	{
		if (str[i] == cpy_c)
			return ((void*)&str[i]);
		n--;
		i++;
	}
	return (NULL);
}
