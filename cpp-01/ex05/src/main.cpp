#include "../includes/Harl.hpp"

int main(void)
{
	Harl	problem;

	problem.complain("ERROR");
	problem.complain("WARNING");
	problem.complain("DEBUG");
	problem.complain("INFO");
	problem.complain("nonexistant");
}