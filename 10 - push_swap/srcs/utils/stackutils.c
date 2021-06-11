#include "ps_c.h"

t_stack	*ft_dupstack(t_stack *stack)
{
	t_stack	*dup;
	t_stack	*dupaux;
	t_stack	*aux;

	if (!stack)
		return (NULL);
	dup = malloc(sizeof(t_stack));
	dupaux = dup;
	aux = stack;
	while (aux)
	{
		dup->s = aux->s;
		if (aux->next)
			dup->next = malloc(sizeof(t_stack));
		else
			dup->next = NULL;
		dup = dup->next;
		aux = aux->next;
	}
	dup = NULL;
	return (dupaux);
}

t_stack	**ft_dupstacks(t_stack **stack)
{
	t_stack	**aux;

	aux = malloc(2 * sizeof(t_stack *));
	aux[0] = ft_dupstack(stack[0]);
	aux[1] = ft_dupstack(stack[1]);
	return (aux);
}

t_stack	**ft_stacktofindchunk(t_stack **stack)
{
	int		*list;
	char	**args;
	int		x;

	x = -1;
	args = malloc(4096);
	list = ft_returnorderedlist(stack[0]);
	args = ft_sendtothetopa(stack[0], args, list, 1);
	while (args[++x])
	{
		stack = ft_execargs(stack, args[x]);
		free (args[x]);
	}
	free (args);
	free (list);
	return (stack);
}

void	ft_printstacks(t_stack **stack)
{
	t_stack	**x;

	x = malloc(2 * sizeof(t_stack *));
	if (stack[0])
		x[0] = ft_dupnode(stack[0]);
	else
		x[0] = NULL;
	if (stack[1])
		x[1] = ft_dupnode(stack[1]);
	else
		x[1] = NULL;
	ft_printf("A | ");
	while (x[0])
	{
		ft_printf("%d ", x[0]->s);
		x[0] = x[0]->next;
	}
	write(1, "\n", 1);
	ft_printf("B | ");
	while (x[1])
	{
		ft_printf("%d ", x[1]->s);
		x[1] = x[1]->next;
	}
	write(1, "\n", 1);
}

int	ft_listsize(t_stack *stack)
{
	int		n;
	t_stack	*aux;

	if (!stack)
		return (0);
	n = 1;
	aux = stack;
	while (aux->next)
	{
		n++;
		aux = aux->next;
	}
	return (n);
}
