#ifndef MATERIAS_HPP
# define MATERIAS_HPP

#include "AMateria.hpp"

class Ice : virtual public AMateria {

public:
	Ice();
	Ice(const Ice &i);
	Ice &operator = (const Ice &i);
	~Ice();

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

class Cure : virtual public AMateria {

public:
	Cure();
	Cure(const Cure &c);
	Cure &operator = (const Cure &c);
	~Cure();

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
