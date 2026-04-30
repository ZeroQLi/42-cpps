#include "./Array.hpp"
# include <string>

int main(void)
{
	Array<int> emptyArray;
	std::cout << emptyArray.size() << std::endl;
	try
	{
		std::cout << emptyArray[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << std::endl;
	Array<double> doubleArrs(5);
	std::cout << doubleArrs.size() << std::endl;
	for (size_t i = 0; i < 5; i++)
	{
		doubleArrs[i] = i * 2.5;
		std::cout << "index " << i << ": " << doubleArrs[i] << "\n";
	}

	Array<float> floatArrs(6);
	for (size_t i = 0; i < 6; i++)
	{
		try
		{
			floatArrs[i] = static_cast<float>(doubleArrs[i]);
			std::cout << floatArrs[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	const int num = 3;
	std::cout << std::endl << floatArrs[num] << std::endl;
}