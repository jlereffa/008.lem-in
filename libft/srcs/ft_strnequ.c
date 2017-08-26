/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:44:50 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:44:52 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!n)
		return (1);
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
