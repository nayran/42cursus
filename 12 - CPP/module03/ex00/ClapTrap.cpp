#include "ClapTrap.hpp"

ClapTrap::ClapTrap ()
{
	return ;
}

ClapTrap::ClapTrap (std::string Name)
{
	ClapTrap::name = Name;
	ClapTrap::hitpoints = 10;
	ClapTrap::energyPoints = 10;
	ClapTrap::attackDamage = 0;
	std::cout << "ClapTrap " << name << " born!" << std::endl;
}

ClapTrap::~ClapTrap ()
{
	std::cout << "ClapTrap " << name << " died!" << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
	ClapTrap::operator = (ct);
}

ClapTrap &ClapTrap::operator = (const ClapTrap &ct)
{
	if (this != &ct)
	{
		this->name = ct.getName();
		this->hitpoints = ct.getHitpoints();
		this->energyPoints = ct.getEnergyPoints();
		this->attackDamage = ct.getAttackDamage();
	}
	return (*this);
}

std::string ClapTrap::getName( void ) const
{
	return (name);
}

int	ClapTrap::getHitpoints( void ) const
{
	return (hitpoints);
}

int ClapTrap::getEnergyPoints( void ) const
{
	return (energyPoints);
}

int ClapTrap::getAttackDamage( void ) const
{
	return (attackDamage);
}

void ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " <<  name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitpoints -= amount;
	std::cout << "ClapTrap " <<  name << " took " << amount << " points of damage! HP: " << hitpoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	hitpoints += amount;
	std::cout << "ClapTrap " <<  name << " repaired " << amount << " points of damage! HP: " << hitpoints << std::endl;
}
