#include "IMateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int x = 0; x < 4; x++)
		exists[x] = 0;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &ms)
{
	*this = ms;
}

MateriaSource &MateriaSource::operator = (const MateriaSource &ms)
{
	if (this == &ms)
		return (*this);
	for (int x = 0; x < 4; x++)
	{
		if (exists[x])
			delete materia[x];
		materia[x] = ms.materia[x]->clone();
		exists[x] = ms.exists[x];
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	return;
}

void MateriaSource::learnMateria(AMateria *am)
{
	for (int x = 0; x < 4; ++x)
	{
		if (!exists[x])
		{
			materia[x] = am->clone();
			exists[x] = 1;
			break;
		}
	}
}

int		ft_typecmp(std::string string, std::string string2)
{
	int x;
	std::string s1;
	std::string s2;

	x = 0;
	s1 = string;
	s2 = string2;
	while (s1[x] && s2[x])
	{
		if (s1[x] >= 65  && s1[x] <= 90)
			s1[x] += 32;
		if (s2[x] >= 65  && s2[x] <= 90)
			s2[x] += 32;
		if (s1[x] != s2[x])
			return (0);
		x++;
	}
	return (1);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int x = 0; x < 4; ++x)
	{
		if (exists[x] && ft_typecmp(materia[x]->getType(), type))
			return (materia[x]->clone());
	}
	return (NULL);
}

