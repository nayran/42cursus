#include "../cub3D.h"

t_godfather ft_trata_r(char *line, t_godfather all)
{
	int x;
	int y;
	char *c;
	int k;

	k = 0;
	x = 0;
	y = 0;
	while (k < 2 && line[x + y])
	{
		x += y;
		while (ft_isdigit(line[x + y]) == 0)
			x++;
		while (ft_isdigit(line[x + y]) > 0)
			y++;
		c = ft_substr(line, x, y);
		all.caso.r[k] = ft_atoi(c);
		k++;
	}
	return (all);
}

char *ft_tratageral(char *line, char *tipo)
{
	int x;
	int y;
	int k;
	char *c;

	k = ft_strlen(line);
	x = 0;
	y = 0;
	while (line[x + y] && k)
	{
		while (line[x] < 33 || line[x] == *tipo)
		{
			if (ft_strlen(tipo) > 1)
				if (line[x] == *tipo && line[x + 1] == *(tipo + 1))
					x++;
			x++;
		}
		while(ft_isascii(line[x + y]) > 0)
			y++;
		c = ft_substr(line, x, y);
		k--;
	}
	return (c);
}

t_godfather ft_tratafc(char *line, t_godfather all, char cas)
{
	int x;
	int y;
	char *c;
	int k;

	k = 0;
	y = 0;
	x = 0;
	while (k < 3)
	{
		x += y;
		while (ft_isdigit(line[x]) == 0 || line[x] == ',')
			x++;
		while (ft_isdigit(line[x + y]) > 0 && line[x + y] != ',')
			y++;
		c = ft_substr(line, x, y);
		if (cas == 'F')
			all.caso.f[k] = ft_atoi(c);
		if (cas == 'C')
			all.caso.c[k] = ft_atoi(c);
		k++;
	}
	return (all);
}
