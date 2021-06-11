#include "ps_c.h"

void	ft_free(t_stack *stack)
{
	t_stack	*aux;

	while (stack)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
	free (stack);
}

void	ft_freeargs(char **args)
{
	int	x;

	x = -1;
	while (args[++x])
		free (args[x]);
	free (args);
}

void	ft_freeall(t_stack **stack)
{
	ft_free(stack[0]);
	ft_free(stack[1]);
	free (stack);
}
