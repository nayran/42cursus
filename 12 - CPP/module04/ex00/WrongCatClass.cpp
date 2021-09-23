#include "WrongCatClass.hpp"

WrongCat::WrongCat ()
{
    std::cout << "Wrong Cat constructor!" << std::endl;
	WrongAnimal::type = "Wrong Cat";
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destructor!" << std::endl;
	return;
}

WrongCat::WrongCat(const WrongCat &c)
{
    std::cout << "Wrong Cat copy constructor!" << std::endl;
	WrongAnimal::operator = (c);
}

WrongCat &WrongCat::operator = (const WrongCat &c)
{
	WrongCat *tmp = new WrongCat();
	tmp->type = c.type;
	return (*tmp);
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Cat Sound" << std::endl;
}
