#include "../includes/Cat.hpp"

// Default constructor
Cat::Cat(): Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
	return ;
}

// Copy constructor
Cat::Cat(const Cat &other): Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain);
	return ;
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

// Destructor
Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

void Cat::makeSound() const
{
	std::cout << this->getType() << " says: MEOW MEOW MEOW MEOWWWWWWWWW\n";
}

void Cat::setIdea(unsigned int index, const std::string& idea)
{
	if (index >= 100)
	{
		std::cout << "Error: out of bounds (1-100)" << std::endl;
		return ;
	}
	this->brain->setIdea(index, idea);
}
std::string Cat::getIdea(unsigned int index) const
{
	if (index >= 100)
	{
		return ("Error: out of bounds (1-100)\n");
	}
	return this->brain->getIdea(index);
}