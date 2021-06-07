/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:46:53 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/22 11:41:15 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t num)
{
	const unsigned char	*aux1;
	const unsigned char	*aux2;
	int					x;

	x = num;
	aux1 = s1;
	aux2 = s2;
	while (x != 0)
	{
		if (*aux1 != *aux2)
			return (*aux1 - *aux2);
		x--;
		aux1++;
		aux2++;
	}
	return (0);
}
