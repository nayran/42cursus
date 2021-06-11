#include "ps_c.h"

int	*ft_invertchunk(int *chunk)
{
	int	x;
	int	y;
	int	*aux;

	x = 0;
	y = 0;
	while (chunk[x] != 0)
		x++;
	aux = malloc(sizeof(int) * (x + 1));
	ft_bzero(aux, x + 1);
	while (--x >= 0)
		aux[y++] = chunk[x];
	aux[y] = 0;
	free (chunk);
	return (aux);
}

int	*ft_orderchunk(t_stack *stack, int *chunk)
{
	int	highest;
	int	*final;
	int	y;
	int	x;

	x = 0;
	y = 0;
	final = ft_calloc(sizeof(int), ft_listsize(stack));
	highest = ft_highestinchunk(chunk, ft_listsize(stack));
	while (y < ft_listsize(stack))
	{
		if (chunk[y] == highest && (x == 0 || ft_positionvalue(stack,
					ft_listsize(stack) - 1 - y) + 1 < final[0]))
		{
			final[x] = ft_positionvalue(stack,
					ft_listsize(stack) - 1 - y) + 1;
			highest -= 1;
			x++;
		}
		y++;
	}
	final[x] = 0;
	return (ft_invertchunk(final));
}

int	*ft_invertchunkno(int *chunk, int num)
{
	int	y;
	int	*aux;

	y = 0;
	aux = malloc(sizeof(int) * num);
	ft_bzero(aux, num + 1);
	while (num >= 0)
		aux[y++] = chunk[num--];
	free(chunk);
	return (aux);
}

int	*ft_whilechunk(t_stack *stack, int *chunk, int i, int x)
{
	int		k;
	int		*tmp;
	int		y;
	int		j;

	tmp = ft_calloc(sizeof(int), i);
	k = 0;
	y = 0;
	j = -1;
	while (++j < i)
	{
		y = chunk[i - 1 - j];
		if (ft_positionvalue(stack, i - 1 - j) < x)
		{
			tmp[k] = y + 1;
			k++;
		}
	}
	return (tmp);
}

int	*ft_findchunk(t_stack *stack)
{
	int		i;
	int		*chunk;
	t_stack	*aux;

	i = -1;
	aux = stack;
	chunk = ft_calloc(ft_listsize(stack), sizeof(int));
	while (++i < ft_listsize(stack))
	{
		chunk[i] = ft_highestinchunk(ft_whilechunk(stack, chunk, i, aux->s), i);
		aux = aux->next;
	}
	return (ft_invertchunkno(chunk, i - 1));
}
