#include "Fixed.hpp"

Fixed::Fixed ()
{
	Fixed::pvalue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed ()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed (const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	Fixed::operator = (f);
}

Fixed &Fixed::operator = (const Fixed &f)
{
	std::cout << "Assignation operator called" << std::endl;
	this->pvalue = f.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (Fixed::pvalue);
}

void Fixed::setRawBits( int const raw )
{
	Fixed::pvalue = raw;
}
