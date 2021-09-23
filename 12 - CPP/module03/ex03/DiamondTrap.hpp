#ifndef DIAMONDTRAP_HPP 
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap{

private:
	std::string name;
public:
	DiamondTrap(void);
	DiamondTrap(const DiamondTrap &dt);
	DiamondTrap& operator = (const DiamondTrap &dt);
	~DiamondTrap(void);

	DiamondTrap(std::string Name);
	void attack(std::string const & target);
	void whoAmI();
};

#endif
