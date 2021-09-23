#include "AnimalClass.hpp"
#include "WrongAnimalClass.hpp"

int main()
{
	const Animal* j = new Dog();
    const Animal* i = new Cat();
	
	std::cout << std::endl;
    delete j;//should not create a leak
	delete i;
	/*
	const Animal *a[4];
	a[0] = new Dog();
	a[1] = new Dog();
	a[2] = new Cat();
	a[3] = new Cat();
	for(int x = 0; x < 4; x++)
		delete a[x];
	*/
	return (0);
}
