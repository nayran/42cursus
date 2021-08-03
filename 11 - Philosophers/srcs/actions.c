#include "philo.h"

void	*ft_actions(void *param)
{
	t_philo		*philo;

	philo = param;
	if (!(philo->num % 2))
		ft_usleep(1);
	while (!ft_stop(philo))
	{
		if (!ft_eat(philo))
			break ;
		if (ft_stop(philo) || !ft_sleep(philo))
			break ;
		ft_printstatus(philo, 't');
	}
	return (NULL);
}

int	ft_eat(t_philo *philo)
{
	ft_forks(philo);
	if (ft_stop(philo))
		return (0);
	pthread_mutex_lock(&philo->mutex);
	ft_printstatus(philo, 'e');
	pthread_mutex_unlock(&philo->mutex);
	philo->time = ft_time();
	while (ft_time() - philo->time < philo->all->teat)
	{
		if (ft_stop(philo))
		{
			pthread_mutex_unlock(&philo->mutex);
			ft_unlockforks(philo);
			return (0);
		}
		ft_usleep(1);
	}
	ft_unlockforks(philo);
	philo->ate++;
	return (1);
}

int	ft_sleep(t_philo *philo)
{
	long int	t;

	t = ft_time();
	ft_printstatus(philo, 's');
	while (ft_time() - t < philo->all->tsleep)
	{
		if (ft_stop(philo))
			return (0);
		ft_usleep(1);
	}
	return (1);
}

int	ft_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->forks[philo->rfork]);
	ft_printstatus(philo, 'f');
	pthread_mutex_lock(&philo->all->forks[philo->lfork]);
	ft_printstatus(philo, 'f');
	return (1);
}

int	ft_unlockforks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->all->forks[philo->lfork]);
	pthread_mutex_unlock(&philo->all->forks[philo->rfork]);
	return (0);
}
