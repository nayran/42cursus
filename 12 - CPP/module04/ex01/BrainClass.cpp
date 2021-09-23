#include "BrainClass.hpp"

Brain::Brain ()
{
    std::cout << "Brain constructor!" << std::endl;
	return ;
}

Brain::~Brain()
{
	std::cout << "Brain destructor!" << std::endl;
	return;
}

Brain::Brain(const Brain &b)
{
    std::cout << "Brain copy constructor!" << std::endl;
	Brain::operator = (b);
}

Brain &Brain::operator = (const Brain &b)
{
	Brain *tmp = new Brain();
	for (int x = 0; x < 100; x++)
		tmp->ideas[x] = b.ideas[x];
	return (*this);
}
