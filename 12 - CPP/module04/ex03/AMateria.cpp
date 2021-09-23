#include "AMateria.hpp"

AMateria::AMateria (std::string const &type)
{
	AMateria::Type = type;
	return ;
}

AMateria::~AMateria ()
{
	return;
}

std::string const &AMateria::getType() const
{
	return (AMateria::Type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
