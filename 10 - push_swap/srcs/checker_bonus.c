#include "utils/ps_c.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**stack;
	char	**args;
	int		x;

	if (argc == 1)
		return (0);
	stack = ft_initstack(argc, argv);
	if (!stack[0] || ft_isthereequal(stack[0]))
		return (ft_error());
	args = ft_readargs();
	x = -1;
	while (args[++x])
		stack = ft_execargs(stack, args[x]);
	if (!stack)
		return (ft_error());
	if (ft_isallright(stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
