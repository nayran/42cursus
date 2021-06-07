#include "libft.h"

char	*ft_prevline(char *line)
{
	int		x;
	char	*aux;

	if (!line)
		return (0);
	x = 0;
	while (line && line[x] && line[x] != '\n')
		x++;
	aux = (char *)malloc(sizeof(char) * (x + 1));
	if (!aux)
		return (0);
	x = 0;
	while (line && line[x] && line[x] != '\n')
	{
		aux[x] = line[x];
		x++;
	}
	aux[x] = '\0';
	return (aux);
}

char	*ft_eol(char *line)
{
	char	*aux;
	int		x;

	if (!line)
		return (0);
	x = 0;
	while (line[x] && line[x] != '\n')
		x++;
	if (!line[x])
	{
		free(line);
		return (0);
	}
	aux = ft_strdup(&line[x + 1]);
	free(line);
	return (aux);
}

int	get_next_line(int fd, char **line)
{
	static char	*leftover[OPEN_MAX];
	int			nread;
	char		*buffer;
	char		*aux;

	if (!line || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (-1);
	nread = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (leftover[fd] == 0)
		leftover[fd] = ft_strdup("");
	while (!ft_strchr(leftover[fd], '\n') && nread)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread == -1)
			return (-1);
		buffer[nread] = '\0';
		aux = ft_strjoin(leftover[fd], buffer);
		free(leftover[fd]);
		leftover[fd] = aux;
	}
	*line = ft_prevline(leftover[fd]);
	leftover[fd] = ft_eol(leftover[fd]);
	return (nread > 0);
}
