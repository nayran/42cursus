#ifndef CATCLASS_HPP 
# define CATCLASS_HPP

#include "AnimalClass.hpp"
#include "BrainClass.hpp"

class Cat : virtual public Animal{

private:
	Brain *b;

public: 
	Cat(void);
	Cat(const Cat &c);
	Cat& operator = (const Cat &c);
	virtual ~Cat(void);

	virtual void	makeSound() const;
};

#endif
