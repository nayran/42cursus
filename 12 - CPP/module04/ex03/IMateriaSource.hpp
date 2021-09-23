#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {

public:
	virtual ~IMateriaSource() {};
	virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : virtual public IMateriaSource {

private:
	AMateria	*materia[4];
	int			exists[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &obj);
	MateriaSource &operator = (const MateriaSource &obj);
	virtual ~MateriaSource();

	virtual void learnMateria(AMateria *m);
	virtual AMateria* createMateria(std::string const & type);
};

#endif
