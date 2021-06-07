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

	if (argc == 1)
		return (0);
	stack = ft_initstack(argc, argv);
	if (!stack[0] || ft_isthereequal(stack[0]))
		return (ft_error());
	if (ft_isallright(stack))
		return (0);
	args = malloc(SHRT_MAX * sizeof(char *));
	args = ft_sort(args, stack);
	ft_printargs(args);
	free (args);
	free (stack);
	return (0);
}
