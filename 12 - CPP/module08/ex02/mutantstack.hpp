#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
private:

public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack<T>();
	MutantStack( MutantStack<T> const & ms);
	MutantStack<T> 	&operator=( MutantStack<T> const & ms);
	virtual ~MutantStack<T>();
	
	iterator		begin(void);
	iterator		end(void);
};

#include "mutantstack.cpp"

#endif
