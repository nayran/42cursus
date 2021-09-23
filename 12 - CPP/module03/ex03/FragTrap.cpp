#include "FragTrap.hpp"

FragTrap::FragTrap ()
{
    std::cout << "FragTrap constructor!" << std::endl;
	return ;
}

FragTrap::FragTrap (std::string Name)
{
	FragTrap::name = Name;
	FragTrap::hitpoints = 100;
	FragTrap::energyPoints = 100;
	FragTrap::attackDamage = 30;
	std::cout << "FragTrap " << name << " born!" << std::endl;
}

FragTrap::~FragTrap ()
{
	std::cout << "FragTrap " << name << " died!" << std::endl;
	return;
}

FragTrap::FragTrap(const FragTrap &ft)
{
    std::cout << "FragTrap copy constructor!" << std::endl;
	FragTrap::operator = (ft);
}

FragTrap &FragTrap::operator = (const FragTrap &ft)
{
	if (this != &ft)
	{
		this->name = ft.getName();
		this->hitpoints = ft.getHitpoints();
		this->energyPoints = ft.getEnergyPoints();
		this->attackDamage = ft.getAttackDamage();
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << FragTrap::name  << " requested high fives!" << std::endl;
}
