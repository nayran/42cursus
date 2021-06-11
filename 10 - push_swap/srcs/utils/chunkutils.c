#include "ps_c.h"

int	ft_chunksize(int *chunk)
{
	int	i;

	i = 0;
	while (chunk[i] != 0)
		i++;
	return (i);
}

int	ft_isinchunk(int *chunk, int num)
{
	int	i;

	i = -1;
	while (chunk[++i] != 0)
		if (chunk[i] - 1 == num)
			return (1);
	return (0);
}

int	ft_highestinchunk(int *chunk, int ls)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	if (!chunk)
		return (0);
	while (x < ls)
	{
		if (chunk[x] > y)
			y = chunk[x];
		x++;
	}
	free (chunk);
	return (y);
}

int	ft_lastchunkappearance(int *chunk, t_stack *stack, int listsize)
{
	int		num;
	int		x;
	int		y;
	t_stack	*aux;

	x = 0;
	num = -1;
	aux = stack;
	while (aux)
	{
		y = -1;
		while (++y < listsize)
		{
			if (aux->s == chunk[y])
			{
				num = x;
				break ;
			}
		}
		x++;
		aux = aux->next;
	}
	return (num);
}

int	ft_firstchunkappearance(int *chunk, t_stack *stack, int listsize)
{
	int		x;
	int		y;
	t_stack	*aux;

	x = 0;
	aux = stack;
	while (aux)
	{
		y = -1;
		while (++y < listsize)
			if (aux->s == chunk[y])
				return (x);
		x++;
		aux = aux->next;
	}
	return (-1);
}
