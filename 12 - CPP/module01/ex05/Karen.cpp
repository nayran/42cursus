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
	(this->*(func[x]))();
}

void	Karen::debug(void)
{
	std::cout << "DEBUG: I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "INFO: I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "ERROR: This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::panic(void)
{
	std::cout << "PANIC: This is not a complain, you can do better!" << std::endl;
}
