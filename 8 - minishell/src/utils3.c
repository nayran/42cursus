/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:35:19 by nayran            #+#    #+#             */
/*   Updated: 2020/12/28 20:13:03 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_antispace(char *buff)
{
	int x;

	x = 0;
	while (buff[x] && (buff[x] == ' ' || buff[x] == '\t'))
		x++;
	return (&buff[x]);
}

int		ft_counter(char *buff, char c)
{
	int x;
	int num;

	num = 1;
	x = -1;
	while (buff[++x])
	{
		if (x > 0 && buff[x] == c)
			num++;
	}
	return (num);
}

char	*ft_removeallspaces(char *buff)
{
	buff = ft_antispace(buff);
	buff = ft_removelineendspace(buff);
	return (buff);
}

char	*ft_removelinebreak(char *buff)
{
	int x;

	x = ft_strlen(buff) - 1;
	if (buff[x] == '\n')
		buff[x] = '\0';
	return (buff);
}

char	*ft_removelineendspace(char *buff)
{
	int x;

	x = ft_strlen(buff);
	while (x > 0)
	{
		if (buff[x] == ' ' || buff[x] == '\t' ||
				buff[x] == '\n' || buff[x] == '\0')
			x--;
		else
			break ;
	}
	buff[x + 1] = '\0';
	return (buff);
}
