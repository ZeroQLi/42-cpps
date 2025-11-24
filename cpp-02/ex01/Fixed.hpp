#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixed;
		static const int	fracts;

	public:
		Fixed(void);
		Fixed(const Fixed& copy);
		Fixed	&operator=(const Fixed &given);
		~Fixed();

		Fixed(const int num);
		Fixed(const float num);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &output, const Fixed &fix);