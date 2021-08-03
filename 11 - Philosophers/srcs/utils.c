#include "philo.h"
#include <sys/time.h>

long int	ft_time(void)
{
	long int		milliseconds;
	struct timeval	time;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (milliseconds);
}

void	ft_usleep(int t)
{
	usleep(t * 1000);
}

int	ft_free(t_all *all, int x)
{
	int	y;

	free(all->forks);
	free(all->philo);
	pthread_mutex_destroy(&all->print);
	y = -1;
	while (++y < all->numphilo)
	{
		if (x > 0)
			pthread_mutex_destroy(&all->forks[y]);
		if (x > 1)
			pthread_mutex_destroy(&all->philo[y].mutex);
	}
	return (0);
}

void	ft_printstatus(t_philo *philo, char c)
{
	pthread_mutex_lock(&philo->all->print);
	printf("%ld %d ", ft_time() - philo->all->tstart, philo->num);
	if (c == 'f')
		printf("has taken a fork\n");
	else if (c == 'e')
		printf("is eating\n");
	else if (c == 's')
		printf("is sleeping\n");
	else if (c == 't')
		printf("is thinking\n");
	else if (c == 'd')
		printf("died\n");
	pthread_mutex_unlock(&philo->all->print);
}

int	ft_isallnum(char **argv)
{
	int	x;
	int	y;

	x = 0;
	while (argv[++x])
	{
		y = -1;
		while (argv[x][++y])
			if (!ft_isdigit(argv[x][y]) && argv[x][y] != '-'
				&& argv[x][y] != ' ')
				return (0);
	}
	return (1);
}
