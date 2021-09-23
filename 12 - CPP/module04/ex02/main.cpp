#include "AnimalClass.hpp"
#include "WrongAnimalClass.hpp"

int main()
{
	//const Animal *a = new Animal();
	const Animal* j = new Dog();
    const Animal* i = new Cat();
	
	std::cout << std::endl;
	//delete a;
    delete j;	//should not create a leak
	delete i;
	return (0);
}
