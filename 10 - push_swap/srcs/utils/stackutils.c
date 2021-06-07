#include "ps_c.h"

t_stack	*ft_dupstack(t_stack *stack)
{
	t_stack	*dup;
	t_stack	*dupaux;
	t_stack	*aux;

	if (!stack)
		return (NULL);
	dup = malloc(0);
	dupaux = dup;
	aux = stack;
	while (aux)
	{
		dup->s = aux->s;
		if (aux->next)
			dup->next = malloc(0);
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

	aux = malloc(0);
	aux[0] = ft_dupstack(stack[0]);
	aux[1] = ft_dupstack(stack[1]);
	return (aux);
}

t_stack	**ft_stacktofindchunk(t_stack **stack)
{
	t_stack	**aux;
	int		*list;
	char	**args;
	int		x;

	x = -1;
	args = malloc(4096);
	aux = ft_dupstacks(stack);
	list = ft_returnorderedlist(aux[0]);
	args = ft_sendtothetopa(aux[0], args, list, 1);
	while (args[++x])
		aux = ft_execargs(aux, args[x]);
	free (args);
	free (list);
	return (aux);
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

int	*ft_returnorderedlist(t_stack *stack)
{
	int		x;
	int		y;
	int		*ints;
	t_stack	*aux;

	x = 0;
	ints = malloc(sizeof(int) * (ft_listsize(stack) - 1));
	while (x < ft_listsize(stack))
	{
		aux = stack;
		y = 0;
		ints[x] = INT_MAX;
		while (y < ft_listsize(stack))
		{
			if (aux->s < ints[x] && x == 0)
				ints[x] = aux->s;
			else if (x > 0 && aux->s < ints[x] && aux->s > ints[x - 1])
				ints[x] = aux->s;
			y++;
			aux = aux->next;
		}
		x++;
	}
	return (ints);
}
