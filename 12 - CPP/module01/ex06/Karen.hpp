#ifndef KAREN_HPP 
# define KAREN_HPP

#include <iostream>
#include <string.h>

class Karen{

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	panic(void);

public:
	void complain( std::string level );
	Karen(void);
	~Karen(void);
};

#endif
