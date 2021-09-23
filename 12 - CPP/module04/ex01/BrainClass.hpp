#ifndef BRAINCLASS_HPP 
# define BRAINCLASS_HPP

#include <iostream>
#include <string.h>

class Brain{

private:
	std::string ideas[100];

public: 
	Brain(void);
	Brain(const Brain &b);
	Brain& operator = (const Brain &b);
	virtual ~Brain(void);
};

#endif
