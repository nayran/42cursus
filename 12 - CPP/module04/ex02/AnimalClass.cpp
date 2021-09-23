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
	(void)a;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType() const
{
	return (Animal::type);
}
