#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap ()
{
	DiamondTrap::name = "noname";
	DiamondTrap::hitpoints = 0;
	DiamondTrap::energyPoints = 0;
	DiamondTrap::attackDamage = 0;
    std::cout << "DiamondTrap constructor!" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap (std::string Name)
{
	DiamondTrap::name = Name;
	ClapTrap::name = Name + "_clap_name";
	DiamondTrap::hitpoints = FragTrap::hitpoints;
	DiamondTrap::energyPoints = ScavTrap::energyPoints;
	DiamondTrap::attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << DiamondTrap::name << " born!" << std::endl;
}

DiamondTrap::~DiamondTrap ()
{
	std::cout << "DiamondTrap " << name << " died!" << std::endl;
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt)
{
    std::cout << "DiamondTrap copy constructor!" << std::endl;
	DiamondTrap::operator = (dt);
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &dt)
{
	if (this != &dt)
	{
		this->name = dt.getName();
		this->hitpoints = dt.getHitpoints();
		this->energyPoints = dt.getEnergyPoints();
		this->attackDamage = dt.getAttackDamage();
	}
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "Diamond name: " << DiamondTrap::name  << " and Clap name: " << ClapTrap::name << "!" <<  std::endl;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}
