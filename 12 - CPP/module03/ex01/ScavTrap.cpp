#include "ScavTrap.hpp"

ScavTrap::ScavTrap ()
{
    std::cout << "ScavTrap constructor!" << std::endl;
	return ;
}

ScavTrap::ScavTrap (std::string Name)
{
	ScavTrap::name = Name;
	ScavTrap::hitpoints = 100;
	ScavTrap::energyPoints = 50;
	ScavTrap::attackDamage = 20;
	std::cout << "ScavTrap " << name << " born!" << std::endl;
}

ScavTrap::~ScavTrap ()
{
	std::cout << "ScavTrap " << name << " died!" << std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap &st)
{
    std::cout << "ScavTrap copy constructor!" << std::endl;
	ScavTrap::operator = (st);
}

ScavTrap &ScavTrap::operator = (const ScavTrap &st)
{
	if (this != &st)
	{
		this->name = st.getName();
		this->hitpoints = st.getHitpoints();
		this->energyPoints = st.getEnergyPoints();
		this->attackDamage = st.getAttackDamage();
	}
	return (*this);
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " <<  name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;

}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap have enterred in Gate keeper mode." << std::endl;
}
