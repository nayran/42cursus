#include <iostream>

/*
 *	Stack
 *	Zombie z = Zombie(name);
 *	
 *	Heap // Dynamic
 *	Zombie *z = new Zombie(name);
 *
 *	Pointer: makes a copy to another address, don't modify the original
 *	   x 
 *	Reference: uses the same address, modifying the original
 */

int main()
{
	// Pointer
	int *ptr;
	int *ptr2;
	int x = 1;
	int y = 2;

	ptr = new int;
	*ptr = x;
	ptr2 = &y;
	std::cout << "ptr: " << *ptr << "\tx: " << x << std::endl;
	std::cout << "ptr2: " << *ptr2 << "\ty: " << y << std::endl;

	*ptr += 1;
	*ptr2 += 1;
	std::cout << "*ptr++ *ptr2++" << std::endl;
	std::cout << "ptr: " << *ptr << "\tx: " << x << std::endl;
	std::cout << "ptr2: " << *ptr2 << "\ty: " << y << std::endl;

	std::cout << "Address" << std::endl;
	std::cout << ptr << "\t" << ptr2 << std::endl;
	delete ptr;
}
