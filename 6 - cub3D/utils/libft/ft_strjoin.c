/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:32:29 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/27 07:13:52 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;
	int		k;
	char	*aux;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	k = ft_strlen(s1) + ft_strlen(s2);
	x = (char *)malloc(k + 1);
	aux = x;
	if (!x)
		return (NULL);
	while (*s1)
	{
		*x = *s1;
		x++;
		s1++;
	}
	while (*s2)
	{
		*x = *s2;
		x++;
		s2++;
	}
	*x = '\0';
	return (aux);
}
