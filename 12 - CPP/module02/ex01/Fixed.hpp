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
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream &operator << (std::ostream &os, const Fixed &f);

#endif
