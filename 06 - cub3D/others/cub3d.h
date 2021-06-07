/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:32:14 by nayran            #+#    #+#             */
/*   Updated: 2020/06/24 05:21:29 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "../utils/libft/libft.h"
# include "../utils/ft_printf/ft_printf.h"
# include "../utils/minilibx/mlx.h"

# define BUFF_SIZE	4096

typedef struct	s_img
{
	void		*ptr;
	int			*addr;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct	s_sprite
{
	double		map_x;
	double		map_y;
	double		dist;
	double		x;
	double		y;
	double		trans_x;
	double		trans_y;
	int			side;
	int			height;
	int			d;
	t_img		img;
}				t_sprite;

typedef struct	s_dda
{
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	int			step_x;
	int			step_y;
}				t_dda;

typedef struct	s_ray
{
	int			x;
	int			map_x;
	int			map_y;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	int			side;
	t_dda		dda;
	double		*z_buf;
}				t_ray;

typedef struct	s_wall
{
	double		dist;
	int			height;
	int			start;
	int			end;
	int			dir;
	double		x;
}				t_wall;

typedef struct	s_floor
{
	double		start_x;
	double		start_y;
	double		dist;
	double		x;
	double		y;
}				t_floor;

typedef struct	s_cam
{
	double		x;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		ms;
	double		rs;
	t_ray		ray;
	t_wall		wall;
	t_floor		floor;
}				t_cam;

typedef struct	s_move
{
	int			up:1;
	int			down:1;
	int			left:1;
	int			right:1;
	int			r_left:1;
	int			r_right:1;
}				t_move;

typedef struct	s_text
{
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			x;
	int			y;
}				t_text;

typedef struct	s_map
{
	char		*map_name;
	int			**map;
	int			x;
	int			y;
	int			start_x;
	int			start_y;
	char		start_dir;
	int			sprites_nb;
	t_sprite	*sprites;
}				t_map;

typedef struct	s_godfather
{
	int			wx;
	int			wy;
	void		*mlx;
	void		*win;
	int			color[2];
	t_text		text[5];
	t_img		img;
	t_map		map;
	t_cam		cam;
	t_move		move;
	clock_t		old_time;
	clock_t		time;
}				t_godfather;

typedef struct	s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef struct	s_draw
{
	int			y;
	int			y_end;
	int			x;
	int			x_end;
}				t_draw;

int				ft_lecube(t_godfather *all, const char *filename);
void			ft_skip(const char **line, const char *set);
int				ft_resolution(t_godfather *all, const char **line);
int				ft_textures(t_godfather *all, const char **line, int i);
int				ft_color(t_godfather *all, const char **line, int i);

int				ft_map(t_map *map, const char *line);
int				ft_validchar(char c, const char *set);
int				ft_mapalloc(t_map *map);
int				**ft_mapfree(int **map, int index_stop);
int				ft_mapcpy(t_map *map, const char *file);
int				ft_mapstart(t_map *map, int x, int y);

int				ft_bmp(t_godfather *all);

int				key_press(int keycode, t_godfather *all);
int				key_release(int keycode, t_godfather *all);

int				ft_loop(t_godfather *all);
void			ft_move(char c, int **map, t_cam *cam);
void			ft_rotate(char c, t_cam *cam);
void			ft_frame(t_godfather *all, t_cam *cam);
void			ft_raysprites(t_map *map, t_cam *cam);
void			ft_spritesort(t_sprite *sprites, int spriteqtd);

void			ft_render(t_godfather *all, t_wall *wall, int x);
void			ft_rendersprites(t_godfather *all, t_cam *cam, t_sprite *arr,
		int size);

int				ft_quit(t_godfather *all);
#endif
