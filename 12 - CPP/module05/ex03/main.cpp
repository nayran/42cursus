#include "Intern.hpp"

int main()
{
	try
	{
		Intern  someRandomIntern;
		
		Form*   rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		rrf = someRandomIntern.makeForm("shrubbery creation request", "target");
		std::cout << *rrf << std::endl;
		rrf = someRandomIntern.makeForm("presidential pardon request", "target");
		std::cout << *rrf << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
