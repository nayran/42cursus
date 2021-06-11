#include "ps_c.h"

t_stack	*ft_addfirst(t_stack *stack, t_stack *node)
{
	if (stack)
		node->next = stack;
	return (node);
}

t_stack	*ft_addlast(t_stack *stack, t_stack *node)
{
	t_stack	*last;
	t_stack	*first;

	if (!node)
	{
		free(node);
		return (stack);
	}
	first = stack;
	last = ft_lastnode(stack);
	last->next = node;
	last->next->next = NULL;
	return (first);
}

t_stack	*ft_penultnode(t_stack *stack)
{
	t_stack	*aux;

	if (!stack)
		return (stack);
	aux = stack;
	while (stack->next)
	{
		aux = stack;
		stack = stack->next;
	}
	return (aux);
}

t_stack	*ft_dellastnode(t_stack *stack)
{
	t_stack	*aux;
	t_stack	*last;

	aux = stack;
	last = ft_lastnode(stack);
	free (last);
	stack = ft_penultnode(stack);
	stack->next = NULL;
	return (aux);
}

int	*ft_returnorderedlist(t_stack *stack)
{
	int		x;
	int		y;
	int		*ints;
	t_stack	*aux;

	x = 0;
	ints = malloc(sizeof(int) * (ft_listsize(stack) - 1));
	while (x < ft_listsize(stack))
	{
		aux = stack;
		y = 0;
		ints[x] = INT_MAX;
		while (y < ft_listsize(stack))
		{
			if (aux->s < ints[x] && x == 0)
				ints[x] = aux->s;
			else if (x > 0 && aux->s < ints[x] && aux->s > ints[x - 1])
				ints[x] = aux->s;
			y++;
			aux = aux->next;
		}
		x++;
	}
	return (ints);
}
