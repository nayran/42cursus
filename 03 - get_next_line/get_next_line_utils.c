/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:18:55 by nasimon-          #+#    #+#             */
/*   Updated: 2020/02/06 18:41:20 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *string)
{
	size_t	x;

	x = 0;
	while (*string != '\0')
	{
		x++;
		string++;
	}
	return (x);
}

void	*ft_calloc(size_t num_elements, size_t size)
{
	void	*ptr;
	char	*aux;
	int		x;

	x = num_elements * size;
	ptr = malloc(num_elements * size);
	if (ptr)
	{
		aux = ptr;
		while (x > 0)
		{
			*aux = 0;
			aux++;
			x--;
		}
	}
	return (ptr);
}
