#ifndef ICHARACTER_HPP 
# define ICHARACTER_HPP 

#include "AMateria.hpp"

class ICharacter {

public:
	virtual ~ICharacter() {};
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

class Character : virtual public ICharacter {

private:
	std::string Name;
	int			inventory[4];
	AMateria	*materia[4];

public:
	Character();
	Character(std::string const &name);
	Character(const Character &cha);
	Character &operator = (const Character &cha);
	virtual ~Character();

	virtual std::string const & getName() const;
	virtual void equip(AMateria* am);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif
