#ifndef CUB3D_H
#define CUB3D_H

#include "utils/get_next_line/get_next_line.h"
#include "./minilibx/mlx.h"
#include <fcntl.h>

typedef struct	s_textura
{
	int	width;
	int	height;
}				t_textura;

typedef struct    s_mapa
{
    int        x;
    int        y;
    char    **line;
}                t_mapa;

typedef struct	s_pathcaso
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		r[2];
	int		f[3];
	int		c[3];
    int     map;
}				t_pathcaso;

typedef struct  s_godfather
{
        t_mapa      mapa;
        t_pathcaso  caso;
        t_textura   textura;
}               t_godfather;

int				ft_strstr(char *str, char *str2);
t_godfather		ft_lecube(char *path);
t_godfather		ft_trata_r(char *line, t_godfather all);
t_godfather		ft_tratafc(char *line, t_godfather all, char cas);
char			*ft_tratageral(char *line, char *tipo);
t_godfather		ft_tratamapa (char *line, t_godfather all);

#endif
