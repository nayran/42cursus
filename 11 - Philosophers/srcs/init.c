#include "philo.h"

int	ft_initstruct(t_all *all, char **argv)
{
	if (!ft_isallnum(argv))
		return (0);
	all->numphilo = ft_atoi(argv[1]);
	all->tdie = ft_atoi(argv[2]);
	all->teat = ft_atoi(argv[3]);
	all->tsleep = ft_atoi(argv[4]);
	if (all->numphilo < 1 || all->tdie < 1 || all->teat < 1 || all->tsleep < 1)
		return (0);
	if (argv[5])
		all->musteat = ft_atoi(argv[5]);
	pthread_mutex_init(&all->print, NULL);
	all->philo = ft_calloc(all->numphilo, sizeof(t_philo));
	all->forks = malloc(sizeof(pthread_mutex_t) * all->numphilo);
	if (all->numphilo < 1 || all->teat == 0)
		return (ft_free(all, 0));
	if (argv[5] && all->musteat < 1)
		return (ft_free(all, 0));
	return (ft_initphilos(all));
}

int	ft_initphilos(t_all *all)
{
	int	x;

	x = -1;
	while (++x < all->numphilo)
	{
		all->philo[x].num = x + 1;
		all->philo[x].time = ft_time();
		all->philo[x].all = all;
		all->philo[x].lfork = x;
		all->philo[x].rfork = x + 1;
		if (x + 1 == all->numphilo)
			all->philo[x].rfork = 0;
		if (pthread_mutex_init(&all->forks[x], NULL))
			return (ft_free(all, 1));
		if (pthread_mutex_init(&all->philo[x].mutex, NULL))
			return (ft_free(all, 2));
	}
	return (1);
}

int	ft_stop(t_philo *philo)
{
	if (philo->all->numphilo == 1)
	{
		pthread_mutex_lock(&philo->all->forks[0]);
		ft_printstatus(philo, 'f');
		ft_usleep(philo->all->tdie);
		pthread_mutex_unlock(&philo->all->forks[0]);
		ft_printstatus(philo, 'd');
		return (1);
	}
	return (ft_stop2(philo));
}

int	ft_stop2(t_philo *philo)
{
	int	x;
	int	count;

	x = -1;
	count = 0;
	while (++x < philo->all->numphilo)
	{
		pthread_mutex_lock(&philo->all->philo[x].mutex);
		if (ft_time() - philo->all->philo[x].time >= philo->all->tdie)
		{
			pthread_mutex_unlock(&philo->all->philo[x].mutex);
			philo->all->philo[x].time = -1;
			return (1);
		}
		pthread_mutex_unlock(&philo->all->philo[x].mutex);
		if (philo->all->musteat && philo->ate >= philo->all->musteat)
			count++;
		if (count == philo->all->numphilo)
			return (1);
	}
	return (0);
}
