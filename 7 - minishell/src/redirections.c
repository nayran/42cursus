/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:04:43 by nayran            #+#    #+#             */
/*   Updated: 2021/02/03 15:02:50 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_returnfilename(char *buff)
{
	int		x;
	char	*aux;

	x = -1;
	aux = NULL;
	while (buff[++x])
	{
		if (buff[x] == '>' || buff[x] == '<')
		{
			if (buff[x + 1] == '>')
				aux = ft_strdup(&buff[x + 2]);
			else
				aux = ft_strdup(&buff[x + 1]);
			break ;
		}
	}
	aux = ft_antispace(aux);
	aux = ft_removelineendspace(aux);
	return (aux);
}

int		ft_returnfd(char *filename, int redirtype)
{
	int filefd;

	if (redirtype == 1)
		filefd = open(filename, O_RDWR | O_APPEND | O_CREAT, 0777);
	else if (redirtype == 2)
		filefd = open(filename, O_RDWR | O_TRUNC | O_CREAT, 0777);
	else
		filefd = open(filename, O_RDONLY);
	if (filefd < 0)
		ft_printf("minishell: no such file or directory: %s\n", filename);
	return (filefd);
}

char	*ft_secondredir(char *filename)
{
	return (ft_returnfilename(filename));
}

int		ft_redirargs2(char *buff, int filefd, int redirtype)
{
	pid_t		pid;
	static int	num;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, NULL);
		if (redirtype == 3)
		{
			dup2(filefd, STDIN_FILENO);
			close(filefd);
		}
		else
			close(1);
		dup2(filefd, STDOUT_FILENO);
		close(filefd);
		num = ft_handleargs(buff, num);
		exit(num);
	}
	else
	{
		close(filefd);
		waitpid(pid, &num, 0);
	}
	return (num);
}

void	ft_redirargs(char *buff)
{
	static int	num;
	int			filefd;
	int			redirtype;
	char		*filename;

	redirtype = ft_isredirection(buff);
	filename = ft_returnfilename(buff);
	if (ft_isredirection(filename))
		filename = ft_secondredir(filename);
	filefd = ft_returnfd(filename, redirtype);
	if (filefd < 0)
	{
		ft_printf("minishell: no such file or directory: %s\n", filename);
		return ;
	}
	buff = ft_removefilename(buff);
	if (ft_isinitargs(buff))
		num = ft_initialargs(buff, num);
	else
		num = ft_redirargs2(buff, filefd, redirtype);
	ft_vars(ft_strjoin("?=", ft_itoa(num)));
}
