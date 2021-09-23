#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>
#include <list>

template <template <typename, typename> class T>
typename T<int, std::allocator<int> >::const_iterator easyfind(T <int, std::allocator<int> > &lst, int n)
{
	std::list<int>::const_iterator it;
	std::list<int>::const_iterator ite = lst.end();
	for (it = lst.begin(); it != ite; it++)
	{
		if (*it == n)
			return (it);
	}
	throw std::exception();
}

#endif
