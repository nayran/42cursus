/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:37:05 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/27 02:45:21 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*aux;
	unsigned char	*aux2;
	size_t			i;

	if ((dest == NULL && src == NULL) || num == 0)
		return (dest);
	i = 0;
	aux = (unsigned char *)dest;
	aux2 = (unsigned char *)src;
	while (num > i)
	{
		aux[i] = aux2[i];
		i++;
	}
	return (dest);
}
