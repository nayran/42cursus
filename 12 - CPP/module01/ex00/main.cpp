#include "Zombie.hpp"

int		main()
{
	int x;
	std::string name;
	
	x = -1;
	while (++x < 5)
	{
		name = "Zombie";
		name += std::to_string(x);
		randomChump(name);
	}
	return (0);
}
