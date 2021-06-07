#include "ps_c.h"

int	ft_atoichecker(char *num)
{
	unsigned int	t;

	if (ft_strchr(num, '-'))
	{
		num = ft_strdup(ft_strchr(num, '-'));
		num = &num[1];
	}
	t = ft_atoi(num);
	if (t > INT_MAX)
		return (0);
	return (1);
}

char	*ft_argvtoline(char **av, int ac)
{
	int		x;
	char	*aux;

	x = 1;
	aux = ft_strjoin(av[x], " ");
	while (++x < ac)
		aux = ft_strdup(ft_strjoin(aux, ft_strjoin(av[x], " ")));
	x = ft_strlen(aux);
	while (aux[--x])
	{
		if (aux[x] == ' ')
			aux[x] = '\0';
		else
			break ;
	}
	return (aux);
}

t_stack	**ft_initstack(int argc, char **argv)
{
	t_stack	**stack;
	char	*line;

	stack = malloc(2 * sizeof(t_stack *));
	line = ft_argvtoline(argv, argc);
	if (!ft_fullofdigits(line))
		stack[0] = NULL;
	else
	{
		stack[0] = ft_readstack(line);
		free (line);
	}
	stack[1] = NULL;
	return (stack);
}

t_stack	*ft_readstack(char *stack)
{
	t_stack			*a;
	t_stack			*aux;
	int				x;

	x = -1;
	a = malloc(0);
	aux = a;
	while (stack[++x])
	{
		if (!ft_atoichecker(&stack[x]))
			return (0);
		if (ft_isdigit(stack[x])
			|| (stack[x] == '-' && ft_isdigit(stack[x + 1])))
		{
			a->s = ft_atoi(&stack[x]);
			while (ft_isdigit(stack[x]) || stack[x] == '-')
				x++;
			if (stack[x] != '\0')
				a = ft_mallocnextnode(a);
			else
				a->next = NULL;
			a = a->next;
		}
	}
	return (aux);
}

char	**ft_sendtothetopa(t_stack *stack, char **args, int *chunk, int ls)
{
	int		posfirst;
	int		poslast;
	int		x;
	t_stack	*aux;

	x = -1;
	aux = stack;
	posfirst = ft_firstchunkappearance(chunk, aux, ls);
	poslast = ft_lastchunkappearance(chunk, aux, ls);
	if (posfirst != -1 && posfirst <= ft_listsize(aux) - poslast)
		while (++x < posfirst)
			args = ft_putlastarg(args, "ra");
	else if (poslast != -1)
		while (++x < ft_listsize(aux) - poslast)
			args = ft_putlastarg(args, "rra");
	return (args);
}
