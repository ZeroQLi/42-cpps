#include <iostream>
#include <fstream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc [file]" << std::endl;
		return (1);
	}
	else
	{
		try
		{
			BitcoinExchange exchange;
			exchange.readInput(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << "ERROR: " << e.what() << '\n';
			return (1);
		}
	}
}