#include "Karen.hpp"

Karen::Karen (void)
{
	return ;
}

Karen::~Karen (void)
{
	return ;
}

void Karen::complain( std::string level )
{
	int			x;
	std::string	s[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Karen::*func[])() = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error, &Karen::panic};

	x = 0;
	while (x < 4 && level != s[x])
		x++;
	switch (x)
	{
		case 0:
			(this->*(func[0]))();
		case 1:
			(this->*(func[1]))();
		case 2:
			(this->*(func[2]))();
		case 3:
			(this->*(func[3]))();
			break;
		default:
			(this->*(func[4]))();
			break;
	}
}

void	Karen::debug(void)
{
	std::cout << "[ DEBUG ]\nI love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
	std::cout << std::endl;
}

void	Karen::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
	std::cout << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
	std::cout << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable, I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	Karen::panic(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	std::cout << std::endl;
}
