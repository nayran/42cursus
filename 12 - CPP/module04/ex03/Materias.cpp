#include "Materias.hpp"

Ice::Ice() : AMateria("Ice")
{
	return ;
}

Ice::~Ice ()
{
	return;
}

Ice::Ice(const Ice &i) : AMateria(i.getType()) {}

Ice &Ice::operator = (const Ice &i)
{
	(void)i;
	return (*this);
}

AMateria* Ice::clone() const
{
	Ice	*tmp = new Ice(*this);
	return (tmp);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}

Cure::Cure() : AMateria("Cure")
{
	return ;
}

Cure::~Cure ()
{
	return;
}

Cure::Cure(const Cure &c) : AMateria(c.getType()) {}

Cure &Cure::operator = (const Cure &c)
{
	(void)c;
	return (*this);
}

AMateria* Cure::clone() const
{
	Cure *tmp = new Cure(*this);
	return (tmp);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	AMateria::use(target);
}
