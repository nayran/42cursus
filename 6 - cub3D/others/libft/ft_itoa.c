/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:05:40 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/28 14:23:28 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(unsigned int aux)
{
	int	x;

	x = 0;
	while (aux > 9)
	{
		aux = aux / 10;
		x++;
	}
	return (x);
}

char			*ft_itoa(int n)
{
	char			*final;
	int				x;
	unsigned int	aux;
	int				k;

	k = (n < 0) ? 1 : 0;
	aux = (n < 0) ? 0 - n : n;
	x = ft_count(aux) + 1 + k;
	final = (char *)malloc(x + 1);
	if (!final)
		return (0);
	final[x--] = '\0';
	while (aux > 9)
	{
		final[x--] = aux % 10 + '0';
		aux = aux / 10;
	}
	final[x] = aux + '0';
	if (k)
		final[--x] = '-';
	return (final);
}
