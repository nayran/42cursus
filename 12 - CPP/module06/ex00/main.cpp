#include "Conversion.hpp"

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
	{
		std::cout << "Only 1 number per time!" << std::endl;
		return (0);
	}
	Conversion x(argv[1]);
	std::cout << x << std::endl;
	return (0);
}
