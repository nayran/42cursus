/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:25:56 by nayran            #+#    #+#             */
/*   Updated: 2021/02/10 13:59:29 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_readout(int r, char *argv)
{
	char *aux;

	g_vars->aftercmd = 1;
	if (r < 0 || *argv == '\0')
		ft_exit("1");
	if (argv[ft_strlen(argv) - 1] == '\n')
		ft_handler(argv);
	else
	{
		aux = malloc(4096);
		read(1, aux, 4096);
		argv = ft_strjoin(argv, aux);
		ft_readout(r, argv);
	}
}

void	ft_sighandler(int sig)
{
	if (sig == 3)
	{
		if (g_vars->aftercmd == 1)
			ft_printf("Quit: %d\n", sig);
	}
	if (sig == 2)
	{
		write(1, "\n", 1);
		if (g_vars->aftercmd == 0)
			ft_printf("minishell $ ");
	}
}
