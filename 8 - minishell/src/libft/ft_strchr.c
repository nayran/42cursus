/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:14:16 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/27 03:08:27 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*src;

	src = s;
	while (*src != '\0')
	{
		if (*src == c)
			return ((char *)src);
		src++;
	}
	if (*src == c)
		return ((char *)src);
	src = 0;
	return ((char *)src);
}
