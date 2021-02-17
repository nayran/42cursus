/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:49:41 by nayran            #+#    #+#             */
/*   Updated: 2021/02/17 16:55:36 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_isquoted(char *buff)
{
	int x;

	x = -1;
	while (buff[++x])
	{
		if (buff[x] == '\'')
			return (1);
		if (buff[x] == '\"')
			return (2);
		if (buff[x] == '\\')
			return (3);
	}
	return (0);
}

int		ft_returnposition(char *buff, char c, int pos)
{
	int x;

	x = 0;
	while (buff[++x])
	{
		if (buff[x] == c && buff[x - 1] != '\\')
			break ;
	}
	return (x + pos);
}

int		ft_isredirection(char *buff)
{
	int x;

	x = -1;
	while (buff[++x])
	{
		if (buff[x] == '>' && buff[x + 1] == '>')
			return (1);
		if (buff[x] == '>')
			return (2);
		if (buff[x] == '<')
			return (3);
	}
	return (0);
}

char	*ft_removefilename(char *buff)
{
	int		x;
	char	*aux;

	x = -1;
	aux = ft_strdup(buff);
	while (buff[++x])
	{
		if (buff[x] == '>' || buff[x] == '<')
		{
			aux[x] = 0;
			break ;
		}
	}
	aux = ft_antispace(aux);
	aux = ft_removelineendspace(aux);
	return (aux);
}

int		ft_isallquote(char *buff)
{
	int x;

	buff = ft_removelinebreak(buff);
	x = ft_strlen(buff) - 1;
	if (buff[0] == '\"' || buff[0] == '\'')
	{
		if (buff[x] == '\"' || buff[x] == '\'')
			return (1);
	}
	return (0);
}
