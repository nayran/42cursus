/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:41:44 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/30 14:18:24 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *to, const void *from, int ch, size_t nbytes)
{
	unsigned char	*aux_from;
	unsigned char	*aux_to;
	size_t			i;

	i = 0;
	aux_from = (unsigned char *)from;
	aux_to = (unsigned char *)to;
	while (nbytes > i)
	{
		aux_to[i] = aux_from[i];
		if (aux_to[i] == (unsigned char)ch)
			return (&aux_to[i + 1]);
		i++;
	}
	return (0);
}
