#include "Zombie.hpp"

Zombie::Zombie (std::string name)
{
	Zombie::name = name;
}

Zombie::~Zombie (void)
{
	std::cout << Zombie::name << " died" << std::endl;
}

void		Zombie::announce( void )
{
	std::cout << Zombie::name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
