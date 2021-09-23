#include "WrongAnimalClass.hpp"

WrongAnimal::WrongAnimal ()
{
    std::cout << "Wrong Animal constructor!" << std::endl;
	WrongAnimal::type = "Type";
	return ;
}

WrongAnimal::~WrongAnimal ()
{
	std::cout << "Wrong Animal destructor!" << std::endl;
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
    std::cout << "Wrong Animal copy constructor!" << std::endl;
	WrongAnimal::operator = (a);
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &a)
{
	WrongAnimal *tmp = new WrongAnimal();
	tmp->type = a.type;
	return (*tmp);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal Sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (WrongAnimal::type);
}
