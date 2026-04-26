#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	int random = std::rand() % 3;
	switch (random)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			break;
	}
	return (0);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A\n";
	}
	catch(const std::exception& e){}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B\n";
	}
	catch(const std::exception& e){}
	try
	{		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C\n";
	}
	catch(const std::exception& e){}
}

int main(void)
{
	std::srand(std::time(0));
	Base *base = generate();
	Base &ref = *base;

	identify(base);
	identify(ref);
	delete base;
}