/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:17:00 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/30 14:00:30 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	unsigned char	*aux;
	int				i;

	i = 0;
	aux = malloc(ft_strlen(source) + 1);
	if (!aux)
		return (NULL);
	while (source[i] != '\0')
	{
		aux[i] = source[i];
		i++;
	}
	aux[i] = '\0';
	return (char *)aux;
}
