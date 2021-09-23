#include "easyfind.hpp"

void	print(int x)
{
	std::cout << x << " ";
}

int main( void )
{
	int myints[] = {16,2,77,29};
	std::list<int> lst (myints, myints + sizeof(myints) / sizeof(int) );
	try
	{
		std::cout << "List: " << for_each(lst.begin(), lst.end(), print) << std::endl;
		std::cout << "Searching 2: " << *easyfind(lst, 2) << std::endl;
		std::cout << "Searching 13: " << *easyfind(lst, 13) << std::endl;
	}
    catch(std::exception &e)
	{
		std::cout << "Number not found!" << std::endl;
	}
	return (0);
}
