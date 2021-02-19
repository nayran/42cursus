/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:53:58 by nayran            #+#    #+#             */
/*   Updated: 2021/02/03 15:07:57 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_excludevar(char *buff, char *aux, char *value)
{
	int		x;
	char	*final;

	x = 0;
	while (buff[x] && aux[x] && buff[x] == aux[x])
		x++;
	while (buff[x])
	{
		if (buff[x] == ' ')
			break ;
		x++;
	}
	if (value)
		aux = ft_strjoin(aux, value);
	final = ft_strjoin(aux, &buff[x]);
	return (final);
}

char	*ft_changebuff(char *buff, char *name)
{
	char	*aux;
	int		x;
	char	*value;

	x = ft_isechovar(buff);
	aux = ft_strdup(buff);
	aux[x] = '\0';
	value = ft_returnvalue(name);
	aux = ft_excludevar(buff, aux, value);
	return (aux);
}

char	*ft_putargs(char *buff)
{
	int		x;
	int		pos;
	char	*name;

	x = 0;
	pos = ft_isechovar(buff);
	name = ft_strdup(&buff[++pos]);
	while (ft_isalnum(name[x]) || name[x] == '?')
		x++;
	name[x] = '\0';
	buff = ft_changebuff(buff, name);
	return (buff);
}

char	**ft_avflags(char **av, char *aux, int flags)
{
	av[1] = ft_firstword(aux);
	aux = ft_antispace(&aux[flags]);
	if (ft_strlen(aux))
	{
		av[2] = ft_strdup(aux);
		av[2] = ft_istheredollsign(av[2]);
		av[3] = NULL;
	}
	else
		av[2] = NULL;
	return (av);
}

char	**ft_echo(char *buff, char *path)
{
	char	**av;
	char	*aux;
	int		flags;

	av = malloc(ARG_MAX);
	ft_bzero(av, ARG_MAX);
	av[0] = path;
	aux = ft_strdup(buff);
	aux = ft_antispace(&aux[4]);
	flags = ft_isflag(ft_firstword(aux));
	if (flags)
		av = ft_avflags(av, aux, flags);
	else
	{
		av[1] = aux;
		av[2] = NULL;
	}
	return (av);
}
