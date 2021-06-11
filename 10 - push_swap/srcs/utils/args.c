#include "ps_c.h"

t_stack	**ft_execargs(t_stack **stack, char *arg)
{
	if (!ft_strcmp(arg, "sa"))
		stack[0] = ft_swap(stack[0]);
	else if (!ft_strcmp(arg, "sb"))
		stack[1] = ft_swap(stack[1]);
	else if (!ft_strcmp(arg, "ss"))
		stack = ft_ss(stack);
	else if (!ft_strcmp(arg, "pa"))
		stack = ft_pusha(stack);
	else if (!ft_strcmp(arg, "pb"))
		stack = ft_pushb(stack);
	else
		stack = ft_execargs2(stack, arg);
	return (stack);
}

t_stack	**ft_execargs2(t_stack **stack, char *arg)
{
	if (!ft_strcmp(arg, "ra"))
		stack[0] = ft_rotate(stack[0]);
	else if (!ft_strcmp(arg, "rb"))
		stack[1] = ft_rotate(stack[1]);
	else if (!ft_strcmp(arg, "rr"))
		stack = ft_rr(stack);
	else if (!ft_strcmp(arg, "rra"))
		stack[0] = ft_reverse(stack[0]);
	else if (!ft_strcmp(arg, "rrb"))
		stack[1] = ft_reverse(stack[1]);
	else if (!ft_strcmp(arg, "rrr"))
		stack = ft_rrr(stack);
	else
	{
		ft_freeall(stack);
		return (NULL);
	}
	return (stack);
}

char	**ft_divideargs(char **args, char *aux)
{
	int		x;

	x = -1;
	while (aux[++x])
	{
		if (x != 0 && (aux[x] == '\n' || aux[x] == 10))
		{
			aux[x] = '\0';
			args = ft_putlastarg(args, aux);
			aux = ft_strdup(&aux[x + 1]);
			x = -1;
		}
	}
	args = ft_putlastarg(args, NULL);
	return (args);
}

char	**ft_readargs(void)
{
	char	**args;
	char	*aux;
	int		x;

	x = 0;
	aux = 0;
	args = malloc(10000 * sizeof(char *));
	while (get_next_line(STDIN_FILENO, &aux))
	{
		args[x] = ft_strdup(aux);
		free(aux);
		x++;
	}
	free(aux);
	args[x] = NULL;
	return (args);
}

void	ft_printargs(char **args)
{
	int	x;

	x = -1;
	while (args[++x])
	{
		write(1, args[x], ft_strlen(args[x]));
		write(1, "\n", 1);
		free (args[x]);
	}
}
