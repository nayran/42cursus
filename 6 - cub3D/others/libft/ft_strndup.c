/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:17:00 by nasimon-          #+#    #+#             */
/*   Updated: 2020/05/24 02:40:54 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *source, int n)
{
	unsigned char	*aux;
	int				i;

	i = 0;
	aux = malloc(ft_strlen(source) + 1);
	if (!aux)
		return (NULL);
	while (source[i] != '\0' && i < n)
	{
		aux[i] = source[i];
		i++;
	}
	aux[i] = '\0';
	return (char *)aux;
}
