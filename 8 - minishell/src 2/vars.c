/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:40:01 by nayran            #+#    #+#             */
/*   Updated: 2020/12/10 17:53:37 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_callvars(char *buff, int num)
{
	int		x;
	char	*aux;

	x = -1;
	aux = ft_strdup(&buff[1]);
	while (aux[++x])
		if (aux[x] == ' ')
			break ;
	aux[x] = '\0';
	aux = ft_returnvalue(aux);
	if (aux)
		aux = ft_strjoin(aux, &buff[x + 1]);
	else
		aux = &buff[x];
	ft_handleargs(aux, num);
}

char	*ft_returnvalue(char *name)
{
	t_vars *aux;

	aux = g_vars;
	while (aux->next)
	{
		if (ft_exactstr(aux->name, name))
			return (aux->value);
		aux = aux->next;
	}
	return (ft_returnenvvar(name));
}

void	ft_varupdate(char *name, char *value)
{
	t_vars	*aux;
	int		x;

	aux = g_vars;
	while (aux->next)
	{
		if (ft_exactstr(aux->name, name))
			aux->value = value;
		aux = aux->next;
	}
	x = -1;
	name = ft_strjoin(name, "=");
	while (g_envp[++x])
	{
		if (ft_strnstr(g_envp[x], name, ft_strlen(name)))
			g_envp[x] = ft_strjoin(name, value);
	}
}

char	*ft_returnname(char *buff)
{
	char	*name;
	int		equalpos;

	name = ft_strdup(buff);
	equalpos = ft_isvar(buff);
	name[equalpos] = '\0';
	return (name);
}

int		ft_vars(char *buff)
{
	int			equalpos;
	char		*name;
	char		*value;
	t_vars		*aux;

	name = ft_returnname(buff);
	equalpos = ft_isvar(buff);
	value = ft_strdup(&buff[++equalpos]);
	if (ft_isitvar(name) == 0)
	{
		aux = malloc(sizeof(t_vars));
		aux->name = name;
		aux->value = value;
		aux->exported = 0;
		aux->next = g_vars;
		g_vars = aux;
	}
	else
		ft_varupdate(name, value);
	return (0);
}
