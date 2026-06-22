#include "RPN.hpp"

// Default constructor
RPN::RPN(void)
{
    std::cout << "RPN default constructor called" << std::endl;
    return ;
}

// Copy constructor
RPN::RPN(const RPN &other)
{
    std::cout << "RPN copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
RPN &RPN::operator=(const RPN &other)
{
    std::cout << "RPN assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
RPN::~RPN(void)
{
    std::cout << "RPN destructor called" << std::endl;
    return ;
}

