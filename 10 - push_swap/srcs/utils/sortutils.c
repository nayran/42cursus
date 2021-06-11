#include "ps_c.h"

int	*ft_initposvar(t_stack **stack)
{
	int	*pos;

	pos = malloc(2 * sizeof(int));
	pos[0] = -ft_listsize(stack[0]);
	pos[1] = ft_listsize(stack[1]);
	return (pos);
}

int	*ft_initauxvar(t_stack **stack, int y)
{
	int	*aux;

	aux = malloc(2);
	aux[0] = ft_positionina(stack[0], ft_positionvalue(stack[1], y));
	aux[1] = y;
	return (aux);
}

int	ft_numofop(int a, int b)
{
	int	x;

	x = a * b;
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (x > 0)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else
		return (a + b);
}

int	ft_returnvalueposition(t_stack *stack, int num)
{
	t_stack	*aux;
	int		x;

	x = 0;
	aux = stack;
	while (aux)
	{
		if (aux->s == num)
			break ;
		aux = aux->next;
		x++;
	}
	return (x);
}

int	*ft_whichaux(int *aux, t_stack **stack, int y)
{
	if (y == 0)
		aux[0] = ft_positionina(stack[0], ft_positionvalue(stack[1], 0));
	else
		aux[0] = ft_positionina(stack[0], ft_positionvalue(stack[1],
					ft_listsize(stack[1]) - y));
	aux[1] = -y;
	return (aux);
}
