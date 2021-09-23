#ifndef ROBOTOMYREQUESTFORM_HPP 
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : virtual public Form{

private:
	std::string target;

public:
	RobotomyRequestForm(const std::string Target);
	RobotomyRequestForm(const RobotomyRequestForm &rrf);
	RobotomyRequestForm & operator = (const RobotomyRequestForm &rrf);
	~RobotomyRequestForm(void);
	
	const	std::string &getTarget() const;
	void	execute(Bureaucrat const & executor) const;
};

#endif
