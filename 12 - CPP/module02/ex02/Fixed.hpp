#ifndef FIXED_HPP 
# define FIXED_HPP

#include <iostream>
#include <string.h>
#include <cmath>

class Fixed{

private:
	int					pvalue;
	static const int	bits = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &f);
	Fixed &operator = (const Fixed &f);
	~Fixed(void);
	bool operator > (const Fixed &f) const;
	bool operator < (const Fixed &f) const;
	bool operator >= (const Fixed &f) const;
	bool operator <= (const Fixed &f) const;
	bool operator == (const Fixed &f) const;
	bool operator != (const Fixed &f) const;
	Fixed operator + (const Fixed &f) const;
	Fixed operator - (const Fixed &f) const;
	Fixed operator * (const Fixed &f) const;
	Fixed operator / (const Fixed &f) const;
	Fixed &operator ++ ();
	Fixed &operator -- ();
	Fixed operator ++ (int);
	Fixed operator -- (int);
	static const Fixed &min(const Fixed &f1, const Fixed &f2);
	static const Fixed &max(const Fixed &f1, const Fixed &f2);
	static Fixed &min(Fixed &f1, Fixed &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream &operator << (std::ostream &os, const Fixed &f);

#endif
