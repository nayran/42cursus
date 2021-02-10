/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:34:51 by nayran            #+#    #+#             */
/*   Updated: 2021/02/10 14:06:05 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_separator2(char *buff, char **dest, char c)
{
	int		x;
	int		y;
	int		count;

	x = -1;
	y = 0;
	count = 0;
	while (buff[++x])
		if (buff[x] == c || buff[x + 1] == '\0')
		{
			dest[count] = malloc(x + 1);
			if (buff[x] == c)
				ft_memcpy(dest[count], &buff[y], x - y);
			else
				ft_memcpy(dest[count], &buff[y], x - y + 1);
			dest[count][x] = '\0';
			y = x + 1;
			count++;
		}
	return (dest);
}

char	**ft_separator(char *buff, char **dest, char c, int n)
{
	dest = malloc(n * sizeof(char *));
	if (buff[0] == c)
		buff = ft_checkinit(buff, c);
	if (buff == NULL)
		return (NULL);
	if (n == 1)
		*dest = ft_strdup(buff);
	else if (buff != NULL)
		dest = ft_separator2(buff, dest, c);
	return (dest);
}

void	ft_handler3(int semicols, char **semicolbuff)
{
	int		x;
	int		pipes;
	char	**pipesbuff;

	x = -1;
	pipesbuff = NULL;
	while (semicolbuff && ++x < semicols)
	{
		pipes = ft_counter(semicolbuff[x], '|');
		if (pipes > 1)
		{
			pipesbuff = ft_separator(semicolbuff[x], pipesbuff, '|', pipes);
			ft_pipes(pipesbuff, pipes, x);
		}
		else if (semicolbuff[x][0] != 0 && semicolbuff[x][0] != 10)
			ft_args(semicolbuff[x]);
	}
}

void	ft_handler2(char *buff)
{
	char	**semicolbuff;
	int		semicols;

	semicolbuff = NULL;
	if (ft_isquoted(buff))
	{
		if (ft_isallquote(buff))
		{
			semicols = 1;
			semicolbuff = malloc(sizeof(char *));
			semicolbuff[0] = ft_strdup(buff);
		}
		else
		{
			semicols = ft_specounter(buff);
			semicolbuff = ft_specharcheck(buff, semicols);
		}
	}
	else
	{
		semicols = ft_counter(buff, ';');
		semicolbuff = ft_separator(buff, semicolbuff, ';', semicols);
		semicolbuff = ft_changedollarsign(semicolbuff, semicols);
	}
	ft_handler3(semicols, semicolbuff);
}

void	ft_handler(char *buff)
{
	buff = ft_antispace(buff);
	if (buff[0] == '|')
		ft_printf("parse error near `|'\n");
	else if (buff[0] != 10 && buff[0] != 0)
		ft_handler2(buff);
}
