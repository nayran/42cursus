#ifndef DOGCLASS_HPP 
# define DOGCLASS_HPP

#include "AnimalClass.hpp"

class Dog : virtual public Animal{

public: 
	Dog(void);
	Dog(const Dog &d);
	Dog& operator = (const Dog &d);
	~Dog(void);

	virtual void	makeSound() const;
};

#endif
