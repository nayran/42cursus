/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:34:52 by nayran            #+#    #+#             */
/*   Updated: 2021/02/09 14:35:44 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_envp;
t_vars	*g_vars;

void	ft_prompt(char *argv)
{
	ssize_t r;

	g_vars->aftercmd = 0;
	ft_bzero(argv, 4096);
	ft_printf("minishell $ ");
	r = read(1, argv, 4096);
	ft_readout(r, argv);
}

int		main(int argc, char **av, char **envp)
{
	static char		argv[4096 + 1];

	ft_gvarsinit();
	(void)(*av);
	(void)(argc);
	g_envp = envp;
	signal(SIGQUIT, ft_sighandler);
	signal(SIGINT, ft_sighandler);
	while (1)
		ft_prompt(argv);
	return (0);
}
