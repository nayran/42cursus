/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:38:41 by nayran            #+#    #+#             */
/*   Updated: 2020/12/28 19:47:35 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_vars	*ft_lastnode(t_vars *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int		ft_isvar(char *buff)
{
	int x;

	x = 0;
	while (ft_isalnum(buff[x]) || buff[x] == '?')
		x++;
	if (buff[x] == '=')
		return (x);
	return (0);
}

int		ft_exactstr(char *str1, char *str2)
{
	int x;

	x = 0;
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	while (str1[x] && str2[x])
	{
		if (str1[x] != str2[x])
			return (0);
		x++;
	}
	return (1);
}

int		ft_isitvar(char *name)
{
	t_vars *aux;

	aux = g_vars;
	while (aux->next)
	{
		if (ft_exactstr(aux->name, name))
			return (1);
		aux = aux->next;
	}
	if (ft_returnenvvar(name))
		return (2);
	return (0);
}

char	*ft_checkinit(char *buff, char c)
{
	if (buff[1] == c)
	{
		ft_printf("parse error near `%c%c'\n", c, c);
		return (NULL);
	}
	else if (buff[0] == c)
		return (&buff[1]);
	return (NULL);
}
