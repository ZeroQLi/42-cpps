#include "./Fixed.hpp"

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

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	fixed = num << this->fracts;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	this->fixed = roundf(num * (1 << this->fracts));
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

std::ostream	&operator<<(std::ostream &output, const Fixed &fix)
{
	output << fix.toFloat();
	return (output);
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float) this->fixed / (float) (1 << this->fracts));
}

int		Fixed::toInt(void) const
{
	return (this->fixed >> this->fracts);
}