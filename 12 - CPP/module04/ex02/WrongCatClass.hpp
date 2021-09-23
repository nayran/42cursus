#ifndef WRONGCATCLASS_HPP 
# define WRONGCATCLASS_HPP

#include "WrongAnimalClass.hpp"

class WrongCat : public WrongAnimal{

public: 
	WrongCat(void);
	WrongCat(const WrongCat &wc);
	WrongCat& operator = (const WrongCat &wc);
	~WrongCat(void);

	void	makeSound() const;
};

#endif
