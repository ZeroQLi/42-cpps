#pragma once

template <typename T>
Array<T>::Array(void): arr(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n): arr(new T[n]), _size(n)
{}

template <typename T>
Array<T>::Array(const Array &other): arr(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		arr[i] = other.arr[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] arr;
		arr = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++)
			arr[i] = other.arr[i];
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutOfBoundsException();
	return (arr[i]);
}

template <typename T>
T const	&Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw OutOfBoundsException();
	return (arr[i]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index out of bounds");
}
