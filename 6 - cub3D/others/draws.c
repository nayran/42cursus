/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:42:02 by nayran            #+#    #+#             */
/*   Updated: 2020/06/24 03:17:01 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_wallstrip(t_cam *cam, t_text *text)
{
	if (cam->ray.side)
		cam->wall.x = cam->ray.pos_x + cam->wall.dist * cam->ray.dir_x;
	else
		cam->wall.x = cam->ray.pos_y + cam->wall.dist * cam->ray.dir_y;
	cam->wall.x -= floor(cam->wall.x);
	text->x = (int)(cam->wall.x * 64.0);
	if (cam->ray.side && cam->ray.dir_y < 0)
		text->x = 64 - text->x - 1;
	if (!cam->ray.side && cam->ray.dir_x > 0)
		text->x = 64 - text->x - 1;
}

static void	ft_drawwall(t_godfather *all, int x, int y, t_text *text)
{
	int	texel;
	int	height;

	if (x < 0 || x >= all->wx || y < 0 || y >= all->wy)
		return ;
	height = all->cam.wall.height;
	text->y = y * 2 - all->wy + height;
	text->y = ((text->y) * 32) / height;
	texel = text->data[text->x + text->y * 64];
	all->img.addr[x + y * all->wx] = texel;
}

void		ft_render(t_godfather *all, t_wall *wall, int x)
{
	int y;

	ft_wallstrip(&all->cam, &all->text[wall->dir]);
	y = wall->start;
	while (y < wall->end)
		ft_drawwall(all, x, y++, &all->text[wall->dir]);
	ft_drawwall(all, x, y, &all->text[wall->dir]);
	while (y < all->wy)
	{
		if (x < 0 || x >= all->wx || y < 0 || y >= all->wy)
			break ;
		all->img.addr[x + y * all->wx] = all->color[0];
		all->img.addr[x + (all->wy - y - 1) * all->wx] = all->color[1];
		y++;
	}
}
