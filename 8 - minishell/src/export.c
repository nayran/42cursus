/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:14:33 by nayran            #+#    #+#             */
/*   Updated: 2021/02/17 15:25:22 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_isexec(char *path)
{
	int fd;
	int aux;

	aux = 1;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		aux = 0;
	close(fd);
	return (aux);
}

void	ft_putvarlst(char *name, char **env)
{
	char	*value;
	int		x;
	int		updated;

	x = -1;
	updated = 0;
	value = ft_returnvalue(name);
	while (env[++x])
	{
		if (ft_strnstr(g_envp[x], name, ft_strlen(name)))
		{
			ft_varupdate(name, value);
			updated = 1;
		}
	}
	if (!updated)
	{
		env[x] = malloc(sizeof(value) + sizeof(name) + 1);
		env[x] = ft_strjoin(ft_strjoin(name, "="), value);
		x++;
		env[x] = 0;
	}
}

int		ft_exportvar(char *name)
{
	t_vars	*vars;

	vars = g_vars;
	while (vars->next)
	{
		if (ft_exactstr(vars->name, name))
		{
			ft_putvarlst(name, g_envp);
			vars->exported = 1;
			return (1);
		}
		vars = vars->next;
	}
	return (0);
}

char	*ft_getvarname(char *name)
{
	int x;

	x = -1;
	while (name[++x])
		if (name[x] == ' ')
			break ;
	name[x] = '\0';
	return (name);
}

int		ft_export(char *buff)
{
	char *name;

	if (!ft_isspace(buff[6]))
		return (13);
	name = ft_antispace(&buff[6]);
	if (name[0] == 0)
		ft_allenv();
	else
	{
		name = ft_getvarname(name);
		if (ft_exportvar(name))
			return (0);
		else if (ft_isvar(name))
		{
			ft_vars(name);
			name = ft_returnname(name);
			if (ft_exportvar(name))
				return (0);
		}
		else
			return (13);
	}
	return (0);
}
