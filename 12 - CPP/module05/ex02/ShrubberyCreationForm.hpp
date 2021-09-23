#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : virtual public Form {

private:
	std::string target;

public:
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &scf);
	ShrubberyCreationForm &operator = (const ShrubberyCreationForm &scf);
	~ShrubberyCreationForm();

	const	std::string &getTarget() const;
	void	execute(Bureaucrat const & executor) const;
};

#endif
