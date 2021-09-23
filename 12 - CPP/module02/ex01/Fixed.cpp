#include "Fixed.hpp"

Fixed::Fixed ()
{
	std::cout << "Default constructor called" << std::endl;
	Fixed::pvalue = 0;
}

Fixed::Fixed (const int value)
{
	std::cout << "Int constructor called" << std::endl;
	Fixed::pvalue = value << bits;
}

Fixed::Fixed (const float value)
{
	std::cout << "Float constructor called" << std::endl;
	Fixed::pvalue = roundf(value * (1 << bits));
}

Fixed::~Fixed ()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed &Fixed::operator = (const Fixed &f)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &f)
		this->pvalue = f.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return (Fixed::pvalue);
}

void Fixed::setRawBits( int const raw )
{
	Fixed::pvalue = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)((float)pvalue / (float)(1 << bits)));
}

int Fixed::toInt( void ) const
{
	return (pvalue >> bits);
}

std::ostream &operator << (std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}
