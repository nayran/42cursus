/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:09:31 by nayran            #+#    #+#             */
/*   Updated: 2020/12/28 18:46:56 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char *buff)
{
	char	*arg;
	int		x;

	buff = ft_antispace(buff);
	arg = ft_firstword(buff);
	buff = ft_antispace(&buff[ft_strlen(arg)]);
	ft_printf("exit\n");
	if (ft_strlen(buff))
	{
		ft_printf("minishell: exit: too many arguments\n");
		return (255);
	}
	x = 0;
	g_vars->aftercmd = 0;
	if (ft_strlen(arg) && ft_isdigit((int)arg[0]))
		x = ft_atoi(arg);
	else if (!ft_isdigit((int)arg[0]) && arg[0] != 0)
	{
		ft_printf("minishell: exit: %s: numeric argument required\n", arg);
		x = 255;
	}
	kill(0, SIGQUIT);
	exit(x);
	return (0);
}
