#include "animal.h"

Animal::Animal()
{
	std::cout << "Animal()" << std::endl;
}


Animal::~Animal()
{
	std::cout << "~Animal()" << std::endl;
}

void Animal::bark()
{
	std::cout << "animal bark" << std::endl;
}