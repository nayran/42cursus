#include "Serialization.hpp"

int main()
{
	Data *ptr = new Data();
	Data *aux= new Data();
	uintptr_t raw;

	ptr->s = "teste";
	std::cout << "ptr->s: " << ptr->s << std::endl;
	std::cout << std::endl;

	raw = serialize(ptr);
	std::cout << "ptr->s to raw: " << raw << std::endl;
	std::cout << std::endl;

	aux = deserialize(raw);
	std::cout << "raw to aux: " << aux->s << std::endl;
	std::cout << "ptr->s: " << ptr->s << std::endl;
	return (0);
}
