#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <time.h>
# include <stdlib.h>
template <typename T>
class Array
{
	private:
		T				*arr;
		unsigned int	_size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &other);
		~Array();

		Array	&operator=(const Array &other);
		T		&operator[](unsigned int i);
		T		const &operator[](unsigned int i) const;

		unsigned int	size() const;

		class OutOfBoundsException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
# include "Array.tpp"
#endif

