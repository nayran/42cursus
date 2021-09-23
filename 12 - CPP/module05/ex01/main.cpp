#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("b1", 10);
	std::cout << b1 << std::endl;
	Form f1("f1", 2, 2);
	std::cout << f1 << std::endl;
	Form f2("f2", 100, 100);
	std::cout << f2 << std::endl;
	b1.signForm(f2);
	std::cout << f2 << std::endl;
	b1.signForm(f1);
	std::cout << f1 << std::endl;
	try
	{
		Form f2("f2", 160, 1);
	}
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
	}
	try
	{
		Form f2("f2", 1, 0);
	}
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
		return (0);
	}
	std::cout << "Completed!" << std::endl;
	return (0);
}
