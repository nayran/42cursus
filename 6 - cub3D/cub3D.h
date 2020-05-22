/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:50:22 by nayran            #+#    #+#             */
/*   Updated: 2020/05/22 14:20:02 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "others/get_next_line/get_next_line.h"
# include "others/minilibx/mlx.h"
# include <fcntl.h>

typedef struct	s_mapa
{
	int		width;
	char	*line;
}				t_mapa;

typedef struct	s_pathcaso
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			r[2];
	int			f[3];
	int			c[3];
	int			map;
	int			error;
	ssize_t		nread;
	int			**final_map;
	int			map_height;
	int			map_width;
}				t_pathcaso;

typedef struct	s_godfather
{
	t_mapa		*mapa;
	t_pathcaso	caso;
}				t_godfather;

t_godfather		ft_lecube(char *path);
t_godfather		ft_trata_r(char *line, t_godfather all);
t_godfather		ft_tratafc(char *line, t_godfather all, char cas);
t_godfather		ft_tratageral(char *line, char *tipo, t_godfather all);
t_godfather		ft_tratamapa(char *line, t_godfather all);
t_godfather		ft_mapafinal(t_godfather all);
t_godfather		ft_convertemapa(t_godfather all);
char			*ft_enquadro(char *str, int width);
int				ft_mapeamento(t_godfather all);
int				ft_mapeamento2(t_godfather all);
#endif
