#include "ps_c.h"

t_stack	*ft_lastnode(t_stack *stack)
{
	if (!stack)
		return (stack);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_dupvalnode(t_stack *stack)
{
	t_stack	*aux;

	aux = malloc(sizeof(t_stack));
	aux->s = stack->s;
	aux->next = NULL;
	return (aux);
}

t_stack	*ft_dupnode(t_stack *stack)
{
	t_stack	*aux;

	aux = malloc(sizeof(t_stack));
	aux->s = stack->s;
	aux->next = stack->next;
	return (aux);
}

int	ft_positionvalue(t_stack *stack, int pos)
{
	t_stack	*aux;
	int		x;

	x = 0;
	aux = stack;
	while (x < pos)
	{
		aux = aux->next;
		x++;
	}
	return (aux->s);
}

int	ft_isthereequal(t_stack *stack)
{
	t_stack	*count;
	t_stack	*ref;

	count = stack;
	while (count->next)
	{
		ref = count;
		while (ref->next)
		{
			if (count->s == ref->next->s)
				return (1);
			ref = ref->next;
		}
		count = count->next;
	}
	return (0);
}
