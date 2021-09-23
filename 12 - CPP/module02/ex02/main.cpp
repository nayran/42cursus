#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed c;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a / b << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl;

	a = Fixed(10);
	c = Fixed(5);
	std::cout << a + c << std::endl;
	std::cout << a - c << std::endl;
	std::cout << a * c << std::endl;
	std::cout << a / c << std::endl;
	return (0);
}
