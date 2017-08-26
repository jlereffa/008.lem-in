/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 13:47:13 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 10:40:14 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup_n(char *s, unsigned int n)
{
	char	*new;
	char	*ptr;

	if (!s || (!(new = (char*)malloc(sizeof(char) * n + 1))))
		return (NULL);
	ptr = new;
	while (n--)
	{
		*new = *s;
		new++;
		s++;
	}
	*new = '\0';
	return (ptr);
}
