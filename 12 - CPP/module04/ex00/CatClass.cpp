#include "CatClass.hpp"

Cat::Cat ()
{
    std::cout << "Cat constructor!" << std::endl;
	Animal::type = "Cat";
	return ;
}

Cat::~Cat()
{
	std::cout << "Cat destructor!" << std::endl;
	return;
}

Cat::Cat(const Cat &c)
{
    std::cout << "Cat copy constructor!" << std::endl;
	Cat::operator = (c);
}

Cat &Cat::operator = (const Cat &c)
{
	Cat *tmp = new Cat();
	tmp->type = c.type;
	return (*tmp);
}

void	Cat::makeSound() const
{
	std::cout << "Cat Sound" << std::endl;
}
