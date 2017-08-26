/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_charset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:26:55 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:27:00 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_charset(const char *str, const char *charset)
{
	int		i;

	i = 0;
	while (str[i] && charset[i])
	{
		if (str[i] != charset[i])
			return (0);
		i++;
	}
	if (i != (int)ft_strlen(charset))
		return (0);
	return (1);
}
