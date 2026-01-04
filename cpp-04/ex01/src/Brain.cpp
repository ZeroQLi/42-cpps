#include "../includes/Brain.hpp"

// Default constructor
Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

// Copy constructor
Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		std::copy(other.ideas, other.ideas + 100, this->ideas);
	}
	return (*this);
}

// Destructor
Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
    return ;
}

void Brain::setIdea(unsigned int index, const std::string& idea)
{
	if (index >= 100)
	{
		std::cout << "Error: out of bounds (1-100)" << std::endl;
		return ;
	}
	this->ideas[index] = idea;
}

std::string Brain::getIdea(unsigned int index) const
{
	if (index >= 100)
	{
		return ("Error: out of bounds (1-100)\n");
	}
	return this->ideas[index];
}