/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:32:31 by nasimon-          #+#    #+#             */
/*   Updated: 2021/04/20 16:32:31 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	const char	*aux;

	aux = s1;
	while (*aux)
		aux++;
	while (aux >= s1)
	{
		if (*aux == c)
			return ((char *)aux);
		aux--;
	}
	return (NULL);
}
