/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:22:00 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/27 04:57:34 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*x;
	unsigned int	k;

	if (!f || !s)
		return (NULL);
	x = malloc(ft_strlen(s) + 1);
	if (!x)
		return (NULL);
	k = 0;
	while (s[k])
	{
		x[k] = f(k, s[k]);
		k++;
	}
	x[k] = '\0';
	return (x);
}
