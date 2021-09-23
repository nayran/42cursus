#include "Zombie.hpp"

Zombie*			zombieHorde( int N, std::string name )
{
	int x;
	Zombie *z;

	x = 0;
	z = new Zombie[N];
	while (x < N)
	{
		z[x].giveName(name + std::to_string(x));
		z[x].announce();
		x++;
	}
	return (z);
}
