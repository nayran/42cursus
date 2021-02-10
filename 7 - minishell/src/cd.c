/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:44:08 by nayran            #+#    #+#             */
/*   Updated: 2021/02/03 15:04:21 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_homedir(void)
{
	int		x;
	char	*home;

	x = -1;
	home = NULL;
	while (g_envp[++x])
		if (ft_strnstr(g_envp[x], "HOME", 4))
			home = g_envp[x];
	if (home)
		home = ft_strdup(&home[5]);
	return (home);
}

char	*ft_path(void)
{
	char	cwd[256];
	char	*aux;

	getcwd(cwd, sizeof(cwd));
	aux = ft_strdup(cwd);
	return (aux);
}

void	ft_changeenv(void)
{
	int x;

	x = -1;
	while (g_envp[++x])
		if (ft_strnstr(g_envp[x], "PWD=", 4))
			g_envp[x] = ft_strjoin("PWD=", ft_path());
}

int		ft_cd(char *buff)
{
	int x;

	x = 0;
	if (!ft_isspace(buff[2]))
	{
		ft_printf("minishell: command not found: %s\n", buff);
		return (15);
	}
	buff = ft_antispace(&buff[2]);
	buff = ft_removelineendspace(buff);
	if (ft_strlen(buff) == 0)
		buff = ft_homedir();
	x = chdir(buff);
	if (x < 0)
	{
		ft_printf("cd: no such file or directory\n");
		return (15);
	}
	ft_changeenv();
	return (0);
}
