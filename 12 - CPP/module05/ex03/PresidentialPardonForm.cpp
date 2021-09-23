#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string Target) :
	Form("PresidentialPardonForm", 25, 5), target(Target)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf) :
	Form(ppf.getName(), ppf.getGradeToSign(), ppf.getGradeToExec())
{
	*this = ppf;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &rrf)
{
	PresidentialPardonForm *tmp = new PresidentialPardonForm(rrf);
	return (*tmp);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return;
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << PresidentialPardonForm::target << " has been pardoned by Zafod Beeblebrox!" << std::endl;
}
