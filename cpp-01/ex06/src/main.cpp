#include "../includes/Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Usage: ./ex06 <level>\n";
		return (1);
	}
	harl.complain(argv[1]);
}