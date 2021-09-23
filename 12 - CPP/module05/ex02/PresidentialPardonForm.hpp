#ifndef PRESIDENTIALPARDONFORM_HPP 
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : virtual public Form{

private:
	std::string target;

public:
	PresidentialPardonForm(const std::string Target);
	PresidentialPardonForm(const PresidentialPardonForm &ppf);
	PresidentialPardonForm & operator = (const PresidentialPardonForm &ppf);
	~PresidentialPardonForm(void);
	
	const	std::string &getTarget() const;
	void	execute(Bureaucrat const & executor) const;
};

#endif
