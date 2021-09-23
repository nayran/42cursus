#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("b1", 10);
	std::cout << b1 << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl << std::endl;
	try
	{
		Bureaucrat b2("b2", 151);
		std::cout << b2 << std::endl;
		//Bureaucrat b2("b2", 0);
		//std::cout << b2 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b3("b3", 150);
		std::cout << b3 << std::endl;
		b3.decrementGrade();
		std::cout << b3 << std::endl;
		//Bureaucrat b3("b3", 1);
		//std::cout << b3 << std::endl;
		//b3.incrementGrade();
		//std::cout << b3 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	std::cout << "Completed!" << std::endl;
	return (0);
}
