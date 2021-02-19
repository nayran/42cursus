/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:33:57 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/28 14:24:21 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**real_split(char const *s, char **dest, char c, int cont)
{
	int	k;
	int	l;
	int x;
	int len;

	k = 0;
	l = 0;
	while (s[k] && l < cont)
	{
		x = 0;
		len = 0;
		while (s[k] == c)
			k++;
		while (s[k + len] != c && s[k + len])
			len++;
		dest[l] = (char *)malloc(sizeof(char) * (len + 1));
		if (!dest[l])
			return (NULL);
		while (s[k] && s[k] != c)
			dest[l][x++] = s[k++];
		dest[l++][x] = '\0';
	}
	dest[l] = 0;
	return (dest);
}

char		**ft_split(char const *s, char c)
{
	int		cont;
	int		ver;
	int		i;
	char	**dest;

	i = 0;
	cont = 0;
	ver = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i++] == c)
			ver = 1;
		else if (ver)
		{
			ver = 0;
			cont++;
		}
	}
	dest = (char **)malloc(sizeof(char *) * (cont + 1));
	if (!dest)
		return (NULL);
	dest = real_split(s, dest, c, cont);
	return (dest);
}
