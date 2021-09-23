#include "Fixed.hpp"

Fixed::Fixed ()
{
	Fixed::pvalue = 0;
}

Fixed::Fixed (const int value)
{
	Fixed::pvalue = value << bits;
}

Fixed::Fixed (const float value)
{
	Fixed::pvalue = roundf(value * (1 << bits));
}

Fixed::~Fixed ()
{
	return ;
}

Fixed::Fixed (const Fixed &f)
{
	*this = f;
}

Fixed &Fixed::operator = (const Fixed &f)
{
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

bool Fixed::operator > (const Fixed &f) const
{
	return (pvalue > f.pvalue);
}

bool Fixed::operator < (const Fixed &f) const
{
	return (pvalue < f.pvalue);
}

bool Fixed::operator >= (const Fixed &f) const
{
	return (pvalue >= f.pvalue);
}

bool Fixed::operator <= (const Fixed &f) const
{
	return (pvalue <= f.pvalue);
}

bool Fixed::operator == (const Fixed &f) const
{
	return (pvalue == f.pvalue);
}

bool Fixed::operator != (const Fixed &f) const
{
	return (pvalue != f.pvalue);
}

Fixed	Fixed::operator + (const Fixed &f) const
{
	Fixed aux;
	aux.setRawBits(pvalue + f.pvalue);
	return (aux);
}

Fixed	Fixed::operator - (const Fixed &f) const
{
	Fixed aux;
	aux.setRawBits(pvalue - f.pvalue);
	return (aux);
}

Fixed	Fixed::operator * (const Fixed &f) const
{
	Fixed aux;
	aux.setRawBits(pvalue * f.getRawBits() >> bits);
	return (aux);
}

Fixed	Fixed::operator / (const Fixed &f) const
{
	Fixed aux;
	aux.setRawBits(pvalue / f.getRawBits() << bits);
	return (aux);
}

Fixed &Fixed::operator ++ ()
{
	++this->pvalue;
	return (*this);
}

Fixed &Fixed::operator -- ()
{
	--this->pvalue;
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed aux(*this);
	operator ++();
	return (aux);
}

Fixed Fixed::operator -- (int)
{
	Fixed aux(*this);
	operator --();
	return (aux);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f2);
	return (f1);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return (f2);
	return (f1);
}
