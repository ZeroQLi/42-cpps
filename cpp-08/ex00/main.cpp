#include "easyfind.hpp"
#include <list>
#include <vector>

int main(void)
{
	std::vector<int> numbers;
	std::list<int> values;
	std::vector<int>::iterator vector_it;
	std::list<int>::iterator list_it;

	numbers.push_back(1);
	numbers.push_back(3);
	numbers.push_back(5);
	numbers.push_back(7);

	values.push_back(2);
	values.push_back(4);
	values.push_back(6);
	values.push_back(8);

	try
	{
		vector_it = easyfind(numbers, 5);
		std::cout << "vector: found " << *vector_it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "vector: " << e.what() << std::endl;
	}

	try
	{
		vector_it = easyfind(numbers, 42);
		std::cout << "vector: found " << *vector_it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "vector: " << e.what() << std::endl;
	}

	try
	{
		list_it = easyfind(values, 6);
		std::cout << "list: found " << *list_it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "list: " << e.what() << std::endl;
	}

	try
	{
		list_it = easyfind(values, 13);
		std::cout << "list: found " << *list_it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "list: " << e.what() << std::endl;
	}

	return (0);
}