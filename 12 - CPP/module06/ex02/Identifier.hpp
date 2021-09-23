#ifndef IDENTIFIER_HPP
# define IDENTIFIER_HPP

#include <iostream>
#include <string>

class Base
{

public:
	virtual ~Base();

};
class A : virtual public Base {};
class B : virtual public Base {};
class C : virtual public Base {};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

class CastException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Exception: casting is not possible!");
		}
};

#endif
