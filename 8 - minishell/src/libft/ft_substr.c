/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:07:22 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/27 07:12:36 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	x;
	char	*final;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		final = (char *)malloc(1);
		if (!final)
			return (NULL);
		*final = '\0';
		return (final);
	}
	x = 0;
	final = (char *)malloc(len + 1);
	if (!final)
		return (NULL);
	while (x < len && s[x + start])
	{
		final[x] = s[x + start];
		x++;
	}
	final[x] = '\0';
	return (final);
}
