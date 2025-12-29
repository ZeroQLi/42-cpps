#include "../includes/Dog.hpp"

// Default constructor
Dog::Dog(void): Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	return ;
}

// Copy constructor
Dog::Dog(const Dog &other): Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	return ;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

// Destructor
Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
    return ;
}

void Dog::makeSound() const
{
	std::cout << this->getType() << " says: WOOF WOOF\n";
}
