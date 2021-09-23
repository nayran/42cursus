#ifndef INTERN_HPP 
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

public:
	Intern();
	Intern(const Intern &i);
	Intern& operator = (const Intern &i);
	~Intern(void);

	Form	*makeForm(std::string formName, std::string target);
};

#endif

