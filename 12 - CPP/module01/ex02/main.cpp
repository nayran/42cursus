#include <iostream>
#include <string.h>

int	main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string &stringREF = s;

	*stringPTR = s;
	std::cout << "\tstring\t\t\tstringPTR\t\tstringREF" << std::endl;
	std::cout << "address\t";	
	std::cout << &s << "\t\t";
	std::cout << stringPTR << "\t\t";
	std::cout << &stringREF << std::endl;
	std::cout << "string\t";
	std::cout << s << '\t';
	std::cout << *stringPTR << '\t';
	std::cout << stringREF << std::endl;
	return (0);
}
