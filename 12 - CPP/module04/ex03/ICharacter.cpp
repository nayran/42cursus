#include "ICharacter.hpp"

Character::Character()
{
	for (int x = 0; x < 4; x++)
	{
		inventory[x] = 0;
	}
	return ;
}

Character::Character(std::string const &name)
{
	Character::Name = name;
}

Character::Character(const Character &cha)
{
	*this = cha;
}

Character &Character::operator = (const Character &cha)
{
	Character *tmp = new Character();
	tmp->Name = cha.Name;
	for (int x = 0; x < 4; x++)
		tmp->inventory[x] = cha.inventory[x];
	for (int x = 0; x < 4; x++)
		tmp->materia[x] = cha.materia[x];
	return (*tmp);
}

Character::~Character()
{
	for (int x = 0; x < 4; x++)
	{
		if (materia[x])
			delete materia[x];
	}
	return;
}

std::string const & Character::getName() const
{
	return (Character::Name);
}

void Character::equip(AMateria* am)
{
	if (!am)
		return;
	for (int x = 0; x < 4; x++)
	{
		if (!inventory[x])
		{
			if (materia[x])
				delete materia[x];
			materia[x] = am->clone();
			inventory[x] = 1;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return;
	if (inventory[idx])
		inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !inventory[idx])
		return;
	materia[idx]->use(target);
}
