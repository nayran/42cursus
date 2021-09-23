#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
 
template<class T>
class Array {

private:
	T	*array;
	int	len;

public:
	Array()
	{
		array = new T[1];
		len = 0;
	}
	Array(unsigned int n)
	{
		array = new T[n];
		len = n;
	}
	Array(const Array &a)
	{
		this->array = new T[a.size()];
		for (int x = 0; x < a.size(); x++)
			this->array[x] = a.array[x];
		this->len = a.size();
	}
	Array &operator = (const Array &a)
	{
		Array *tmp = new Array();
		for (int x = 0; x < a.size(); x++)
			tmp->array[x] = a.array[x];
		tmp->len = a.size();
		return (*tmp);
	}
	~Array()
	{
	}
	T &operator [] (unsigned int n)
	{
		if (static_cast<int>(n) > size() || n < 0)
			throw std::exception();
		return (array[n]);
	}
	int	size() const
	{
		return (len);
	}
};


#endif
