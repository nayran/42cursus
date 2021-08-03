#include "philo.h"

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	nb;
	int						signal;

	i = 0;
	nb = 0;
	signal = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	if (nb > 2147483647 && signal == 1)
		return (-1);
	else if (nb > 2147483648 && signal == -1)
		return (0);
	return ((int)(signal * nb));
}

void	*ft_calloc(size_t num_elements, size_t size)
{
	void	*ptr;

	ptr = malloc(num_elements * size);
	if (ptr)
		ft_bzero(ptr, num_elements * size);
	return (ptr);
}

void	ft_bzero(void *str, size_t x)
{
	char	*aux;

	aux = str;
	while (x > 0)
	{
		*aux = 0;
		aux++;
		x--;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}
