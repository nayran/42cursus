#include "AnimalClass.hpp"

Animal::Animal ()
{
    std::cout << "Animal constructor!" << std::endl;
	Animal::type = "NoType";
	return ;
}

Animal::~Animal ()
{
	std::cout << "Animal destructor!" << std::endl;
	return;
}

Animal::Animal(const Animal &a)
{
    std::cout << "Animal copy constructor!" << std::endl;
	Animal::operator = (a);
}

Animal &Animal::operator = (const Animal &a)
{
	Animal *tmp = new Animal();
	tmp->type = a.type;
	return (*tmp);
}

void	Animal::makeSound() const
{
	std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType() const
{
	return (Animal::type);
}
