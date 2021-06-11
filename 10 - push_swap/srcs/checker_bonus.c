#include "utils/ps_c.h"

int	ft_error(t_stack *stack)
{
	write(1, "Error\n", 6);
	ft_free(stack);
	return (0);
}

void	ft_printresult(t_stack **stack)
{
	if (ft_isallright(stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	**stack;
	t_stack	*aux;
	char	**args;
	int		x;

	if (argc == 1)
		return (0);
	aux = ft_initstack(argc, argv);
	if (!aux || ft_isthereequal(aux))
		return (ft_error(aux));
	args = ft_readargs();
	x = -1;
	stack = malloc(2);
	stack[0] = aux;
	stack[1] = NULL;
	while (stack && args[++x])
		stack = ft_execargs(stack, args[x]);
	ft_freeargs(args);
	if (!stack)
		return (ft_error(aux));
	ft_printresult(stack);
	ft_freeall(stack);
	return (0);
}
