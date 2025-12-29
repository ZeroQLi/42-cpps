#include "../includes/Cat.hpp"

// Default constructor
Cat::Cat(): Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	return ;
}

// Copy constructor
Cat::Cat(const Cat &other): Animal(other)
{
	std::cout << "cat copy constructor called" << std::endl;
	return ;
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "cat assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

// Destructor
Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

void Cat::makeSound() const
{
	std::cout<< this->getType() << " says: MEOW MEOW MEOW MEOWWWWWWWWW\n";
}
