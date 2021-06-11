#include "ps_c.h"

int	ft_positionsdistance(int *pos)
{
	int	aux;

	if (pos[0] > 0 && pos[0] < pos[1])
		aux = pos[0];
	else if (pos[0] > 0 && pos[0] > pos[1])
		aux = pos[1];
	else if (pos[0] < 0 && pos[0] > pos[1])
		aux = pos[0];
	else
		aux = pos[1];
	return (aux);
}

char	**ft_finalinsertion(char **args, int *pos)
{
	int	aux;
	int	x;

	if (pos[0] * pos[1] > 0)
	{
		aux = ft_positionsdistance(pos);
		x = aux;
		if (x < 0)
			x = -x;
		while (x-- > 0)
		{
			if (pos[0] > 0)
				args = ft_putlastarg(args, "rr");
			else
				args = ft_putlastarg(args, "rrr");
		}
		pos[0] -= aux;
		pos[1] -= aux;
	}
	return (ft_finalinsertion2(args, pos));
}

char	**ft_finalinsertion2(char **args, int *pos)
{
	char	*arg;

	if (pos[0] < 0)
	{
		arg = ft_strdup("rra");
		pos[0] = -pos[0];
	}
	else
		arg = ft_strdup("ra");
	while (pos[0]-- != 0)
		args = ft_putlastarg(args, arg);
	free(arg);
	if (pos[1] < 0)
	{
		arg = ft_strdup("rrb");
		pos[1] = -pos[1];
	}
	else
		arg = ft_strdup("rb");
	while (pos[1]-- != 0)
		args = ft_putlastarg(args, arg);
	free (arg);
	free (pos);
	return (ft_putlastarg(args, "pa"));
}

char	**ft_sendbacktoa(char **args, t_stack **aux, int y)
{
	while (ft_listsize(aux[1]) > 0)
	{
		args = ft_finalinsertion(args, ft_bestposition(aux));
		while (args[y])
			aux = ft_execargs(aux, args[y++]);
	}
	return (args);
}

char	**ft_putlastarg(char **args, char *command)
{
	int	x;

	x = 0;
	while (args[x])
		x++;
	args[x] = ft_strdup(command);
	return (args);
}
