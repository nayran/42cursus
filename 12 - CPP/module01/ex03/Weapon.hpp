#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string.h>

class Weapon{

private:
	std::string		type;

public:
	std::string const &getType(void);
	void setType(std::string const &type);
	Weapon(std::string const &type);
	~Weapon(void);
};

#endif
