/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:09:10 by nayran            #+#    #+#             */
/*   Updated: 2021/02/17 13:49:09 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_firstword(char *buff)
{
	char	*aux;
	int		x;

	x = -1;
	aux = ft_strdup(buff);
	aux = ft_antispace(aux);
	while (aux[++x])
		if (ft_isspace(aux[x]))
			break ;
	aux[x] = '\0';
	return (aux);
}

int		ft_issameend(char *str1, char *str2)
{
	int len1;
	int len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (ft_exactstr(&str1[len1 - len2], str2))
		return (1);
	return (0);
}

int		ft_isfile(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	close(fd);
	if (fd == -1)
		return (0);
	return (1);
}

int		ft_isinitargs(char *buff)
{
	if (ft_strnstr(buff, "exit", 4) || ft_strnstr(buff, "cd", 2) ||
			ft_strnstr(buff, "export", 6) || ft_strnstr(buff, "unset", 5) ||
			ft_isvar(buff))
		return (1);
	return (0);
}

void	ft_gvarsinit(void)
{
	g_vars = malloc(sizeof(t_vars));
	g_vars->next = NULL;
}
