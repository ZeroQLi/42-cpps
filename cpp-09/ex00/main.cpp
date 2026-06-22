#include <iostream>
#include <fstream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./bitcoin [file]" << std::endl;
		return (1);
	}
	else
	{
		BitcoinExchange exchange;
		try
		{
			exchange.readInput(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << "ERROR: " << e.what() << '\n';
		}
	}
}