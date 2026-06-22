#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN (expression)" << std::endl;
		return (1);
	}
	else
	{
		std::cout << argv[1];
	}
}