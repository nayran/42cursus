/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:48:57 by nayran            #+#    #+#             */
/*   Updated: 2021/02/17 17:02:35 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_specounter(char *buff)
{
	int x;
	int count;

	count = 1;
	x = -1;
	while (buff[++x])
	{
		if (buff[x] == '\'' && buff[x - 1] != '\\')
			x = ft_returnposition(&buff[x], '\'', x);
		if (buff[x] == '\"' && buff[x - 1] != '\\')
			x = ft_returnposition(&buff[x], '\"', x);
		if (buff[x] == ';' && buff[x - 1] != '\\')
			count++;
	}
	return (count);
}

char	*ft_specialhandler(char *buff)
{
	int		x;
	int		y;
	char	*aux;

	x = -1;
	y = 0;
	aux = malloc(ft_strlen(buff));
	while (buff[++x])
	{
		if (buff[x] != '\'' && buff[x] != '\"')
		{
			if (buff[x] != '\\')
				aux[y++] = buff[x];
			else if (buff[x] == '\\' && buff[x + 1] != '\\')
				aux[y++] = buff[x];
		}
		else if (buff[x - 1] == '\\' && (buff[x] != '\'' && buff[x] != '\"'))
			aux[y++] = buff[x];
	}
	return (aux);
}

char	**ft_changedollarsign(char **buff, int n)
{
	int x;

	x = 0;
	while (x < n)
	{
		buff[x] = ft_istheredollsign(buff[x]);
		x++;
	}
	return (buff);
}

char	**ft_spcheck2(char **newbuff, int c, int x, char *buff)
{
	int		quote;

	quote = ft_isquoted(buff);
	newbuff[c] = ft_strdup(buff);
	newbuff[c][x] = '\0';
	newbuff[c] = ft_specialhandler(newbuff[c]);
	newbuff[c] = ft_antispace(newbuff[c]);
	if (quote == 2)
		newbuff[c] = ft_istheredollsign(newbuff[c]);
	return (newbuff);
}

char	**ft_specharcheck(char *buff, int semicols)
{
	char	**newbuffer;
	int		x;
	int		count;

	x = -1;
	count = 0;
	newbuffer = malloc(semicols * sizeof(char *));
	while (buff[++x])
	{
		if (buff[x] == '\'' && buff[x - 1] != '\\')
			x = ft_returnposition(&buff[x], '\'', x);
		if (buff[x] == '\"' && buff[x - 1] != '\\')
			x = ft_returnposition(&buff[x], '\"', x);
		if ((buff[x] == ';' && buff[x - 1] != '\\') ||
				(buff[x] == '\0' || buff[x + 1] == '\0'))
		{
			if (buff[x + 1] == '\0')
				x++;
			newbuffer = ft_spcheck2(newbuffer, count, x, buff);
			buff = &buff[x + 1];
			x = -1;
			count++;
		}
	}
	return (newbuffer);
}
