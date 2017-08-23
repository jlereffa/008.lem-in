/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:28:31 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:28:38 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_nblen(long n)
{
	int		count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 1)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char		*ft_itoa_neg(char *tab, int len, long n)
{
	n *= -1;
	tab[0] = '-';
	tab[len] = '\0';
	while (n >= 1)
	{
		tab[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (tab);
}

static char		*ft_itoa_zero(void)
{
	char	*zero;

	if (!(zero = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	zero[0] = '0';
	zero[1] = '\0';
	return (zero);
}

char			*ft_itoa(int n)
{
	char	*tab;
	int		len;

	if (n == 0)
		return (ft_itoa_zero());
	len = ft_count_nblen(n);
	if (!(tab = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n < 0)
		return (ft_itoa_neg(tab, len, n));
	tab[len] = '\0';
	while (n >= 1)
	{
		tab[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (tab);
}
