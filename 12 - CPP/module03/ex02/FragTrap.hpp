#ifndef FRAGTRAP_HPP 
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{

private:

public:
	FragTrap(void);
	FragTrap(const FragTrap &ft);
	FragTrap& operator = (const FragTrap &ft);
	~FragTrap(void);

	FragTrap(std::string Name);
	void highFivesGuys(void);
};

#endif
