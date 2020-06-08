/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 12:57:00 by nayran            #+#    #+#             */
/*   Updated: 2020/06/08 02:07:09 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_view		g_view;
t_godfather	g_all;
t_rays		*g_rays;
int			g_tilesize;

/*
** ft_window:
** t_texture	*tex;
** tex = (t_texture *)malloc(sizeof(t_texture));
**
** ft_setup:
** tex->colorbuffer = (char *)malloc(sizeof(char *) * all->r[0] * all->r[1]);
** tex->colorbuffertex = mlx_new_image(v->mlx, all->r[0], all->r[1]);
** tex->walltexture = (char *)malloc(sizeof(char *) * all->r[0] * all->r[1]);
** load_textures(all, v, tex);
**
** void		load_textures(t_godfather *all, t_view *v, t_texture *tex)
** {
** tex->data[0].img =
**		mlx_xpm_file_to_image(v->mlx, all->no, &tex->tw, &tex->th);
** tex->data[0].img_addr = mlx_get_data_addr(tex->data[0].img,
**		&tex->data[0].bpp, &tex->data[0].line_length, &tex->data[0].endian);
** tex->data[1].img =
**		mlx_xpm_file_to_image(v->mlx, all->so, &tex->tw, &tex->th);
** tex->data[1].img_addr = mlx_get_data_addr(tex->data[1].img,
**		&tex->data[1].bpp, &tex->data[1].line_length, &tex->data[1].endian);
** tex->data[2].img =
**		mlx_xpm_file_to_image(v->mlx, all->we, &tex->tw, &tex->th);
** tex->data[2].img_addr = mlx_get_data_addr(tex->data[2].img,
**		&tex->data[2].bpp, &tex->data[2].line_length, &tex->data[2].endian);
** tex->data[3].img =
**		mlx_xpm_file_to_image(v->mlx, all->ea, &tex->tw, &tex->th);
** tex->data[3].img_addr = mlx_get_data_addr(tex->data[3].img,
**		&tex->data[3].bpp, &tex->data[3].line_length, &tex->data[3].endian);
** tex->data[4].img =
**		mlx_xpm_file_to_image(v->mlx, all->s, &tex->tw, &tex->th);
** tex->data[4].img_addr = mlx_get_data_addr(tex->data[4].img,
**		&tex->data[4].bpp, &tex->data[4].line_length, &tex->data[4].endian);
** }
*/

void		ft_setup(void)
{
	g_tilesize = ceil(((g_all.r[0] / g_all.map.map_width) +
				(g_all.r[1] / g_all.map.map_height)) / 2);
	g_all.player.width = 1;
	g_all.player.height = 1;
	g_all.player.turndirection = 0;
	g_all.player.walkdirection = 0;
	g_all.player.rotationangle = M_PI / 2;
	g_all.player.walkspeed = 100;
	g_all.player.turnspeed = 45 * (M_PI / 180);
	g_all.player.x *= g_tilesize;
	g_all.player.y *= g_tilesize;
}

void		ft_window(t_godfather all)
{
	int			x;
	int			y;

	g_all = all;
	g_view.mlx = mlx_init();
	mlx_get_screen_size(g_view.mlx, &x, &y);
	if (all.r[0] > x || all.r[1] > y || all.error == 10)
		ft_error(10);
	g_view.window = mlx_new_window(g_view.mlx, all.r[0], all.r[1], "cub3D");
	mlx_do_key_autorepeaton(g_view.mlx);
	ft_setup();
	ft_update();
	ft_sethooks();
	mlx_loop(g_view.mlx);
}
