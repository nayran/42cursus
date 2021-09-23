#include "Intern.hpp"

Intern::Intern()
{
	return;
}

Intern::Intern(const Intern &i)
{
	*this = i;
}

Intern &Intern::operator = (const Intern &i)
{
	(void)i;
	return (*this);
}

Intern::~Intern(void)
{
	return;
}

int		ft_strcmp(std::string string, std::string string2)
{
	int x;
	std::string s1;
	std::string s2;

	x = 0;
	s1 = string;
	s2 = string2;
	while (s1[x] && s2[x])
	{
		if (s1[x] >= 65  && s1[x] <= 90)
			s1[x] += 32;
		if (s2[x] >= 65  && s2[x] <= 90)
			s2[x] += 32;
		if (s1[x] != s2[x])
			return (0);
		x++;
	}
	return (1);
}

Form	*Intern::makeForm(std::string formName, std::string target)
{
	std::string forms[3] = {"shrubbery creation request", "robotomy request", "presidential pardon request"};
	int x;

	x = 0;
	while (formName != forms[x])
		x++;
	switch (x)
	{
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Form do not exists!" << std::endl;
	}
	return (NULL);
}
