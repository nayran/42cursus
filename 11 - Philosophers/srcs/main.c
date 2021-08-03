#include "philo.h"

int	main(int argc, char **argv)
{
	t_all	all;

	memset(&all, '\0', sizeof(all));
	if (argc < 5 || argc > 6)
		return (1);
	if (!ft_initstruct(&all, argv))
		return (1);
	if (!ft_party(&all))
		return (1);
	ft_free(&all, 0);
	return (0);
}

int	ft_party(t_all *all)
{
	int	x;

	x = -1;
	while (++x < all->numphilo)
	{
		all->tstart = ft_time();
		if (pthread_create(&all->philo[x].thread, NULL,
				ft_actions, &all->philo[x]))
			return (0);
	}
	return (ft_endparty(all));
}

int	ft_endparty(t_all *all)
{
	int	x;

	x = -1;
	while (++x < all->numphilo)
	{
		if (pthread_join(all->philo[x].thread, NULL))
			return (0);
		if (all->philo[x].time == -1)
		{
			ft_printstatus(&all->philo[x], 'd');
			break ;
		}
	}
	return (1);
}
