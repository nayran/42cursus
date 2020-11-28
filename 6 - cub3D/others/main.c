/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:43:37 by nayran            #+#    #+#             */
/*   Updated: 2020/06/24 08:04:23 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_quit(t_godfather *all)
{
	free(all->map.sprites);
	free(all->cam.ray.z_buf);
	mlx_destroy_image(all->mlx, all->img.ptr);
	mlx_destroy_window(all->mlx, all->win);
	exit(1);
	return (0);
}

static int	ft_error(int error)
{
	if (error == 1 || error == 2 || error == 3 || error == 6 || error == 7)
		ft_printf("Error\nFile Error\n");
	else if (error == 4 || error == 8)
		ft_printf("Error\nMap Error\n");
	else if (error == 5)
		ft_printf("Error\nResolution Error\n");
	return (0);
}

static void	ft_init2(t_cam *cam, t_map *map)
{
	cam->pos_x = (double)map->start_x + 0.5;
	cam->pos_y = (double)map->start_y + 0.5;
	if (map->start_dir == 'N' || map->start_dir == 'S')
	{
		cam->dir_y = map->start_dir == 'N' ? -1 : 1;
		cam->plane_x = map->start_dir == 'N' ? 0.66 : -0.66;
	}
	else if (map->start_dir == 'W' || map->start_dir == 'E')
	{
		cam->dir_x = map->start_dir == 'W' ? -1 : 1;
		cam->plane_y = map->start_dir == 'W' ? -0.66 : 0.66;
	}
	cam->ms = 0.05;
	cam->rs = 0.05;
}

static void	ft_init(t_godfather *all)
{
	char	*title;

	title = ft_strjoin("cub3D : ", all->map.map_name);
	free((void*)all->map.map_name);
	all->map.map_name = NULL;
	all->win = mlx_new_window(all->mlx, all->wx, all->wy, title);
	free((void*)title);
	all->img.ptr = mlx_new_image(all->mlx, all->wx, all->wy);
	all->img.addr = (int*)mlx_get_data_addr(all->img.ptr, &all->img.bpp,\
	&all->img.size_l, &all->img.endian);
	all->img.bpp /= 8;
	all->map.sprites->img.ptr = mlx_new_image(all->mlx, all->wx, all->wy);
	all->map.sprites->img.addr =
		(int*)mlx_get_data_addr(all->map.sprites->img.ptr,\
				&all->map.sprites->img.bpp, &all->map.sprites->img.size_l,
				&all->map.sprites->img.endian);
	all->map.sprites->img.bpp /= 8;
	all->time = clock();
	all->cam.ray.z_buf = malloc(all->wx * sizeof(double));
	if (all->cam.ray.z_buf == NULL)
		ft_quit(all);
	ft_init2(&all->cam, &all->map);
}

int			main(int argc, char **argv)
{
	t_godfather	all;
	int			error;

	if (argc == 3 && ft_strcmp(argv[2], "--save"))
		return (ft_error(1));
	else if (argc != 2 && argc != 3)
		return (ft_error(1));
	ft_bzero(&all, sizeof(t_godfather));
	all.mlx = mlx_init();
	error = ft_lecube(&all, argv[1]);
	if (error != 10)
		return (ft_error(error));
	ft_init(&all);
	if (argc == 3 && ft_bmp(&all) != 10)
		return (ft_error(2));
	else if (argc == 2)
	{
		mlx_hook(all.win, 17, 0L, ft_quit, &all);
		mlx_hook(all.win, 2, (1L << 0), key_press, &all);
		mlx_hook(all.win, 3, (1L << 1), key_release, &all);
		mlx_loop_hook(all.mlx, ft_loop, &all);
		mlx_loop(all.mlx);
	}
	return (ft_quit(&all));
}
