/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:47:32 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/30 16:58:09 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	l;
	int		k;
	size_t	resp;

	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	resp = ft_strlen(src) + ft_strlen(dst);
	k = 0;
	i = 0;
	l = size;
	while (l && dst[i])
	{
		i++;
		l--;
	}
	l = size - ft_strlen(dst) - 1;
	while (l && src[k])
	{
		dst[i + k] = src[k];
		k++;
		l--;
	}
	dst[i + k] = 0;
	return (resp);
}
