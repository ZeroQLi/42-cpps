#pragma once

# include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int to_find)
{
	typename T::iterator result;

	result = std::find(container.begin(), container.end(), to_find);
	if (result == container.end())
		throw NotFoundException();
	return (result);
}
