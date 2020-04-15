#include "../cub3D.h"

t_godfather ft_tratamapa(char *line, t_godfather all)
{
	all.mapa.line[all.mapa.y] = ft_substr(line, 0, ft_strlen(line));
	all.mapa.y++;
	return (all);
}
