#include <iostream>
#include <fstream>
#include <string.h>

int			ft_strlen(std::string s)
{
	int x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

std::string	ft_strstr(std::string s1, std::string s2)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (s1[x])
	{
		if (s1[x] == s2[y])
			y++;
		else
			return ("");
		if (y == ft_strlen(s2))
			return (&s1[x - y]);
		x++;
	}
	return ("");
}

int	main(int argc, char **argv)
{
	std::ifstream	file;
	std::ofstream	newfile;
	std::string		line;
	std::string		filename;
	int x;

	if (argc > 4 || argc < 4)
		return (0);
	file.open(argv[1]);
	if (!file.is_open())
	{
		std::cout << "This file don't exist" << std::endl;
		return (0);
	}
	filename = argv[1];
	filename += ".replace";
	newfile.open(filename, std::ios::out);
	while (std::getline(file, line))
	{
		x = -1;
		while (line[++x])
		{
			if (ft_strstr(&line[x], argv[2]) == "")
				newfile << line[x];
			else
			{
				x += ft_strlen(argv[2]) - 1;
				newfile << argv[3];
			}
		}
		newfile << std::endl;
	}
	file.close();
	newfile.close();
	return (0);
}
