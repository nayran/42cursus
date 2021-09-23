#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <string>

class Conversion{

private:
	const std::string	strNum;
	std::string			type;
	int					strLen;
	bool				neg;
	bool				inf;
	bool				dot;

public:
	Conversion(std::string Num);
	Conversion (const Conversion &c);
	Conversion& operator = (const Conversion &c);
	~Conversion(void);

	std::string getStrNum() const;
	std::string	getType() const;
	std::string	searchLimits();
	std::string	setType();
	bool		getDot() const;

	char	toChar() const;
	int		toInt() const;
	float	toFloat() const;
	double	toDouble() const;

	class InvalidException: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("invalid argument!");
			}
	};
	class ConversionNotPossibleException: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("conversion is not possible!");
			}
	};
};

std::ostream &operator << (std::ostream &os, const Conversion &c);

#endif
