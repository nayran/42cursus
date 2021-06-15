#include "ps_c.h"

int	ft_atoichecker(char *num, t_stack *stack)
{
	unsigned int	t;
	char			*aux;

	if (ft_strchr(num, '-'))
		aux = ft_strdup(ft_strchr(num, '-') + 1);
	else
		aux = ft_strdup(num);
	t = ft_atoi(aux);
	free (aux);
	if (t > INT_MAX)
	{
		ft_free (stack);
		return (0);
	}
	return (1);
}

char	*ft_argvtoline(char **av, int ac)
{
	int		x;
	char	*aux;
	char	*aux2;
	char	*aux3;

	x = 1;
	aux = ft_strjoin(av[x], " ");
	while (++x < ac)
	{
		aux2 = ft_strjoin(av[x], " ");
		aux3 = ft_strjoin(aux, aux2);
		free (aux);
		aux = ft_strdup(aux3);
		free(aux2);
		free(aux3);
	}
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

t_stack	*ft_initstack(int argc, char **argv)
{
	t_stack	*stack;
	char	*line;

	line = ft_argvtoline(argv, argc);
	if (!ft_fullofdigits(line))
		stack = NULL;
	else
		stack = ft_readstack(line);
	free (line);
	return (stack);
}

t_stack	*ft_readstack(char *stack)
{
	t_stack			*a;
	t_stack			*aux;
	int				x;

	x = -1;
	aux = malloc(sizeof(t_stack));
	a = aux;
	while (a && stack[++x])
	{
		if (!ft_atoichecker(&stack[x], aux))
			return (NULL);
		if (ft_isdigit(stack[x])
			|| (stack[x] == '-' && ft_isdigit(stack[x + 1])))
		{
			a->s = ft_atoi(&stack[x]);
			while (ft_isdigit(stack[x]) || stack[x] == '-')
				x++;
			if (stack[x] != '\0')
				a->next = malloc(sizeof(t_stack));
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
