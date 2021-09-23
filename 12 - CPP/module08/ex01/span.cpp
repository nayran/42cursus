#include "span.hpp"

Span::Span()
{
	N = 0;
	addqtd = 0;
}

Span::Span(unsigned int n)
{
	N = n;
	addqtd = 0;
	lst = std::list<unsigned int>(n, 0);
}

Span::Span(const Span &s)
{
	this->N = s.N;
	this->lst = s.lst;
}

Span &Span::operator = (const Span &s)
{
	Span *tmp = new Span();
	tmp->N = s.N;
	tmp->lst = s.lst;
	return (*tmp);
}

Span::~Span()
{}

void			Span::addNumber(unsigned int num)
{
	try
	{
		if (addqtd < N)
		{
			std::list<unsigned int>::const_iterator it;
			std::list<unsigned int>::const_iterator ite = lst.end();
			for (it = lst.begin(); it != ite; it++)
			{
				if (num != 0 && *it == num)
					throw Span::AlreadyStoredException();
			}
			lst.push_back(num);
			lst.pop_front();
			addqtd++;
			std::cout << num << " added!" << std::endl;
		}
		else
			throw NoSpaceException();
	}
    catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void			Span::addNumber(unsigned int num, unsigned int it)
{
	int n = num;
	if (it - num >= N)
		throw NoSpaceException();
	try
	{
		if (addqtd < N)
		{
			for (unsigned int x = 0; x <= it; x++)
			{
				lst.push_back(n);
				lst.pop_front();
				n++;
			}
			std::cout << "Range " << num << " to " << it << " added!" << std::endl;
			addqtd = it + 1;
		}
		else
			throw NoSpaceException();
	}
    catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::list<unsigned int>	&Span::getList()
{
	rm(lst, addqtd, N);
	return (lst);
}

unsigned int	Span::shortestSpan()
{
	rm(lst, addqtd, N);
	if (lst.size() < 2)
		throw NotSpanException();
	lst.sort();
	return (lst.front());
}

unsigned int	Span::longestSpan()
{
	rm(lst, addqtd, N);
	if (lst.size() < 2)
		throw NotSpanException();
	lst.sort();
	return (lst.back());
}
