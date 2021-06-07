#include "ps_c.h"

t_stack	**ft_aorb(t_stack *src, t_stack *dest, char c)
{
	t_stack	**aux;

	aux = malloc(0);
	if (c == 'a')
	{
		aux[0] = dest;
		aux[1] = src;
		return (aux);
	}
	else
	{
		aux[0] = src;
		aux[1] = dest;
		return (aux);
	}
}

t_stack	**ft_push(t_stack *dest, t_stack *src, char c)
{
	t_stack	*stack;
	t_stack	**aux;

	if (!src)
		return (ft_aorb(src, dest, c));
	stack = ft_addfirst(dest, ft_dupvalnode(src));
	aux = ft_aorb(src->next, stack, c);
	return (aux);
}

t_stack	*ft_reverse(t_stack *stack)
{
	t_stack	*node;

	if (!stack)
		return (stack);
	node = ft_dupvalnode(ft_lastnode(stack));
	node = ft_addfirst(stack, node);
	node = ft_dellastnode(node);
	return (node);
}

t_stack	**ft_rrr(t_stack **stack)
{
	stack[0] = ft_reverse(stack[0]);
	stack[1] = ft_reverse(stack[1]);
	return (stack);
}
