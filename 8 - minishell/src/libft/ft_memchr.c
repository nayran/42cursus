/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:18:00 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/30 17:20:03 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buffer, int c, size_t count)
{
	const unsigned char	*aux;
	size_t				l;

	aux = (const unsigned char *)buffer;
	l = 0;
	while (l < count)
	{
		if (aux[l] == (unsigned char)c)
			return ((void *)&aux[l]);
		l++;
	}
	return (NULL);
}
