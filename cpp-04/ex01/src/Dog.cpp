#include "../includes/Dog.hpp"

// Default constructor
Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
	return;
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain);
	return;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

// Destructor
Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
	return;
}

void Dog::makeSound() const
{
	std::cout << this->getType() << " says: WOOF WOOF\n";
}

void Dog::setIdea(unsigned int index, const std::string &idea)
{
	if (index >= 100)
	{
		std::cout << "Error: out of bounds (1-100)" << std::endl;
		return;
	}
	this->brain->setIdea(index, idea);
}
std::string Dog::getIdea(unsigned int index) const
{
	if (index >= 100)
	{
		return ("Error: out of bounds (1-100)\n");
	}
	return this->brain->getIdea(index);
}