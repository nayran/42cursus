#include "ClassData.hpp"

Data::Data(void)
{
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNumber = "";
	drkstSecret = "";
	num = 0;
	return ;
}

Data::~Data(void)
{
	return ;
}

void	Data::addContact(Data *c)
{
	static int x;
	
	if (x > 7)
		x = 0;
	c[x].num = x + 1;
	std::cout << "First name: ";
	c[x].firstName = ft_getinfo();
	std::cout << "Last name: ";
	c[x].lastName = ft_getinfo();
	std::cout << "Nickname: ";
	c[x].nickname = ft_getinfo();
	std::cout << "Phonenumber: ";
	c[x].phoneNumber = ft_getnum();
	std::cout << "Darkest secret: ";
	c[x].drkstSecret = ft_getinfo();
	x++;
	std::cout << "Done\n" << std::endl;
}

void	Data::searchContacts(Data *c)
{
	int x;

	ft_formatprint("Index");
	ft_formatprint("Name");
	ft_formatprint("Last name");
	ft_formatprint("Nickname");
	x = -1;
	while (c[++x].num != 0)
	{
		std::cout << std::endl;
		ft_formatprint(std::to_string(c[x].num));
		ft_formatprint(c[x].firstName);
		ft_formatprint(c[x].lastName);
		ft_formatprint(c[x].nickname);
	}
	std::cout << std::endl << std::endl;
	std::cout << "Index: ";
	x = std::stoi(ft_getnum()) - 1;
	if (x < 0 || x > 7 || c[x].num == 0)
		std::cout << "Contact not found!" << std::endl;
	else
	{
		std::cout << "First name: " << c[x].firstName << std::endl;
		std::cout << "Last name: " << c[x].lastName << std::endl;
		std::cout << "Nickname: " << c[x].nickname << std::endl;
		std::cout << "Phonenumber: " << c[x].phoneNumber << std::endl;
		std::cout << "Darkest secret: " << c[x].drkstSecret << std::endl;
	}
	std::cout << std::endl;
}
