#include "Span.hpp"

// Default constructor
Span::Span(void): s(0)
{
}

Span::Span(unsigned int N): s(N)
{
}

// Copy constructor
Span::Span(const Span &other)
{
	(*this) = other;
}

// Assignment operator overload
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		arr = other.arr;
		s = other.s;
	}
	return (*this);
}

// Destructor
Span::~Span(void)
{
}

void Span::addNumber(int n)
{
	if (arr.size() >= s)
		throw OverflowException();
	arr.push_back(n);
}

void Span::addNumber(const std::vector<int>::iterator &it1, const std::vector<int>::iterator &it2)
{
	if (arr.size() + std::distance(it1, it2) > s)
		throw OverflowException();
	arr.insert(arr.end(), it1, it2);
}

int	Span::shortestSpan()
{
	if (arr.size() <= 1)
		throw InvalidAmountException();
	std::vector<int> tmp = arr;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (int i = 1; i < static_cast<int>(tmp.size()) - 1; i++)
	{
		if (tmp[i+1] - tmp[i] <= min)
			min = tmp[i+1] - tmp[i];
	}
	return (min);
}

int Span::longestSpan()
{
	if (arr.size() <= 1)
		throw InvalidAmountException();
	std::vector<int> tmp = arr;
	std::sort(tmp.begin(), tmp.end());
	int max = tmp[tmp.size() - 1] - tmp[0];
	return (max);
}

const char *Span::OverflowException::what() const throw()
{
	return ("Container Overflow");
}

const char *Span::InvalidAmountException::what() const throw()
{
	return ("Invalid amount of numbers in container");
}