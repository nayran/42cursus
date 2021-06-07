/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasimon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:38:14 by nasimon-          #+#    #+#             */
/*   Updated: 2021/04/20 16:25:41 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_limpa(t_list **lst, void (*del)(void*))
{
	t_list	*x;

	while (*lst)
	{
		x = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = x;
	}
	lst = NULL;
}

static t_list	*ft_nova(void *content)
{
	t_list	*x;

	x = (t_list *)malloc(sizeof(t_list));
	if (!x)
		return (NULL);
	x->next = NULL;
	x->content = content;
	return (x);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux_lst;
	t_list	*first_ele;

	if (!lst || !f)
		return (NULL);
	aux_lst = ft_nova(f(lst->content));
	if (!(aux_lst))
		return (NULL);
	first_ele = aux_lst;
	while (lst)
	{
		if (lst->next)
		{
			aux_lst->next = ft_nova(f(lst->next->content));
			if (!(aux_lst->next))
			{
				ft_limpa(&first_ele, del);
				return (0);
			}
			aux_lst = aux_lst->next;
		}
		lst = lst->next;
	}
	aux_lst->next = NULL;
	return (first_ele);
}
