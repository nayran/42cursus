#ifndef FIXED_HPP 
# define FIXED_HPP

#include <iostream>
#include <string.h>

class Fixed{

private:
	int					pvalue;
	static const int	bits = 8;

public:
	Fixed(void);
	Fixed(const Fixed &f);
	Fixed & operator = (const Fixed &f);
	~Fixed(void);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
