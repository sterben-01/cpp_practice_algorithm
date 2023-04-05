#include "miku.h"

Miku::Miku()
{
	std::cout << "Miku()" << std::endl;
}

Miku::~Miku()
{
	std::cout << "~Miku()" << std::endl;
}

void Miku::show()
{
	std::cout << "Hello, I'm Miku" << std::endl;
}