#include "utils/ps_c.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**stack;
	t_stack	*aux;
	char	**args;

	if (argc == 1)
		return (0);
	aux = ft_initstack(argc, argv);
	if (!aux || ft_isthereequal(aux))
	{
		ft_free(aux);
		return (ft_error());
	}
	if (ft_issemiright(aux))
	{
		ft_free(aux);
		return (0);
	}
	stack = malloc(2);
	stack[0] = aux;
	stack[1] = NULL;
	args = malloc(SHRT_MAX * sizeof(char *));
	args = ft_sort(args, stack);
	ft_printargs(args);
	free (args);
	return (0);
}
