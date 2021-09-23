#include "DogClass.hpp"

Dog::Dog ()
{
    std::cout << "Dog constructor!" << std::endl;
	Animal::type = "Dog";
	return ;
}

Dog::~Dog()
{
	std::cout << "Dog destructor!" << std::endl;
	return;
}

Dog::Dog(const Dog &d)
{
    std::cout << "Dog copy constructor!" << std::endl;
	Dog::operator = (d);
}

Dog &Dog::operator = (const Dog &d)
{
	Dog *tmp = new Dog();
	tmp->type = d.type;
	return (*tmp);
}

void	Dog::makeSound() const
{
	std::cout << "Dog Sound" << std::endl;
}
