/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:38:19 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:38:21 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_count_words(char *str)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\n' || str[i + 1] == '\t'
			|| str[i + 1] == '\0')
				words++;
		}
		i++;
	}
	return (words + 1);
}

static int		ft_count_letters(char *str)
{
	int		i;
	int		letters;

	i = 0;
	letters = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\0')
	{
		letters++;
		i++;
	}
	return (letters + 1);
}

static char		*ft_copy(char *str, int *k)
{
	int		i;
	char	*tab;

	i = 0;
	if (!(tab = (char*)malloc(sizeof(char) * ft_count_letters(&str[*k]))))
		return (NULL);
	while (str[*k] != ' ' && str[*k] != '\n' && str[*k] != '\t' &&
			str[*k] != '\0')
	{
		tab[i] = str[*k];
		i++;
		*k += 1;
	}
	tab[i] = '\0';
	return (tab);
}

char			**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_count_words(str)))))
		return (NULL);
	while (str[k])
	{
		while (str[k] == ' ' || str[k] == '\n' || str[k] == '\t')
			k++;
		if (str[k])
		{
			tab[i] = ft_copy(str, &k);
			i++;
		}
	}
	tab[i] = 0;
	return (tab);
}
