#include "Identifier.hpp"

Base::~Base()
{
	return ;
}

Base * generate(void)
{
	int x;

	x = rand() % 3;
	if (x == 0)
		return (new A);
	if (x == 1)
		return (new B);
	if (x == 2)
		return (new C);
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	if (dynamic_cast<B*>(p))
		std::cout << "B";
	if (dynamic_cast<C*>(p))
		std::cout << "C";
}

void identify(Base& p)
{
	try
	{
		if (dynamic_cast<A*>(&p))
			std::cout << "A";
		else if (dynamic_cast<B*>(&p))
			std::cout << "B";
		else if (dynamic_cast<C*>(&p))
			std::cout << "C";
		else
			throw CastException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
