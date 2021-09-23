#ifndef SCAVTRAP_HPP 
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{

private:

public:
	ScavTrap(void);
	ScavTrap(const ScavTrap &st);
	ScavTrap& operator = (const ScavTrap &st);
	~ScavTrap(void);

	ScavTrap(std::string Name);
	void guardGate(void);
	void attack(std::string const & target);
};

#endif
