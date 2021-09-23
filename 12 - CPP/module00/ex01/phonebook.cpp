#include "ClassData.hpp"

std::string	ft_getnum()
{
	std::string info;

	info = '\0';
	while (!ft_isallnum(info))
		std::cin >> info;
	return (info);
}

std::string	ft_getinfo()
{
	std::string info;

	info = '\0';
	while (info[0] == '\0')
		std::cin >> info;
	return (info);
}

std::string	ft_menu()
{
	std::string	command;

	std::cout << "\tPHONEBOOK\nCommands: ADD, SEARCH, EXIT" << std::endl;
	std::cin >> command;
	return (command);
}

int		main()
{
	std::string	command;
	Data		c[8];

	while (1)
	{
		command = ft_menu();
		if (command == "ADD")
			Data::addContact(&c[0]);
		else if (command == "SEARCH")
			Data::searchContacts(&c[0]);
		else if (command == "EXIT")
			return (0);
		else
			std::cout << "ERROR! Command not found!!\n" << std::endl;
	}
}
