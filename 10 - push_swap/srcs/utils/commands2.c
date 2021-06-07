#include "ps_c.h"

t_stack	*ft_rotate(t_stack *stack)
{
	t_stack	*first;

	if (!stack)
		return (stack);
	first = ft_dupvalnode(stack);
	stack = stack->next;
	first = ft_addlast(stack, first);
	return (first);
}

t_stack	**ft_rr(t_stack **stack)
{
	stack[0] = ft_rotate(stack[0]);
	stack[1] = ft_rotate(stack[1]);
	return (stack);
}

t_stack	*ft_swap(t_stack *stack)
{
	int	aux;
	int	n;

	n = ft_listsize(stack);
	if (n < 2)
		return (stack);
	aux = stack->s;
	stack->s = stack->next->s;
	stack->next->s = aux;
	return (stack);
}

t_stack	**ft_ss(t_stack **stack)
{
	stack[0] = ft_swap(stack[0]);
	stack[1] = ft_swap(stack[1]);
	return (stack);
}
