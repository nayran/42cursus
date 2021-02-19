/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:15:14 by nayran            #+#    #+#             */
/*   Updated: 2021/01/13 15:16:39 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_redirpipe1(int *pipefd, char *buff)
{
	int		filefd;
	char	*filename;
	int		redirtype;

	filename = ft_returnfilename(buff);
	redirtype = ft_isredirection(buff);
	filefd = ft_returnfd(filename, redirtype);
	if (filefd < 0)
		return ;
	buff = ft_removefilename(buff);
	if (redirtype == 3)
	{
		dup2(filefd, STDIN_FILENO);
		close(filefd);
		close(1);
		dup2(pipefd[1], 1);
	}
	else
		close(1);
	dup2(filefd, STDOUT_FILENO);
	dup2(pipefd[1], filefd);
	close(pipefd[0]);
	close(filefd);
}

void		ft_redirpipe2(int *pipefd, char *buff)
{
	int		filefd;
	char	*filename;
	int		redirtype;

	filename = ft_returnfilename(buff);
	redirtype = ft_isredirection(buff);
	filefd = ft_returnfd(filename, redirtype);
	if (filefd < 0)
		return ;
	buff = ft_removefilename(buff);
	if (redirtype == 3)
	{
		dup2(filefd, STDIN_FILENO);
		close(filefd);
	}
	else
		close(1);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(filefd, STDOUT_FILENO);
	close(filefd);
	close(pipefd[0]);
}
