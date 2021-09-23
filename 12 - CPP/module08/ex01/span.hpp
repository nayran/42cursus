#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <list>

class Span{

private:
	unsigned int	N;
	unsigned int	addqtd;
	std::list <unsigned int> lst;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &s);
	Span &operator = (const Span &s);
	~Span();

	std::list<unsigned int>	&getList();
	void			addNumber(unsigned int n);
	void			addNumber(unsigned int num, unsigned int it);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	class AlreadyStoredException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Exception: Number already stored!");
			}
	};
	class NoSpaceException: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Exception: List is full!");
			}
	};
	class NotSpanException: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Exception: Not span!");
			}
	};
};

template <template <typename, typename> class T>
void	print(T <unsigned int, std::allocator<unsigned int> > &lst)
{
	std::list<unsigned int>::const_iterator it;
	std::list<unsigned int>::const_iterator ite = lst.end();
	std::cout << "List: ";
	for (it = lst.begin(); it != ite; it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

template <template <typename, typename> class T>
void	rm(T <unsigned int, std::allocator<unsigned int> > &lst, unsigned int qtd, unsigned int n)
{
	while (n - qtd > 0)
	{
		lst.pop_front();
		qtd++;
	}
}

#endif
