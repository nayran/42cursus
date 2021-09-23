#include "Array.hpp"

int main()
{
	Array<int> a(5);
	Array<int> b(1);
	
	std::cout << "a: ";
	for(int x = 0; x < 5; x++)
		a[x] = x;
	for(int x = 0; x < 5; x++)
		std::cout << a[x] << " ";
	b[0] = 4;
	Array<int> c(b);
	c[0] = 6;
	std::cout << "\nb: " << b[0] << "\nc: " << c[0] << std::endl;
	try
	{
		a[7] = 0;
	}
    catch(const std::exception& e)
	{
        std::cout << e.what() << '\n';
	}
    return 0;
}
