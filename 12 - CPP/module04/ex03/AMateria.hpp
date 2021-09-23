#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string.h>

class ICharacter;
class IMateriaSource;

class AMateria {

protected:
	std::string Type;

public:
	AMateria(std::string const & type);
	AMateria();
	virtual ~AMateria();

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

#endif
