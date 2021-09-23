#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap ed("Ed"), edd("Edd"), eddy("Eddy");

	ed.attack(edd.getName());
	edd.takeDamage(5);
	edd.attack(ed.getName());
	ed.takeDamage(7);
	edd.attack(eddy.getName());
	eddy.takeDamage(8);
	eddy.beRepaired(5);
	return (0);
}
