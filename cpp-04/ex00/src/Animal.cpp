#include "../includes/Animal.hpp"

// Default constructor
Animal::Animal(void): type("default")
{
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

// Copy constructor
Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

// Destructor
Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << this->getType() << " says: 'I'm default, make me special'\n";
}
