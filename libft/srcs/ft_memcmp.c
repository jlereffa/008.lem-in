/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:31:09 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:31:11 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	if (n == i)
		return (0);
	tmp1 = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	while (tmp1[i] == tmp2[i] && i < n - 1)
		i++;
	return ((int)(tmp1[i] - tmp2[i]));
}
