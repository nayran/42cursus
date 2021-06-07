/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:48:59 by nasimon-          #+#    #+#             */
/*   Updated: 2020/02/06 20:07:10 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_strdel(char **s)
{
	free(*s);
	*s = NULL;
}

static int	ft_eol_index(char *buffer)
{
	int x;

	x = 0;
	while (buffer[x])
	{
		if (buffer[x] == '\n')
			return (1);
		x++;
	}
	return (0);
}

static int	ft_aux(ssize_t nread, char *leftover[OPEN_MAX], int fd, char **line)
{
	int		x;
	char	*aux;

	x = 0;
	if (nread < 0)
		return (-1);
	else if (nread == 0 && leftover[fd] == NULL &&
			(*line = (char *)ft_calloc(1, 1)))
		return (0);
	while (leftover[fd][x] != '\n' && leftover[fd][x] != '\0')
		x++;
	if (leftover[fd][x] == '\n')
	{
		*line = ft_substr(leftover[fd], 0, x);
		aux = ft_strdup(&(leftover[fd][x + 1]));
		free(leftover[fd]);
		leftover[fd] = aux;
		if (leftover[fd][0] == '\0')
			ft_strdel(&leftover[fd]);
		return (1);
	}
	*line = ft_strdup(leftover[fd]);
	ft_strdel(&leftover[fd]);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	ssize_t		nread;
	int			eol;
	static char	*leftover[OPEN_MAX];
	char		*aux;
	char		*buffer;

	if (line == NULL || fd < 0 || BUFFER_SIZE == 0)
		return (-1);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	while ((nread = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nread] = '\0';
		if (!leftover[fd])
			leftover[fd] = ft_strdup(buffer);
		else
		{
			aux = ft_strjoin(leftover[fd], buffer);
			free(leftover[fd]);
			leftover[fd] = aux;
		}
		if ((eol = ft_eol_index(buffer)) > 0)
			break ;
	}
	free(buffer);
	return (ft_aux(nread, leftover, fd, line));
}
