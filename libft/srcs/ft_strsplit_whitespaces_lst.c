/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitespaces_lst.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:48:04 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:48:07 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_copy(char *s, int *i)
{
	char	*result;
	int		j;

	j = *i;
	while (s[j] != ' ' && s[j] != '\n' && s[j] != '\t' && s[j] != '\0')
		j++;
	if (!(result = (char*)malloc(sizeof(char) * j + 1)))
		return (NULL);
	j = 0;
	while (s[*i] != ' ' && s[*i] != '\n' && s[*i] != '\t' && s[*i] != '\0')
	{
		result[j] = s[*i];
		*i += 1;
		j++;
	}
	result[j] = '\0';
	return (result);
}

t_lst			*ft_strsplit_whitespaces_lst(char *str)
{
	t_lst		*lst;
	int			i;
	char		*result;

	lst = NULL;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		if (str[i])
		{
			result = ft_copy(str, &i);
			lst = ft_set_lst(lst, result, ft_strlen(result));
		}
	}
	return (lst);
}
