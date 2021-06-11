#include "ps_c.h"

int	*ft_copychunk(int *chunk, int ls)
{
	int	x;
	int	y;
	int	*aux;

	aux = malloc(sizeof(int) * ls);
	x = 0;
	while (x < ls)
	{
		y = chunk[x];
		aux[x] = y;
		x++;
	}
	return (aux);
}

int	*ft_bestposition(t_stack **stack)
{
	int	y;
	int	*aux;
	int	*pos;

	y = -1;
	pos = ft_initposvar(stack);
	while (++y < ft_listsize(stack[1]))
	{
		if (ft_numofop(y, 0) >= ft_numofop(pos[0], pos[1]))
			break ;
		aux = ft_initauxvar(stack, y);
		if (ft_numofop(aux[0], aux[1]) < ft_numofop(pos[0], pos[1]))
		{
			free (pos);
			pos = ft_copychunk(aux, 2);
		}
		aux = ft_whichaux(aux, stack, y);
		if (ft_numofop(aux[0], aux[1]) < ft_numofop(pos[0], pos[1]))
		{
			free (pos);
			pos = ft_copychunk(aux, 2);
		}
		free (aux);
	}
	return (pos);
}

char	**ft_sortthree(char **args, t_stack **stack)
{
	int	max;
	int	min;

	max = ft_highestvalue(stack[0]);
	min = ft_lowestvalue(stack[0]);
	if (ft_listsize(stack[0]) == 2
		|| (stack[0]->s == max && stack[0]->next->s != min)
		|| (stack[0]->next->next->s == max && stack[0]->s != min)
		|| (stack[0]->next->s == max && stack[0]->next->next->s != min))
		args = ft_putlastarg(args, "sa");
	return (args);
}

char	**ft_sortmore(char **args, t_stack **stack)
{
	t_stack	**aux;
	int		*chunk;
	int		y;

	y = 0;
	aux = ft_stacktofindchunk(ft_dupstacks(stack));
	chunk = ft_orderchunk(aux[0], ft_findchunk(aux[0]));
	ft_freeall(aux);
	aux = ft_dupstacks(stack);
	while (ft_listsize(aux[0]) > ft_chunksize(chunk))
	{
		if (!ft_isinchunk(chunk, aux[0]->s))
			args = ft_putlastarg(args, "pb");
		else
			args = ft_putlastarg(args, "ra");
		while (args[y])
			aux = ft_execargs(aux, args[y++]);
	}
	args = ft_sendbacktoa(args, aux, y);
	free (chunk);
	ft_freeall(aux);
	return (args);
}

char	**ft_sort(char **args, t_stack **stack)
{
	int		y;
	int		x;

	y = 0;
	if (ft_listsize(stack[0]) <= 3)
		args = ft_sortthree(args, stack);
	else
		args = ft_sortmore(args, stack);
	while (args[y])
		stack = ft_execargs(stack, args[y++]);
	x = ft_lowestvalue(stack[0]);
	args = ft_sendtothetopa(stack[0], args, &x, 1);
	ft_free(stack[0]);
	ft_free(stack[1]);
	free (stack);
	return (args);
}
