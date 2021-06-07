/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 08:13:59 by nayran            #+#    #+#             */
/*   Updated: 2021/02/18 01:10:43 by nayran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	aux(void)
{
	char	*a;
	char	*b;
	int		fd;

	b = malloc(9);
	ft_write(1, "\nWRITE\n", 7);
	ft_write(1, "write", 6);
	ft_write(1, " = ", 3);
	write(1, "write", 6);
	ft_write(1, "\n", 1);
	write(1, "\nREAD\n", 6);
	fd = open("tests", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	read(fd, "tests", 1);
	ft_read(fd, "tests", 1);
	close(fd);
	printf("\nFT_STRDUP\n");
	a = ft_strdup("ft_strdup");
	b = ft_strdup(a);
	printf("before: %s = %s\n", a, b);
	a[2] = '-';
	printf("after: %s = %s\n", a, b);
}

int		main(void)
{
	char	*a;

	a = malloc(1);
	printf("FT_STRLEN\n");
	printf("%d = %lu\n", ft_strlen("ft_strlen"), strlen("ft_strlen"));
	printf("\nFT_STRCPY\n");
	printf("%s = %s\n", ft_strcpy(a, "ft_strcpy"), strcpy(a, "ft_strcpy"));
	printf("\nFT_STRCMP\n");
	printf("equal: %d = %d\n", ft_strcmp("equal", "equal"),
			strcmp("equal", "equal"));
	printf("lower: %d = %d\n", ft_strcmp("low", "lower"),
			strcmp("low", "lower"));
	printf("higher: %d = %d\n", ft_strcmp("higher", "high"),
			strcmp("higher", "high"));
	aux();
	return (0);
}
