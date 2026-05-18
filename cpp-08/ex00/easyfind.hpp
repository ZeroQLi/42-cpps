#pragma once

# include <algorithm>
# include <iostream>
# include <exception>

class NotFoundException: public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Value not found");
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int to_find);

# include "easyfind.tpp"