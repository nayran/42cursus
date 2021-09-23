#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1("bureaucrat1", 1);
		std::cout << b1 << std::endl;
		Form *tree = new ShrubberyCreationForm("tree");
		std::cout << *tree << std::endl;
		Form *thief= new PresidentialPardonForm("thief");
		std::cout << *thief << std::endl;
		Form *robot = new RobotomyRequestForm("robot");
		std::cout << *robot << std::endl;
		
		tree->beSigned(b1);
		tree->execute(b1);

		thief->beSigned(b1);
		thief->execute(b1);

		robot->beSigned(b1);
		robot->execute(b1);
		b1.executeForm(*robot);
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
