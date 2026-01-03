#include "../includes/WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal(void): type("wrong default")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "wrongAnimal copy constructor called" << std::endl;
	*this = other;
    return ;
}

// Assignment operator overload
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "wrongAnimal assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "wrongAnimal destructor called" << std::endl;
	return ;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << this->getType() << "says: 'Wrong animal duh'\n";
}
