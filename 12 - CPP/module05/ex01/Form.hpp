#ifndef FORM_HPP 
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {

private:
	const std::string	name;
	bool				isSigned;
	const int			signGrade;
	const int			execGrade;

public:
	Form(const std::string Name, int gradesign, int gradeexec);
	Form(const Form &f);
	Form& operator = (const Form &f);
	~Form(void);

	const std::string	getName() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;
	bool				getisSign() const;
	void				beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Form exception: Grade too high!");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Form exception: Grade too low!");
			}
	};
};

std::ostream &operator << (std::ostream &out, const Form &f);

#endif
