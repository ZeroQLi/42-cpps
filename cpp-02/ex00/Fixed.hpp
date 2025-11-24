#pragma once

#include <iostream>

class Fixed
{
	private:
		int					fixed;
		static const int	fracts;

	public:
		Fixed(void);
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed	&operator=(const Fixed &given);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};


