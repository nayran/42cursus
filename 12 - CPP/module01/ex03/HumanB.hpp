#ifndef HUMANB_HPP 
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{

private:
	Weapon		*weapon;
	std::string	name;

public:
	void	attack();
	void	setWeapon(Weapon &weapon);
	HumanB(std::string name);
	~HumanB(void);
};

#endif
