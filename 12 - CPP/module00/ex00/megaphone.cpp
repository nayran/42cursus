#include <iostream>

char	*ft_megaphone(char *argv)
{
	int y;

	y = -1;
	while (argv[++y])
	{
		if (argv[y] >= 97 && argv[y] <= 122)
			argv[y] -= 32;
	}
    return (argv);
}

int	main(int argc, char **argv)
{
	int x = 0;
	
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	while (++x < argc)
	{
		argv[x] = ft_megaphone(argv[x]);
		std::cout << argv[x];
		std::cout << ' ';
	}
	std::cout << '\n';
}
