/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:05:40 by nasimon-          #+#    #+#             */
/*   Updated: 2021/04/20 16:41:53 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_count(unsigned int aux)
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

char	*ft_itoa(int n)
{
	char			*final;
	int				x;
	unsigned int	aux;
	int				k;

	k = 0;
	aux = n;
	if (n < 0)
		k = 1;
	if (n < 0)
		aux = 0 - n;
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
