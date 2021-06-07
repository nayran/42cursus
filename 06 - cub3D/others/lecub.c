/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:43:45 by nayran            #+#    #+#             */
/*   Updated: 2020/06/24 05:25:12 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_casecheck(const char *str)
{
	if (!ft_strncmp("R ", str, 2))
		return (5);
	if (!ft_strncmp("NO ", str, 3))
		return (0);
	if (!ft_strncmp("SO ", str, 3))
		return (1);
	if (!ft_strncmp("WE ", str, 3))
		return (2);
	if (!ft_strncmp("EA ", str, 3))
		return (3);
	if (!ft_strncmp("S ", str, 2))
		return (4);
	if (!ft_strncmp("F ", str, 2))
		return (6);
	if (!ft_strncmp("C ", str, 2))
		return (7);
	return (9);
}

static int		ft_typecheck(t_godfather *all, const char *filename)
{
	size_t	len;

	if ((len = ft_strlen(filename)) < 5)
		return (3);
	if (ft_strncmp(".cub", filename + (len - 4), 4))
		return (3);
	if ((all->map.map_name = (char*)malloc(len - 3)) == NULL)
		return (3);
	ft_strlcpy(all->map.map_name, filename, len - 3);
	return (10);
}

static int		ft_filecheck(t_godfather *all, const char *file)
{
	int			i;
	static int	x;

	while (x < 8)
	{
		ft_skip(&file, " \n");
		i = ft_casecheck(file);
		if (i == 9)
			return (4);
		ft_skip(&file, " RNOSWEAFC");
		if (i == 5 && ft_resolution(all, &file) != 10)
			return (5);
		if (i >= 0 && i <= 4 && ft_textures(all, &file, i) != 10)
			return (6);
		if ((i == 6 || i == 7) && ft_color(all, &file, i) != 10)
			return (7);
		x++;
	}
	ft_skip(&file, " \n");
	if (ft_map(&all->map, file) != 10)
		return (8);
	return (10);
}

static char		*ft_readfile(int fd, size_t offset)
{
	char		buffer[BUFF_SIZE];
	char		*new;
	size_t		count;

	if (read(fd, buffer, 0) < 0)
		return (NULL);
	if (!(count = read(fd, buffer, BUFF_SIZE)))
	{
		close(fd);
		return ((char*)ft_calloc(offset + 1, sizeof(char)));
	}
	if (!(new = ft_readfile(fd, offset + count)))
		return (NULL);
	ft_memcpy(new + offset, buffer, count);
	return (new);
}

int				ft_lecube(t_godfather *all, const char *filename)
{
	char	*file;
	int		error;

	if (ft_typecheck(all, filename) != 10)
		return (3);
	if (!(file = ft_readfile(open(filename, O_RDONLY), 0)))
		return (2);
	error = ft_filecheck(all, file);
	if (error != 10)
		return (error);
	free(file);
	return (10);
}
