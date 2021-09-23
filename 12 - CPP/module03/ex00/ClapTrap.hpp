#ifndef CLAPTRAP_HPP 
# define CLAPTRAP_HPP

#include <iostream>
#include <string.h>

class ClapTrap{

private:
	std::string		name;
	int				hitpoints;
	int				energyPoints;
	int				attackDamage;

public:
	ClapTrap(void);
	ClapTrap(std::string Name);
	ClapTrap(const ClapTrap &ct);
	ClapTrap& operator = (const ClapTrap &ct);
	~ClapTrap(void);
	std::string getName( void ) const;
	int getHitpoints( void ) const;
	int getEnergyPoints( void ) const;
	int getAttackDamage( void ) const;
	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
