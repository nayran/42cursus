#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	HumanB::name = name;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::attack()
{
	std::cout << HumanB::name;
	std::cout << " attacks with his ";
	std::cout << HumanB::weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	HumanB::weapon = &weapon;
}
