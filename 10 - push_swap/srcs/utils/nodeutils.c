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

	first = stack;
	last = ft_lastnode(stack);
	if (node)
		last->next = node;
	return (first);
}

t_stack	*ft_penultnode(t_stack *stack)
{
	if (!stack)
		return (stack);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_dellastnode(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	stack = ft_penultnode(stack);
	stack->next = NULL;
	return (aux);
}

t_stack	*ft_mallocnextnode(t_stack *stack)
{
	stack->next = malloc(0);
	stack->next->prev = stack;
	return (stack);
}
