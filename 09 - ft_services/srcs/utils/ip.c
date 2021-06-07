#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>

int	*ft_handler(char *ip);
int	*ft_incrementer(int	*ip);
char	*itoa(int n);

int	main(int arc, char **argv)
{
	int	*divided;
	FILE *fd;
	int x;

	x = 0;
	fd = fopen("ips.txt", "a");
	divided = ft_handler(argv[1]);
	while (x < 10)
	{
		fprintf(fd, "%d.%d.%d.%d\n", divided[0], divided[1], divided[2], divided[3]);
		divided = ft_incrementer(divided);
		x++;
	}
	fclose(fd);
	return (0);
}

int	*ft_handler(char *ip)
{
	int	x;
	int	y;
	int count;
	int	*divided;

	x = -1;
	y = 0;
	count = 0;
	divided = malloc(4 * sizeof(char *));
	while (ip[++x])
	{
		if(ip[x] == '.')
		{
			divided[count] = atoi(strndup(&ip[y], x-y));
			y = x+1;
			count++;
		}
		if(ip[x+1] == '\0')
			divided[count] = atoi(strndup(&ip[y], x-y+1));
	}
	return (divided);
}

int	*ft_incrementer(int	*ip)
{
	ip[3]++;
	if (ip[3] == 255)
	{
		ip[3] = 1;
		ip[2]++;
		if (ip[2] == 254)
			ip[2] = 1;
	}
	return (ip);
}

static int	ft_count(unsigned int aux)
{
	int	x;

	x = 0;
	while (aux > 9)
	{
		aux = aux / 10;
		x++;
	}
	return (x);
}

char	*itoa(int n)
{
	char			*final;
	int				x;
	unsigned int	aux;
	int				k;

	k = 0;
	aux = n;
	if (n < 0)
		k = 1;
	if (n < 0)
		aux = 0 - n;
	x = ft_count(aux) + 1 + k;
	final = (char *)malloc(x + 1);
	if (!final)
		return (0);
	final[x--] = '\0';
	while (aux > 9)
	{
		final[x--] = aux % 10 + '0';
		aux = aux / 10;
	}
	final[x] = aux + '0';
	if (k)
		final[--x] = '-';
	return (final);
}
