#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap ed("Ed");
	ScavTrap ted("Ted");

	ed.attack(ted.getName());
	ted.takeDamage(0);
	ted.attack(ed.getName());
	ed.takeDamage(20);
	ted.guardGate();
	return (0);
}
