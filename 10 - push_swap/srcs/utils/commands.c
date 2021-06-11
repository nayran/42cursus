#include "ps_c.h"

t_stack	**ft_pusha(t_stack **stack)
{
	t_stack	*aux;

	if (!stack[1])
		return (stack);
	aux = stack[1]->next;
	stack[0] = ft_push(stack[0], stack[1]);
	stack[1] = aux;
	return (stack);
}

t_stack	**ft_pushb(t_stack **stack)
{
	t_stack	*aux;

	if (!stack[0])
		return (stack);
	aux = stack[0]->next;
	stack[1] = ft_push(stack[1], stack[0]);
	stack[0] = aux;
	return (stack);
}

t_stack	*ft_push(t_stack *dest, t_stack *src)
{
	t_stack	*stack;

	if (!src)
		return (dest);
	stack = src;
	stack->next = dest;
	return (stack);
}

t_stack	*ft_reverse(t_stack *stack)
{
	t_stack	*node;
	t_stack	*first;
	t_stack	*penult;

	if (!stack)
		return (stack);
	penult = ft_penultnode(stack);
	first = stack;
	node = ft_lastnode(stack);
	node->next = first;
	penult->next = NULL;
	return (node);
}

t_stack	**ft_rrr(t_stack **stack)
{
	stack[0] = ft_reverse(stack[0]);
	stack[1] = ft_reverse(stack[1]);
	return (stack);
}
