#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template< typename T >
void	iter(T *array, int len, void (*func)(T &i))
{
	int x = -1;
	while (++x < len)
		(*func)(array[x]);
}

template< typename T >
void print(T &x)
{
	std::cout << x << " ";
}

#endif
