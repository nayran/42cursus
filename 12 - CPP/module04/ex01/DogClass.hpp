#ifndef DOGCLASS_HPP 
# define DOGCLASS_HPP

#include "AnimalClass.hpp"
#include "BrainClass.hpp"

class Dog : virtual public Animal{

private:
	Brain *b;

public: 
	Dog(void);
	Dog(const Dog &d);
	Dog& operator = (const Dog &d);
	virtual ~Dog(void);

	virtual void	makeSound() const;
};

#endif
