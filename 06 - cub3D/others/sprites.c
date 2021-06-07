/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:44:44 by nayran            #+#    #+#             */
/*   Updated: 2020/06/24 04:24:34 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_appearing(int winx, double buf, double y, int x)
{
	return (y > 0 && x > 0 && x < winx && y < buf);
}

static void	ft_spritepos(t_godfather *all, t_sprite *sprt, t_draw *pos)
{
	pos->y = -sprt->height / 2 + all->wy / 2;
	if (pos->y < 0)
		pos->y = 0;
	pos->y_end = sprt->height / 2 + all->wy / 2;
	if (pos->y_end >= all->wy)
		pos->y_end = all->wy - 1;
	pos->x = -sprt->height / 2 + sprt->side;
	if (pos->x < 0)
		pos->x = 0;
	pos->x_end = sprt->height / 2 + sprt->side;
	if (pos->x_end >= all->wx)
		pos->x_end = all->wx - 1;
}

static void	ft_rendersprites2(t_godfather *all, t_ray *ray, t_sprite *sprt,
		t_text *text)
{
	t_draw	pos;
	int		y;
	int		texel;

	ft_spritepos(all, sprt, &pos);
	while (pos.x < pos.x_end)
	{
		if (ft_appearing(all->wx, ray->z_buf[pos.x], sprt->trans_y, pos.x))
		{
			text->x = (int)(256 * (pos.x - (-sprt->height / 2 + sprt->side)) \
			* 64 / sprt->height) / 256;
			y = pos.y - 1;
			while (++y < pos.y_end)
			{
				sprt->d = y * 256 - all->wy * 128 + sprt->height * 128;
				text->y = ((sprt->d * 64) / sprt->height) / 256;
				texel = text->data[text->y * 64 + text->x];
				if (texel << 24 != 0x00)
					all->img.addr[pos.x + (y - 1) * all->wx] = texel;
			}
		}
		pos.x++;
	}
}

void		ft_rendersprites(t_godfather *all, t_cam *cam, t_sprite *arr,
		int size)
{
	int		i;
	double	inv;

	i = 0;
	inv = 1.0 / (cam->plane_x * cam->dir_y - cam->plane_y * cam->dir_x);
	while (i < size)
	{
		arr[i].x = arr[i].map_x - cam->pos_x;
		arr[i].y = arr[i].map_y - cam->pos_y;
		arr[i].trans_x = inv * (cam->dir_y * arr[i].x - cam->dir_x * arr[i].y);
		arr[i].trans_y = inv * (-cam->plane_y * arr[i].x + cam->plane_x \
		* arr[i].y);
		arr[i].side = (int)((all->wx / 2) * \
		(1 + arr[i].trans_x / arr[i].trans_y));
		arr[i].height = abs((int)(all->wy / arr[i].trans_y));
		ft_rendersprites2(all, &cam->ray, &arr[i], &all->text[4]);
		i++;
	}
}

void		ft_raysprites(t_map *map, t_cam *cam)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	while (i < map->sprites_nb)
	{
		x = map->sprites[i].map_x;
		y = map->sprites[i].map_y;
		map->sprites[i].dist = pow(cam->pos_x - x, 2) * pow(cam->pos_y - y, 2);
		i++;
	}
	ft_spritesort(map->sprites, map->sprites_nb);
}
