#include "Weapon.hpp"

Weapon::Weapon(std::string const &type)
{
	Weapon::setType(type);
}

Weapon::~Weapon(void)
{
	return ;
}

void Weapon::setType(std::string const &type)
{
	Weapon::type = type;
}

std::string const &Weapon::getType(void)
{
	return(Weapon::type);
}
