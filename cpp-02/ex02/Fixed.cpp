#include "Fixed.hpp"

const int Fixed::fract = 8;

Fixed::Fixed(void): fixed(0)
{
	return ;
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
	return ;
}

Fixed::Fixed(const int num)
{
	this->fixed = num << this->fract;
}

Fixed::Fixed(const float num)
{
	this->fixed = roundf(num * (1 << this->fract));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->fixed = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	return ;
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed = raw;
}

int	Fixed::toInt(void) const
{
	return (this->fixed >> this->fract);
}

float	Fixed::toFloat(void) const
{
	return ((float) this->fixed / (float) (1 << this->fract));
}

Fixed	&Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1.toFloat() <= num2.toFloat())
		return (num1);
	return (num2);
}

const Fixed	&Fixed::max(Fixed const &num1, Fixed const &num2)
{
	if (num1.toFloat() >= num2.toFloat())
		return (num1);
	return (num2);
}

const Fixed	&Fixed::min(Fixed const &num1, Fixed const &num2)
{
	if (num1.toFloat() <= num2.toFloat())
		return (num1);
	return (num2);
}

Fixed	&Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1.toFloat() >= num2.toFloat())
		return (num1);
	return (num2);
}

std::ostream	&operator<<(std::ostream &stream, const Fixed &num)
{
	stream << num.toFloat();
	return (stream);
}

// all overloaded assignment operators
bool	Fixed::operator>(const Fixed &other) const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->toFloat() != other.toFloat());
}

// all overloaded arthimetic operators
float	Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

float	Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

float	Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

float	Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}

//all overloaded pre increment/decrement operators
Fixed	Fixed::operator++(void)
{
	this->fixed++;
	return (*this);
}

Fixed	Fixed::operator--(void)
{
	this->fixed--;
	return (*this);
}

// all overloaded post increment/decrement operators
Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->fixed;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->fixed;
	return (tmp);
}