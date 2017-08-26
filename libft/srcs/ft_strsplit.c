/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:47:06 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:47:07 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words + 1);
}

static int		ft_letters(char *s, char c)
{
	int		i;
	int		letters;

	i = 0;
	letters = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		letters++;
		i++;
	}
	return (letters + 1);
}

static char		*ft_copy(char *str, int *i, char c)
{
	char	*tab;
	int		j;

	j = 0;
	if (!(tab = (char*)malloc(sizeof(char) * ft_letters((char*)&str[*i], c))))
		return (NULL);
	while (str[*i] != c)
	{
		tab[j] = str[*i];
		*i += 1;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	char	**tab;

	i = 0;
	j = 0;
	words = ft_count_words((char*)s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * words)))
		return (NULL);
	while (j < words - 1)
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			tab[j] = ft_copy((char*)s, &i, c);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
