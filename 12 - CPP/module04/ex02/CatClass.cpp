#include "CatClass.hpp"

Cat::Cat ()
{
	Cat::b = new Brain();
    std::cout << "Cat constructor!" << std::endl;
	Animal::type = "Cat";
	return ;
}

Cat::~Cat()
{
	std::cout << "Cat destructor!" << std::endl;
	delete b;
	return;
}

Cat::Cat(const Cat &c)
{
    std::cout << "Cat copy constructor!" << std::endl;
	Cat::operator = (c);
}

Cat &Cat::operator = (const Cat &c)
{
	Cat	*tmp = new Cat();
	tmp->type = c.type;
	tmp->b = c.b;
	return (*tmp);
}

void	Cat::makeSound() const
{
	std::cout << "Cat Sound" << std::endl;
}
