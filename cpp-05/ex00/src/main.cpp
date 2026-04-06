#include "../includes/Bureaucrat.hpp"

int main(void)
{
	Bureaucrat defaultBureaucrat;
	Bureaucrat namedBureaucrat("Alice");
	Bureaucrat gradedBureaucrat(149);
	Bureaucrat fullBureaucrat("Alan", 2);
	Bureaucrat falseBureaucrat("Rebel", 200);

	std::cout << std::endl;
	std::cout << fullBureaucrat << std::endl;

	fullBureaucrat.incrementGrade();
	std::cout << fullBureaucrat << std::endl;

	fullBureaucrat.incrementGrade();
	std::cout << std::endl << std::endl;

	std::cout << gradedBureaucrat << std::endl;

	gradedBureaucrat.decrementGrade();
	std::cout << gradedBureaucrat << std::endl;

	gradedBureaucrat.decrementGrade();
	std::cout << std::endl;
}