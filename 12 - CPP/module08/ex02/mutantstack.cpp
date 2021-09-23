#ifndef MUTANTSTACK_CPP
#define MUTANTSTACK_CPP

#include "mutantstack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
{}

template<typename T>
MutantStack<T>::MutantStack( MutantStack<T> const & ms)
{
	*this = ms;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=( MutantStack<T> const & ms)
{
	MutantStack<T> *tmp;
	tmp->iterator = ms.iterator;
	return (tmp);
}

template<typename T>
MutantStack<T>::~MutantStack()
{}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return(MutantStack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator		MutantStack<T>::end(void)
{
	return(MutantStack<T>::c.end());
}

#endif

//https://en.cppreference.com/w/cpp/container/stack
