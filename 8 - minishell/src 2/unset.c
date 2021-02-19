/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:29:17 by nayran            #+#    #+#             */
/*   Updated: 2021/02/03 15:04:46 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_excludeenvvar2(char *name)
{
	int x;

	x = -1;
	while (g_envp[++x])
		if (ft_strnstr(g_envp[x], name, ft_strlen(name)))
		{
			if (ft_isitvar(name) == 2)
				g_envp[x][ft_strlen(name) + 1] = 0;
			else
			{
				if (!g_envp[x + 1])
					g_envp[x] = 0;
				else
				{
					while (g_envp[x])
					{
						g_envp[x] = g_envp[x + 1];
						x++;
					}
					break ;
				}
			}
		}
	return (0);
}

int		ft_excludeenvvar(char *name)
{
	t_vars	*aux;
	t_vars	*aux2;

	aux = g_vars;
	aux2 = malloc(sizeof(t_vars));
	g_vars = aux2;
	while (aux->next)
	{
		if (!ft_exactstr(aux->name, name))
		{
			aux2->name = aux->name;
			aux2->value = aux->value;
			aux2->exported = aux->exported;
			aux2->next = malloc(sizeof(t_vars));
			aux2 = aux2->next;
		}
		aux = aux->next;
	}
	aux2->next = NULL;
	return (0);
}

int		ft_unset(char *buff)
{
	char *name;

	if (!ft_isspace(buff[5]))
		return (14);
	name = ft_strdup(buff);
	name = ft_antispace(&name[5]);
	if (!name)
		return (14);
	name = ft_getvarname(name);
	ft_excludeenvvar2(name);
	return (ft_excludeenvvar(name));
}
