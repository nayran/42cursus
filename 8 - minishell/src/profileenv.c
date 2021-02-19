/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   profileenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:22:30 by nayran            #+#    #+#             */
/*   Updated: 2020/12/10 17:23:14 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_returnenvvar(char *name)
{
	int x;

	x = -1;
	name = ft_strjoin(name, "=");
	while (g_envp[++x])
		if (ft_strnstr(g_envp[x], name, ft_strlen(name)))
			return (&g_envp[x][ft_strlen(name)]);
	return (NULL);
}

int		ft_allenv(void)
{
	char	**aux;

	if (!g_envp)
		return (12);
	aux = g_envp;
	while (*aux)
	{
		ft_printf("%s\n", *aux);
		aux++;
	}
	return (0);
}
