/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:34:27 by nasimon-          #+#    #+#             */
/*   Updated: 2020/01/28 14:14:47 by nasimon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_ultima(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void			ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	aux = ft_ultima(*lst);
	if (aux)
		aux->next = new;
	else
		*lst = new;
}
