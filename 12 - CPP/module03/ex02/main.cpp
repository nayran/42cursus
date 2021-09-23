#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap ed("Ed");
	FragTrap ted("Ted");

	ed.attack(ted.getName());
	ted.takeDamage(0);
	ted.attack(ed.getName());
	ed.takeDamage(20);
	ted.highFivesGuys();
	return (0);
}
