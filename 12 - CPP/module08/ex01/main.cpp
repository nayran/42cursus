#include "span.hpp"

void	print(int x)
{
	std::cout << x << " ";
}

int main()
{
	try
	{
		Span ns = Span(1);
		ns.addNumber(0);
		print(ns.getList());
		std::cout << "Shortest span: " << ns.shortestSpan() << std::endl;
		std::cout << "Longest span: " << ns.longestSpan() << std::endl;
	}
    catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	Span sp = Span(7);
	sp.addNumber(3);
	sp.addNumber(5);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(3);
	sp.addNumber(11);
	sp.addNumber(0);
	sp.addNumber(13);
	sp.addNumber(14);
	print(sp.getList());
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	try
	{
		Span s = Span(10001);
		s.addNumber(0, 10000);
		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	}
    catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
