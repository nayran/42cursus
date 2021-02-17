/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:55:40 by nayran            #+#    #+#             */
/*   Updated: 2021/02/17 13:50:13 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_handleenv(char *env, char *exec)
{
	int		x;
	char	*aux;
	char	*aux2;

	if (!env || !(x = -1))
		return (NULL);
	if (!ft_strnstr(env, ":", ft_strlen(env)))
		if (ft_isfile(ft_strjoin(env, exec)))
			return (ft_strjoin(env, exec));
	aux = ft_strdup(env);
	while (aux[++x])
		if (aux[x] == ':')
		{
			aux2 = ft_strdup(&aux[x + 1]);
			aux[x] = '\0';
			aux = ft_strjoin(aux, exec);
			if (ft_isfile(aux))
				return (aux);
			aux = aux2;
			x = -1;
		}
	aux = ft_strjoin(aux, exec);
	if (!ft_issameend(aux, exec))
		return (NULL);
	return (aux);
}

char	*ft_handlepath(char *buff)
{
	char	*aux;

	aux = ft_firstword(buff);
	if (aux[0] != '/' && !ft_strnstr(aux, "./", 2))
	{
		aux = ft_strjoin("/", aux);
		aux = ft_handleenv(ft_returnenvvar("PATH"), aux);
	}
	return (aux);
}

int		ft_handleargs(char *buff, int x)
{
	char		*path;
	int			redir;

	x = 1;
	redir = ft_isredirection(buff);
	if (redir)
		buff = ft_removefilename(buff);
	path = ft_handlepath(buff);
	if (path && ft_isexec(path))
		x = ft_exec(buff, path);
	else if (ft_strnstr(buff, "env", 3))
		x = ft_allenv();
	else if (ft_strnstr(buff, "$", 1))
		ft_callvars(buff, x);
	else if (!ft_isfile(path) || !ft_isvar(buff))
	{
		if (ft_isallquote(buff))
		{
			buff = &buff[1];
			buff[ft_strlen(buff) - 1] = '\0';
		}
		ft_printf("minishell: command not found: %s\n", buff);
	}
	return (x);
}

int		ft_initialargs(char *buff, int num)
{
	if (ft_isvar(buff))
		num = ft_vars(buff);
	else if (ft_strnstr(buff, "exit", 4))
		num = ft_exit(&buff[4]);
	else if (ft_strnstr(buff, "cd", 2))
		num = ft_cd(buff);
	else if (ft_strnstr(buff, "export", 6))
		num = ft_export(buff);
	else if (ft_strnstr(buff, "unset", 5))
		num = ft_unset(buff);
	return (num);
}

void	ft_args(char *buff)
{
	pid_t		pid;
	static int	num;

	if (ft_isredirection(buff))
		ft_redirargs(buff);
	else
	{
		buff = ft_removelinebreak(buff);
		buff = ft_antispace(buff);
		if (ft_isinitargs(buff))
			num = ft_initialargs(buff, num);
		else
		{
			pid = fork();
			if (pid == 0)
			{
				signal(SIGINT, NULL);
				num = ft_handleargs(buff, num);
				exit(num);
			}
			else
				waitpid(pid, &num, 0);
		}
		ft_vars(ft_strjoin("?=", ft_itoa(num)));
	}
}
