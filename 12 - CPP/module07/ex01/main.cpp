#include "iter.hpp"


int main( void )
{
	int ints[] = {-2, -1, 0, 1, 2};
	std::string chars[] = {"aaa", "bbb", "ccc", "ddd", "eee"};

    ::iter(ints, 5, print);
	std::cout << std::endl;
    ::iter(chars, 5, print);
	std::cout << std::endl;
	return 0;
}
