/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:58:45 by nayran            #+#    #+#             */
/*   Updated: 2021/02/09 15:43:32 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_pwd(char *buff, char *path)
{
	char	**av;
	char	*aux;

	av = malloc(ARG_MAX);
	av[0] = path;
	aux = ft_strdup(buff);
	aux = ft_antispace(&aux[3]);
	av[1] = NULL;
	return (av);
}

char	**ft_otherexecs2(char **av, char *aux, int n)
{
	int		x;
	int		y;

	x = 0;
	while (++x <= n)
	{
		av[x] = ft_strdup(aux);
		y = -1;
		while (av[x][++y])
			if (av[x][y] == ' ')
			{
				av[x][y] = '\0';
				aux = &av[x][y + 1];
			}
	}
	av[x] = NULL;
	return (av);
}

char	**ft_otherexecs(char *buff, char *path)
{
	char	**av;
	char	*aux;
	int		n;

	n = ft_numberofspaces(buff);
	av = malloc((n + 1) * sizeof(char *));
	av[0] = path;
	aux = ft_strdup(buff);
	aux = ft_antispace(&aux[ft_strlen(ft_firstword(aux))]);
	aux = ft_removelineendspace(aux);
	if (ft_strlen(aux) > 0)
		av = ft_otherexecs2(av, aux, n);
	else
		av[1] = NULL;
	return (av);
}

char	**ft_handleexecargs(char *buff, char *path)
{
	char	**args;

	args = NULL;
	if (ft_strnstr(ft_firstword(buff), "echo", 4))
		args = ft_echo(buff, path);
	else if (ft_strnstr(ft_firstword(buff), "pwd", 3))
		args = ft_pwd(buff, path);
	else
		args = ft_otherexecs(buff, path);
	return (args);
}

int		ft_exec(char *buff, char *path)
{
	char	**args;

	args = ft_handleexecargs(buff, path);
	if (args == NULL)
		return (16);
	if (execve(path, args, g_envp) < 0)
		return (16);
	free(args);
	return (0);
}
