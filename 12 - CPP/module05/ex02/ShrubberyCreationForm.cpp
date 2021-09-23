#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string Target) :
	Form("ShrubberyCreationForm", 145, 137), target(Target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf) :
	Form(scf.getName(), scf.getGradeToSign(), scf.getGradeToExec())
{
	*this = scf;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &scf)
{
	ShrubberyCreationForm *tmp = new ShrubberyCreationForm(scf);
	return (*tmp);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return;
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::ofstream	file;
	file.open(ShrubberyCreationForm::target + "_shrubbery", std::ios::out | std::ios::app);
	file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n";
	file.close();
	std::cout << "The tree has been planted!" << std::endl;
}
