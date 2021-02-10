/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:46:27 by nayran            #+#    #+#             */
/*   Updated: 2020/12/23 18:41:08 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_isflag(char *buff)
{
	if (buff[0] != '-')
		return (0);
	return (ft_strlen(ft_firstword(buff)));
}

int		ft_isechovar(char *buff)
{
	int x;

	x = 0;
	while (ft_isalnum(buff[x]) || buff[x] == ' ')
		x++;
	if (buff[x] == '$')
		return (x);
	return (0);
}

char	*ft_istheredollsign(char *buff)
{
	while (ft_strchr(buff, '$'))
		buff = ft_putargs(buff);
	return (buff);
}

int		ft_numberofspaces(char *buff)
{
	int x;
	int n;

	n = 0;
	x = -1;
	buff = ft_removeallspaces(buff);
	while (buff[++x])
		if (buff[x] == ' ')
			n++;
	return (n);
}

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\0' || c == '\t')
		return (1);
	return (0);
}
