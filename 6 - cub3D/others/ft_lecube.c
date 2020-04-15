#include "../cub3D.h"

int	ft_strstr(char *str, char *str2)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(str[x])
	{
		y = 0;
		while(str2[y] == str[x + y])
		{
			if (y  == ft_strlen(str2) - 1)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

t_godfather ft_tratacasos(char *line, t_godfather all)
{
	if (ft_strstr(line, "R") > 0)
		all = ft_trata_r(line, all);
	if (ft_strstr(line, "NO") > 0)
        all.caso.no = ft_tratageral(line, "NO");
	if (ft_strstr(line, "SO") > 0)
		all.caso.so = ft_tratageral(line, "SO");
	if (ft_strstr(line, "WE") > 0)
		all.caso.we = ft_tratageral(line, "WE");
	if (ft_strstr(line, "EA") > 0)
		all.caso.ea = ft_tratageral(line, "EA");
	if (ft_strstr(line, "S") > 0 && all.caso.map == 0)
		all.caso.s = ft_tratageral(line, "S");
	if (ft_strstr(line, "F") > 0)
		all = ft_tratafc(line, all, 'F');
	if (ft_strstr(line, "C") > 0)
		all = ft_tratafc(line, all, 'C');
	/*if (ft_strstr(line, "1") > 0)
		all = ft_tratamapa(line, all);*/
	return (all);
}

t_godfather inicializa_mapa(void)
{
    t_godfather m;

	m.mapa.x = 0;
	m.mapa.y = 0;
	m.mapa.line = NULL;
    m.caso.map = 0;
	return (m);
}

t_godfather	ft_lecube(char *path)
{
	int fd;
	char *line;
	ssize_t nread;
	t_godfather all;

	line = NULL;
    all = inicializa_mapa();
	if (!path)
		return (all);
	fd = open(path, O_RDONLY);
	while (( get_next_line(fd, &line)) > 0)
		all = ft_tratacasos(line, all);
	return (all);
}
