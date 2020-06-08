#include "get_next_line.h"

int ft_strlen(char *str)
{
	int x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char *ft_calloc(int x)
{
	char *aux;
	int	k;

	k = 0;
	aux =(char *)malloc(x);
	while (k < x)
	{
		aux[k] = '\0';
		k++;
	}
	return (aux);
}

int ft_find(char *str, char find)
{
	int x;

	x = 0;
	while (str[x])
	{
		if (str[x] == find)
			return (x);
		x++;
	}
	return (-1);
}

char *ft_strjoin(char *str, char *str2)
{
	int x;
	int y;
	char *aux;

	aux = ft_calloc(ft_strlen(str) + ft_strlen(str2) + 1);
	x = 0;
	y = 0;
	while (str[x])
	{
		aux[x] = str[x];
		x++;
	}
	while (str2[y])
	{
		aux[x + y] = str2[y];
		y++;
	}
	return (aux);
}

char *ft_substr(char *str, int posi, int posf)
{
	char *aux;
	int x;
	int total;
	
	x = 0;
	total = posf - posi;
	aux = ft_calloc(total + 1);
	while(str[x] && x < total)
	{
		aux[x] = str[posi + x];
		x++;
	}
	return (aux);
}

int get_next_line(char **line)
{
	static char *sttc;
	ssize_t nread;
	char buffer[BUFFER_SIZE + 1];
	int posi;

	if ((!line) || (!(sttc) && !(sttc = ft_calloc(1))))
			return (-1);
	while (ft_find(sttc, '\n') < 0 && (nread = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nread] = '\0';
		sttc = ft_strjoin(sttc, buffer);
	}
	posi = ft_find(sttc, '\n');
	if (posi >= 0)
	{
		*line = ft_substr(sttc, 0, posi);
		sttc = ft_substr(sttc, posi+1 , ft_find(sttc, '\0'));
		return (1);
	}
	*line = ft_substr(sttc, 0, ft_find(sttc, '\0'));
	free(sttc);
	return (0);
}
