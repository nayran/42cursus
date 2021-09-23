#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :
	weapon(weapon)
{
	HumanA::name = name;
}

HumanA::~HumanA(void)
{
	return ;
}

void	HumanA::attack()
{
	std::cout << HumanA::name;
	std::cout << " attacks with his ";
	std::cout << HumanA::weapon.getType() << std::endl;
}
