#ifndef ANIMALCLASS_HPP
# define ANIMALCLASS_HPP

#include <iostream>
#include <string.h>

class Animal{

protected:
	std::string		type;

public:
	Animal(void);
	Animal(const Animal &a);
	Animal& operator = (const Animal &a);
	virtual ~Animal(void);

	virtual void	makeSound() const = 0;
	std::string getType() const;
};

#include "DogClass.hpp"
#include "CatClass.hpp"

#endif
