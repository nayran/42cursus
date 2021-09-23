#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap ed("Ed");
	std::cout << std::endl;
	FragTrap ted("Ted");
	std::cout << std::endl;
	DiamondTrap led("Led");
	std::cout << std::endl;

	ed.attack(ted.getName());
	ted.takeDamage(0);
	ted.attack(ed.getName());
	ed.takeDamage(20);
	ted.highFivesGuys();
	std::cout << std::endl;
	led.attack(ted.getName());
	led.whoAmI();
	return (0);
}
