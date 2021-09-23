#ifndef CATCLASS_HPP 
# define CATCLASS_HPP

#include "AnimalClass.hpp"

class Cat : virtual public Animal{

public: 
	Cat(void);
	Cat(const Cat &c);
	Cat& operator = (const Cat &c);
	~Cat(void);

	virtual void	makeSound() const;
};

#endif
