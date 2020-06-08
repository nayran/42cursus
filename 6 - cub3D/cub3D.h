/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 13:50:22 by nayran            #+#    #+#             */
/*   Updated: 2020/06/08 04:45:40 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "others/get_next_line/get_next_line.h"
# include "others/minilibx/mlx.h"

# define MINIMAP_SCALE 1.0

typedef struct	s_player
{
	float		x;
	float		y;
	float		width;
	float		height;
	int			turndirection;
	int			walkdirection;
	float		rotationangle;
	float		walkspeed;
	float		turnspeed;
}				t_player;

typedef struct	s_view
{
	void		*mlx;
	void		*window;
}				t_view;

typedef struct	s_data
{
	void		*img;
	char		*img_addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_texture
{
	t_data		data[5];
	int			th;
	int			tw;
	void		*colorbuffertex;
	char		*colorbuffer;
	char		*walltexture;
}				t_texture;

typedef	struct	s_map
{
	int			**map;
	int			map_height;
	int			map_width;
}				t_map;

typedef struct	s_cast
{
	float		xstep;
	float		ystep;
	float		xtocheck;
	float		ytocheck;
}				t_cast;

typedef struct	s_rays
{
	float		rayangle;
	float		wallhitx;
	float		wallhity;
	float		distance;
	int			washitvertical;
	int			facingup;
	int			facingdown;
	int			facingleft;
	int			facingright;
	int			wallhitcontent;
}				t_rays;

typedef struct	s_godfather
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		**mapaa;
	int			bmp;
	int			r[2];
	int			f[3];
	int			c[3];
	int			error;
	t_map		map;
	t_player	player;
}				t_godfather;

extern t_view		g_view;
extern t_godfather	g_all;
extern t_rays		*g_rays;
extern int			g_tilesize;
extern t_data		g_img;

t_godfather		ft_tratacasos(char *line, t_godfather all);
t_godfather		ft_mapafinal(t_godfather all);
t_godfather		ft_convertemapa(t_godfather all);
t_godfather		ft_copiamapa(char *line, t_godfather all);
char			*ft_enquadro(char *str, int width);
int				ft_mapeamento(t_godfather all);
void			ft_window(t_godfather all);
void			ft_sethooks();
void			ft_error(int error);
void			ft_update(void);
void			ft_render(void);
void			ft_pixelput(int x, int y, int color);
void			ft_drawsquare(int x, int y, int size, int color);
int				ft_iswall(float x, float y);
void			ft_castallrays();
void			ft_drawline(int x0, int y0, int x1, int y1);

#endif
