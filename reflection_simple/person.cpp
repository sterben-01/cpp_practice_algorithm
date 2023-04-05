#include "person.h"

Person::Person()
{
	std::cout << "Person()" << std::endl;
}


Person::~Person()
{
	std::cout << "~Person()" << std::endl;
}

void Person::show()
{
	std::cout << "Hello, I'm person" << std::endl;
}