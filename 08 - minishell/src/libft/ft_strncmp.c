/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:46:53 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/30 16:36:06 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t max)
{
	unsigned char	*aux1;
	unsigned char	*aux2;
	int				x;

	if (max <= 0)
		return (0);
	x = max - 1;
	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	while (x > 0 && *aux1 && *aux2)
	{
		if (*aux1 != *aux2)
			return (*aux1 - *aux2);
		aux1++;
		aux2++;
		x--;
	}
	return (*aux1 - *aux2);
}
