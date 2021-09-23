#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string Target) :
	Form("RobotomyRequestForm", 72, 45), target(Target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf) :
	Form(rrf.getName(), rrf.getGradeToSign(), rrf.getGradeToExec())
{
	*this = rrf;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &rrf)
{
	RobotomyRequestForm *tmp = new RobotomyRequestForm(rrf);
	return (*tmp);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return;
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int num;
	Form::execute(executor);
	std::cout << "* Drilling noises * ";
	num = rand() % 100;
	if (num < 49)
		std::cout << RobotomyRequestForm::target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << RobotomyRequestForm::target << " failed to robotomize!" << std::endl;
}
