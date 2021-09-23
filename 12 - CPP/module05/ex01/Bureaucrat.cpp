#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
	*this = b;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat &b)
{
	Bureaucrat *tmp = new Bureaucrat();
	tmp->grade = b.grade;
	return (*tmp);
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
}

Bureaucrat::Bureaucrat(std::string Name, int grade) : name(Name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

void		Bureaucrat::incrementGrade()
{
	grade--;
	if (grade < 1)
		throw GradeTooHighException();
}

void		Bureaucrat::decrementGrade()
{
	grade++;
	if (grade > 150)
		throw GradeTooLowException();
}

const std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::signForm(Form &f)
{
	if (f.getisSign())
		std::cout << Bureaucrat::name << " cannot sign " << f.getName() << " because it's already signed!" << std::endl;
	else if (f.getGradeToSign() < Bureaucrat::getGrade())
		std::cout << Bureaucrat::name << " cannot sign " << f.getName() << " because bureaucrat's grade is lower than requested!" << std::endl;
	else
	{
		std::cout << Bureaucrat::name << " signs " << f.getName() << std::endl;
		f.beSigned(*this);
	}
}

std::ostream &operator << (std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
