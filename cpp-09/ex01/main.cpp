#include <iostream>

#include "./RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN (expression)" << std::endl;
		return (1);
	}
	else
	{
		try
		{
			RPN calculator;

			calculator.calc(argv[1]);
			std::cout << calculator.getResult() << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << "ERROR: " << e.what() << '\n';
		}
	}
}