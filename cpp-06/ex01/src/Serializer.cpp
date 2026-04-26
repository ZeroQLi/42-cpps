#include "../includes/Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	(void) other;
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void) other;
	std::cout << "Serializer default constructor called" << std::endl;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer default constructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
