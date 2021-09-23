#ifndef WRONGANIMALCLASS_HPP
# define WRONGANIMALCLASS_HPP

#include <iostream>
#include <string.h>

class WrongAnimal{

protected:
	std::string		type;

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &wa);
	WrongAnimal& operator = (const WrongAnimal &wa);
	~WrongAnimal(void);

	void	makeSound() const;
	std::string getType() const;
};

#include "WrongCatClass.hpp"

#endif
