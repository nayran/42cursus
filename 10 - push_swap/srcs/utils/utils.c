#include "ps_c.h"

int	ft_fullofdigits(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (!ft_isdigit(s[x]) && s[x] != ' ' && s[x] != '-')
			return (0);
		x++;
	}
	return (1);
}

int	ft_highestvalue(t_stack *stack)
{
	int		x;
	t_stack	*aux;

	aux = stack;
	x = aux->s;
	while (aux)
	{
		if (aux->s > x)
			x = aux->s;
		aux = aux->next;
	}
	return (x);
}

int	ft_lowestvalue(t_stack *stack)
{
	int		x;
	t_stack	*aux;

	aux = stack;
	x = aux->s;
	while (aux)
	{
		if (aux->s < x)
			x = aux->s;
		aux = aux->next;
	}
	return (x);
}

int	ft_isallright(t_stack **stack)
{
	t_stack	*aux;

	if (stack[1])
		return (0);
	aux = stack[0];
	while (aux->next)
	{
		if (aux->s > aux->next->s)
			return (0);
		aux = aux->next;
	}
	return (1);
}

int	ft_issemiright(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	while (aux->next)
	{
		if (aux->s > aux->next->s)
			return (0);
		aux = aux->next;
	}
	return (1);
}
