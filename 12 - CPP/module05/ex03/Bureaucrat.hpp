#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string.h>

class Form;
class Bureaucrat {

private:
	const std::string	name;
	int					grade;

public:
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &b);
	Bureaucrat& operator = (const Bureaucrat &b);
	~Bureaucrat(void);

	Bureaucrat(std::string name, int grade);
	const std::string	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form &f);
	void				executeForm(Form const & form);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Exception: Grade too high!");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Exception: Grade too low!");
			}
	};
};

std::ostream &operator << (std::ostream &os, const Bureaucrat &b);

#include "Form.hpp"

#endif
