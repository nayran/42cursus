#include "Conversion.hpp"
#include <cmath>
#include <sstream>

Conversion::Conversion(std::string Num) : strNum(Num)
{
	int x = 0;

	neg = false;
	inf	= false;
	dot = false;
	type = "none";
	while (strNum[x])
		x++;
	this->strLen = x;
	type = setType();
	return ;
}

Conversion::Conversion (const Conversion &c)
{
	*this = c;
}

Conversion& Conversion::operator = (const Conversion &c)
{
	Conversion *tmp = new Conversion(c.strNum);
	tmp->type = c.type;
	tmp->strLen = c.strLen;
	tmp->neg = c.neg;
	tmp->inf = c.inf;
	return (*tmp);
}

Conversion::~Conversion(void)
{
	return ;
}

std::string	Conversion::searchLimits()
{
	inf = true;
	if (strNum == "nan")
		return ("nan");
	if (strNum == "+inf")
		return ("+inf");
	if (strNum == "-inf")
		return ("-inf");
	if (strNum == "nanf")
		return ("nanf");
	if (strNum == "+inff")
		return ("+inff");
	if (strNum == "-inff")
		return ("-inff");
	inf = false;
	return ("none");
}

std::string	Conversion::setType()
{
	type = searchLimits();
	if (type != "none")
		return type;
	if ((!isprint(strNum[0])) || (strLen > 1 && strNum[0] == '.'))
		return ("invalid");
	if (strLen < 2 && isprint(strNum[0]))
		if (strNum[0] < '0' || strNum[0] > '9')
			return ("char");
	int x = 0;
	if (strNum[0] == '-')
	{
		neg = true;
		x++;
	}
	for (; x < strLen; x++)
	{
		if (strNum[x] != '.' && (strNum[x] < '0' || strNum[x] > '9'))
		{
			if (strNum[x] == 'f' && x + 1 == strLen && dot)
				return ("float");
			else
				return ("invalid");
		}
		if (strNum[x] == '.')
			dot = true;
	}
	if (dot)
		return ("double");
	return ("int");
}

std::string Conversion::getStrNum() const
{
	return(strNum);
}

std::string	Conversion::getType() const
{
	return(type);
}

bool		Conversion::getDot() const
{
	return(dot);
}


char	Conversion::toChar() const
{
	if (type == "invalid")
		throw InvalidException();
	if (type == "char")
		return (strNum[0]);
	std::istringstream iss(strNum);
	if (type == "int")
	{
		int i;
		if (!(iss >> i) || !isprint(i))
			throw ConversionNotPossibleException();
		return (static_cast<char>(i));
	}
	if (type == "float")
	{
		float f;
		if (!(iss >> f) || !isprint(f))
			throw ConversionNotPossibleException();
		return (static_cast<char>(f));
	}
	if (type == "double")
	{
		double d;
		if (!(iss >> d) || !isprint(d))
			throw ConversionNotPossibleException();
		return (static_cast<char>(d));
	}
	return (0);
}

int	Conversion::toInt() const
{
	if (type == "invalid")
		throw InvalidException();
	if (type == "char")
		return (static_cast<int>(strNum[0]));
	std::istringstream iss(strNum);
	if (type == "int")
	{
		int i;
		if (!(iss >> i))
			throw ConversionNotPossibleException();
		return (i);
	}
	if (type == "float")
	{
		float f;
		if (!(iss >> f))
			throw ConversionNotPossibleException();
		return (static_cast<int>(f));
	}
	if (type == "double")
	{
		double d;
		if (!(iss >> d))
			throw ConversionNotPossibleException();
		return (static_cast<int>(d));
	}
	return (0);
}

float Conversion::toFloat() const
{
	if (type == "invalid")
		throw InvalidException();
	if (type == "nanf")
		return (std::numeric_limits<float>::quiet_NaN());
	if (type == "+inff")
        return (std::numeric_limits<float>::infinity());
	if (type == "-inff")
        return (-std::numeric_limits<float>::infinity());
	if (type == "char")
		return (static_cast<float>(strNum[0]));
	std::istringstream iss(strNum);
	if (type == "int")
	{
		int i;
		if (!(iss >> i))
			throw ConversionNotPossibleException();
		return (static_cast<float>(i));
	}
	if (type == "float")
	{
		float f;
		if (!(iss >> f))
			throw ConversionNotPossibleException();
		return (f);
	}
	if (type == "double")
	{
		double d;
		if (!(iss >> d))
			throw ConversionNotPossibleException();
		return (static_cast<float>(d));
	}
	return (0.0f);
}

double Conversion::toDouble() const
{
	if (type == "invalid")
		throw InvalidException();
	if (type == "nan")
		return (std::numeric_limits<double>::quiet_NaN());
	if (type == "+inf")
        return (std::numeric_limits<double>::infinity());
	if (type == "-inf")
        return (-std::numeric_limits<double>::infinity());
	if (type == "char")
		return (static_cast<double>(strNum[0]));
	std::istringstream iss(strNum);
	if (type == "int")
	{
		int i;
		if (!(iss >> i))
			throw ConversionNotPossibleException();
		return (static_cast<double>(i));
	}
	if (type == "float")
	{
		float f;
		if (!(iss >> f))
			throw ConversionNotPossibleException();
		return (f);
	}
	if (type == "double")
	{
		double d;
		if (!(iss >> d))
			throw ConversionNotPossibleException();
		return (static_cast<double>(d));
	}
	return (0.0);
}

std::ostream &operator << (std::ostream &os, const Conversion &c)
{
	os << "char:\t";
	try
	{
		char cha = c.toChar();
		os << cha << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	os << "int:\t";
	try
	{
		int in = c.toInt();
		os << in << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	os << "float:\t";
	try
	{
		float f = c.toFloat();
		os << f;
		if (c.getDot() == false)
			os << ".0";
		os << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	os << "double:\t";
	try
	{
		double d = c.toDouble();
		os << d;
		if (c.getDot() == false)
			os << ".0";
		os << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (os);
}
