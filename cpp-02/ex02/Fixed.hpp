#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixed;
		static const int	fract;
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		~Fixed();

		Fixed(const int num);
		Fixed(const float decimal);

		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed &min		(Fixed &num1, Fixed &num2);
		static Fixed &max		(Fixed &num1, Fixed &num2);
		static const Fixed &min	(const Fixed &num1,const Fixed &num2);
		static const Fixed &max	(const Fixed &num1, const Fixed &num2);

		Fixed	&operator=(const Fixed &other);

		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		float	operator+(const Fixed &other) const;
		float	operator-(const Fixed &other) const;
		float	operator*(const Fixed &other) const;
		float	operator/(const Fixed &other) const;

		Fixed	operator++(void);
		Fixed	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &num);