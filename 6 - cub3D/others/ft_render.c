/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 01:51:46 by nayran            #+#    #+#             */
/*   Updated: 2020/06/08 05:06:07 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_data	g_img;

void		ft_rendermap(void)
{
	int tilex;
	int tiley;
	int color;
	int y;
	int x;

	y = -1;
	while (++y < g_all.map.map_height)
	{
		x = -1;
		while (++x < g_all.map.map_width)
		{
			tilex = x * g_tilesize;
			tiley = y * g_tilesize;
			color = g_all.map.map[y][x] != 0 ? 0x000000 : 0xffffff;
			ft_drawsquare(tilex * MINIMAP_SCALE, tiley * MINIMAP_SCALE,
					g_tilesize * MINIMAP_SCALE, color);
		}
	}
}

void		ft_renderplayer(void)
{
	ft_drawsquare(g_all.player.x * MINIMAP_SCALE, g_all.player.y *
			MINIMAP_SCALE, g_all.player.width * MINIMAP_SCALE, 0x0066ff);
}

void		ft_renderrays(void)
{
	int i;

	i = -1;
	while (++i < g_all.r[0])
		ft_drawline(g_all.player.x * MINIMAP_SCALE, g_all.player.y *
				MINIMAP_SCALE, g_rays[i].wallhitx * MINIMAP_SCALE,
				g_rays[i].wallhity * MINIMAP_SCALE);
}

void		ft_render(void)
{
	g_img.img = mlx_new_image(g_view.mlx, g_all.r[0], g_all.r[1]);
	g_img.img_addr = mlx_get_data_addr(g_img.img, &g_img.bpp,
			&g_img.line_length, &g_img.endian);
	ft_rendermap();
	ft_renderrays();
	ft_renderplayer();
	mlx_put_image_to_window(g_view.mlx, g_view.window, g_img.img, 0, 0);
	mlx_destroy_image(g_view.mlx, g_img.img);
	ft_sethooks();
}
