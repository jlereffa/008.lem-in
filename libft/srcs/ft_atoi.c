/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:25:49 by jlereffa          #+#    #+#             */
/*   Updated: 2016/11/23 21:25:52 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *nptr)
{
	int		i;
	int		result;
	int		is_neg;

	i = 0;
	result = 0;
	is_neg = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' ||
			nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f' ||
			(nptr[i] == '+' && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9')))
		i++;
	if (nptr[i] == '-' && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
	{
		i++;
		is_neg = -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * is_neg);
}
