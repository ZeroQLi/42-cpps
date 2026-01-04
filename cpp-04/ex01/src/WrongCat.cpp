#include "../includes/WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(void): WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "wrong cat";
	return ;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other): WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

// Destructor
WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

void WrongCat::makeSound(void) const
{
	std::cout << this->getType() << " says: 'Wrong cat meowww'\n";
}