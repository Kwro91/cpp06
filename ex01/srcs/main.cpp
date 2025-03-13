#include "../includes/Serializer.hpp"

int main ()
{
	try{
		Data d1(0, "TestName");
		std::cout << GREEN << d1 << YELLOW <<  " adress: " << &d1 << WHITE << std::endl;
		uintptr_t raw = Serializer::serialize(&d1);
		std::cout << GREEN << "raw uintptr_t: " << ROSE << raw << YELLOW << " adress : " << &raw << WHITE << std::endl;
		Data *d2 = Serializer::deserialize(raw);
		std::cout << GREEN << *d2 << YELLOW << " adress : " << d2 <<  WHITE << std::endl;
		std::cout << "///////////////////////////////" << std::endl;
		Data d3(-1, "Negative");
		std::cout << GREEN << d3 << YELLOW <<  " adress: " << &d3 << WHITE << std::endl;
		raw = Serializer::serialize(&d3);
		std::cout << GREEN << "raw uintptr_t: " << ROSE << raw << YELLOW << " adress : " << &raw << WHITE << std::endl;
		Data *d4 = Serializer::deserialize(raw);
		std::cout << GREEN << *d4 << YELLOW << " adress : " << d4 <<  WHITE << std::endl;

	}catch (const std::exception &e){
		std::cerr << YELLOW << e.what() << WHITE << std::endl;
	}
	return (0);
}