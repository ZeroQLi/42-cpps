#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename Tarray, typename Tfunction>
void iter(Tarray *arr, const size_t len, Tfunction func)
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif