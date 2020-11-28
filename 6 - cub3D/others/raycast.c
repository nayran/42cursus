/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:44:22 by nayran            #+#    #+#             */
/*   Updated: 2020/06/24 04:25:58 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_lineinit(t_ray *ray, t_dda *dda)
{
	dda->delta_x = fabs(1 / ray->dir_x);
	dda->delta_y = fabs(1 / ray->dir_y);
	if (ray->dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_x = (ray->pos_x - ray->map_x) * dda->delta_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_x = (ray->map_x + 1.0 - ray->pos_x) * dda->delta_x;
	}
	if (ray->dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_y = (ray->pos_y - ray->map_y) * dda->delta_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_y = (ray->map_y + 1.0 - ray->pos_y) * dda->delta_y;
	}
}

static void	ft_drawline(int **map, t_ray *ray)
{
	ft_lineinit(ray, &ray->dda);
	while (1)
	{
		if (ray->dda.side_x < ray->dda.side_y)
		{
			ray->dda.side_x += ray->dda.delta_x;
			ray->map_x += ray->dda.step_x;
			ray->side = 0;
		}
		else
		{
			ray->dda.side_y += ray->dda.delta_y;
			ray->map_y += ray->dda.step_y;
			ray->side = 1;
		}
		if (map[ray->map_y][ray->map_x] == 1)
			return ;
	}
}

static void	ft_raycasting(t_godfather *all, t_cam *cam, t_ray *ray)
{
	cam->x = 2 * ray->x / (double)all->wx - 1;
	ray->pos_x = cam->pos_x;
	ray->pos_y = cam->pos_y;
	ray->dir_x = cam->dir_x + cam->plane_x * cam->x;
	ray->dir_y = cam->dir_y + cam->plane_y * cam->x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ft_drawline(all->map.map, ray);
	if (ray->side)
		cam->wall.dist = (ray->map_y - ray->pos_y + \
		(1 - ray->dda.step_y) / 2) / ray->dir_y;
	else
		cam->wall.dist = (ray->map_x - ray->pos_x + \
		(1 - ray->dda.step_x) / 2) / ray->dir_x;
}

void		ft_frame(t_godfather *all, t_cam *cam)
{
	while (cam->ray.x < all->wx)
	{
		ft_raycasting(all, cam, &cam->ray);
		cam->ray.z_buf[cam->ray.x] = cam->wall.dist;
		cam->wall.height = (int)(all->wy / cam->wall.dist);
		cam->wall.start = -cam->wall.height / 2 + all->wy / 2;
		if (cam->wall.start < 0)
			cam->wall.start = 0;
		cam->wall.end = cam->wall.height / 2 + all->wy / 2;
		if (cam->wall.start >= all->wy)
			cam->wall.end = all->wy - 1;
		if (cam->ray.side)
			cam->wall.dir = cam->ray.dir_y < 0 ? 0 : 1;
		else
			cam->wall.dir = cam->ray.dir_x < 0 ? 2 : 3;
		ft_render(all, &cam->wall, cam->ray.x);
		cam->ray.x++;
	}
	ft_raysprites(&all->map, cam);
	ft_rendersprites(all, cam, all->map.sprites, all->map.sprites_nb);
	mlx_put_image_to_window(all->mlx, all->win, all->img.ptr, 0, 0);
	cam->ray.x = 0;
}

int			ft_loop(t_godfather *all)
{
	if (all->move.up)
		ft_move('u', all->map.map, &all->cam);
	if (all->move.down)
		ft_move('d', all->map.map, &all->cam);
	if (all->move.right)
		ft_move('r', all->map.map, &all->cam);
	if (all->move.left)
		ft_move('l', all->map.map, &all->cam);
	if (all->move.r_right)
		ft_rotate('r', &all->cam);
	if (all->move.r_left)
		ft_rotate('l', &all->cam);
	ft_frame(all, &all->cam);
	return (0);
}
