#include "./Fixed.hpp"
#include "Fixed.hpp"

const int Fixed::fracts = 8;

Fixed::Fixed(): fixed(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed	&Fixed::operator=(const Fixed &given)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &given)
		this->fixed = given.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed = raw;
}
