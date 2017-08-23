/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_charset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:47:23 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:47:24 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_handle_null_charset(char *str)
{
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * 2)))
		tab[0] = ft_strdup(str);
	tab[1] = NULL;
	return (tab);
}

static int		ft_count_words(char *s, char *c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (ft_find_charset(&s[i], c))
			i += ft_strlen(c);
		if (!ft_find_charset(&s[i], c) && s[i])
		{
			if (ft_find_charset(&s[i + 1], c))
			{
				i += ft_strlen(c);
				words++;
			}
			else if (s[i + 1] == '\0')
				words++;
		}
		if (s[i])
			i++;
	}
	return (words + 1);
}

static int		ft_letters(char *s, char *c)
{
	int		i;
	int		letters;

	i = 0;
	letters = 0;
	while (ft_find_charset(&s[i], c))
		i += ft_strlen(c);
	while (s[i] && !ft_find_charset(&s[i], c))
	{
		letters++;
		i++;
	}
	return (letters + 1);
}

static char		*ft_copy(char *str, int *i, char *c)
{
	char	*tab;
	int		j;

	j = 0;
	if (!(tab = (char*)malloc(sizeof(char) * ft_letters(&str[*i], c))))
		return (NULL);
	while (!ft_find_charset(&str[*i], c))
	{
		tab[j] = str[*i];
		*i += 1;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

char			**ft_strsplit_charset(char *str, char *charset)
{
	int		i;
	int		j;
	int		words;
	char	**tab;

	i = 0;
	j = 0;
	if (charset[0] == '\0')
		return (ft_handle_null_charset(str));
	words = ft_count_words(str, charset);
	if (!(tab = (char**)malloc(sizeof(char*) * words)))
		return (NULL);
	while (j < words - 1)
	{
		while (ft_find_charset(&str[i], charset))
			i += ft_strlen(charset);
		if (str[i])
			tab[j] = ft_copy(str, &i, charset);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
