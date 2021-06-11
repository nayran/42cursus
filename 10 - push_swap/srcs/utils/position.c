#include "ps_c.h"

char	ft_ifzero(t_stack *stack, int x, int y)
{
	if (x < ft_positionvalue(stack, y)
		&& x > ft_positionvalue(stack, ft_listsize(stack) - 1))
		return ('a');
	if (x > ft_positionvalue(stack, 0)
		&& x < ft_positionvalue(stack, 1))
		return ('b');
	return ('\0');
}

char	ft_ifone(t_stack *stack, int x, int y)
{
	if (x < ft_positionvalue(stack, y)
		&& x > ft_positionvalue(stack, y - 1))
		return ('a');
	if (x > ft_positionvalue(stack, ft_listsize(stack) - y)
		&& x < ft_positionvalue(stack, 0))
		return ('b');
	return ('\0');
}

char	ft_ifmore(t_stack *stack, int x, int y)
{
	if (x < ft_positionvalue(stack, y)
		&& x > ft_positionvalue(stack, y - 1))
		return ('a');
	if (x > ft_positionvalue(stack, ft_listsize(stack) - y)
		&& x < ft_positionvalue(stack, ft_listsize(stack) - y + 1))
		return ('b');
	return ('\0');
}

int	ft_highestina(t_stack *stack)
{
	int		highest;

	highest = ft_highestvalue(stack);
	highest = ft_returnvalueposition(stack, highest) + 1;
	if (highest == ft_listsize(stack))
		return (0);
	if (highest > ft_listsize(stack) - highest)
		highest = -(ft_listsize(stack) - highest);
	return (highest);
}

int	ft_positionina(t_stack *stack, int x)
{
	int		y;
	char	c;

	y = 0;
	c = '\0';
	while (y < ft_listsize(stack))
	{
		if (y == 0)
			c = ft_ifzero(stack, x, y);
		else if (y == 1)
			c = ft_ifone(stack, x, y);
		else
			c = ft_ifmore(stack, x, y);
		if (c == 'a')
			return (y);
		else if (c == 'b')
			return (-y + 1);
		y++;
	}
	return (ft_highestina(stack));
}
