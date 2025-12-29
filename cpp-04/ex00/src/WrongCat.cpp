#include "../includes/WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(void): WrongAnimal()
{
    
    std::cout << "WrongCat default constructor called" << std::endl;
    return ;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    
    return ;
}

// Assignment operator overload
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat assignment operator called" << std::endl;
    (void) other;
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
    std::cout << this->getType() << " says: 'Wrong cat weom'\n";
}