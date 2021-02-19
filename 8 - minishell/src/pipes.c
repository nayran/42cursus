/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:06:04 by nayran            #+#    #+#             */
/*   Updated: 2021/01/13 14:35:21 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_pipe1(int *pipefd, char *buff, int num)
{
	signal(SIGINT, NULL);
	if (ft_isredirection(buff))
		ft_redirpipe1(pipefd, buff);
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
	}
	num = ft_handleargs(buff, num);
	exit(num);
}

void		ft_pipe2(int *pipefd, char *buff, int num)
{
	signal(SIGINT, NULL);
	if (ft_isredirection(buff))
		ft_redirpipe2(pipefd, buff);
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
	}
	num = ft_handleargs(buff, num);
	exit(num);
}

int			ft_closepipes(int *pipefd, int num, pid_t p1, pid_t p2)
{
	close(pipefd[1]);
	close(pipefd[0]);
	waitpid(p1, &num, 0);
	waitpid(p2, &num, 0);
	return (num);
}

int			ft_pipes2(char *b1, char *b2, int *pipefd, int num)
{
	pid_t		p1;
	pid_t		p2;

	p1 = fork();
	if (p1 == 0)
		ft_pipe1(pipefd, b1, num);
	else if (p1 > 0)
	{
		wait(NULL);
		b2 = ft_removeallspaces(b2);
		p2 = fork();
		if (p2 == 0)
			ft_pipe2(pipefd, b2, num);
		else
			num = ft_closepipes(pipefd, num, p1, p2);
	}
	return (num);
}

void		ft_pipes(char **buff, int pipesnum, int argnum)
{
	int			pipefd[2];
	static int	num;
	int			x;

	x = argnum;
	pipesnum -= 1;
	while (x < pipesnum)
	{
		buff[x] = ft_removeallspaces(buff[x]);
		if (ft_isinitargs(buff[x]))
			num = ft_initialargs(buff[x], num);
		else
		{
			if (pipe(pipefd) < 0)
			{
				ft_printf("minishell: pipe error\n");
				return ;
			}
			num = ft_pipes2(buff[x], buff[x + 1], pipefd, num);
			x++;
		}
		ft_vars(ft_strjoin("?=", ft_itoa(num)));
	}
}
