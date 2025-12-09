#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
ScavTrap::~ScavTrap(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

