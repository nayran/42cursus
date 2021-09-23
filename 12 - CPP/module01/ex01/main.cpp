#include "Zombie.hpp"

int			ft_isallnum(std::string info)
{
	int x;

	x = -1;
	if (info[0] == '\0')
		return (0);
	while (info[++x])
	{
		if (info[x] < '0' || info[x] > '9')
			return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	Zombie *z;
	int n;
	
	if (argc < 2 || argc > 2)
		return (0);
	n = 0;
	if (ft_isallnum(argv[1]))
		n = std::stoi(argv[1]);
	if (n == 0)
		std::cout << "There's no horde without zombies!" << std::endl;
	z = zombieHorde(n, "Zombie ");
	delete[] z;
	return (0);
}
