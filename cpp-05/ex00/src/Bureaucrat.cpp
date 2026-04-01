#include "../includes/Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat(void)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
    return ;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
    return ;
}

