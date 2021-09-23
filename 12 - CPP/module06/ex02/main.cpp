#include "Identifier.hpp"

int main()
{
	Base *p[10];
	Base *r[10];

	std::cout << "Pointer" << std::endl;
	for (int x = 0; x < 10; x++)
	{
		p[x] = generate();
		identify(p[x]);
		std::cout << " ";
		delete p[x];
	}
	std::cout << std::endl << "Reference" << std::endl;
	for (int x = 0; x < 10; x++)
	{
		r[x] = generate();
		identify(*r[x]);
		std::cout << " ";
		delete r[x];
	}
	std::cout << std::endl;
	return (0);
}
