#include "Zombie.hpp"

Zombie::Zombie (void)
{
	return ;
}

Zombie::~Zombie (void)
{
	std::cout << Zombie::name << " died" << std::endl;
}

void	Zombie::giveName(std::string name)
{
	Zombie::name = name;
}
void		Zombie::announce( void )
{
	std::cout << Zombie::name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
