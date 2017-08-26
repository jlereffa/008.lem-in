/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:50:17 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:50:19 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int		i;
	unsigned int		len;

	i = 0;
	len = (ft_strlen(s) - 1);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (!s[i])
		return ("");
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	if (len == ft_strlen(s))
		return ((char*)&s[i]);
	return (ft_strsub(s, i, (len - i + 1)));
}
