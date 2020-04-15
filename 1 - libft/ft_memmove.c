/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 07:29:27 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/30 16:02:27 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t numbytes)
{
	char *to2;
	char *from2;

	if (to == from)
		return (to);
	if (to < from)
	{
		to = ft_memcpy(to, from, numbytes);
		return (to);
	}
	to2 = (char *)to;
	from2 = (char *)from;
	while (numbytes-- > 0)
		to2[numbytes] = from2[numbytes];
	return (to);
}
