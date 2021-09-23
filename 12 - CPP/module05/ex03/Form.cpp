#include "Form.hpp"

Form::Form(const std::string Name, int gradesign, int gradeexec) : name(Name), signGrade(gradesign), execGrade(gradeexec)
{
	isSigned = false;
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &f) : name(f.name), isSigned(f.isSigned), signGrade(f.signGrade), execGrade(f.execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	*this = f;
}

Form& Form::operator = (const Form &f)
{
	if (f.signGrade < 1 || f.execGrade < 1)
		throw Form::GradeTooHighException();
	else if (f.signGrade > 150 || f.execGrade > 150)
		throw Form::GradeTooLowException();
	Form::isSigned = f.isSigned;
	return (*this);
}

Form::~Form(void)
{
	return ;
}

const std::string	Form::getName() const
{
	return (Form::name);
}

int	Form::getGradeToSign() const
{
	return (Form::signGrade);
}

int	Form::getGradeToExec() const
{
	return (Form::execGrade);
}

bool	Form::getisSign() const
{
	return (Form::isSigned);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (Form::signGrade < b.getGrade())
		throw Form::GradeTooLowException();
	Form::isSigned = true;
}


void	Form::execute(Bureaucrat const & executor) const
{
	if (!Form::isSigned)
		throw NotSignedException();
	if (Form::getGradeToExec() < executor.getGrade())
		throw GradeTooLowException();
}

std::ostream &operator << (std::ostream &out, const Form &f)
{
	out << "Form: " << f.getName() << " Grade to sign: " << f.getGradeToSign() << ", Grade to exec: " << f.getGradeToExec() << ", is signed: " << f.getisSign();
	return (out);
}
