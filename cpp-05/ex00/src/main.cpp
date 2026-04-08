#include "../includes/Bureaucrat.hpp"

int main(void)
{
	Bureaucrat defaultBureaucrat;
	Bureaucrat namedBureaucrat("Alice");
	Bureaucrat gradedBureaucrat(149);
	Bureaucrat fullBureaucrat("Alan", 2);
	Bureaucrat b1("bento", 50);
	Bureaucrat b2 = b1; // copy constructor
	Bureaucrat b3("bepop", 75);
	b3 = b1; // assignment operator

	try
	{
		Bureaucrat falseBureaucrat("Rebel", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << defaultBureaucrat << std::endl << std::endl;

	std::cout << namedBureaucrat << std::endl;
	namedBureaucrat.incrementGrade();
	namedBureaucrat.incrementGrade();
	std::cout << namedBureaucrat << std::endl;
	namedBureaucrat.decrementGrade();
	std::cout << namedBureaucrat << std::endl << std::endl;

	std::cout << gradedBureaucrat << std::endl;
	try
	{
		gradedBureaucrat.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << '\n';
	}
	std::cout << gradedBureaucrat << std::endl;
	try
	{
		gradedBureaucrat.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "ERROR: " << e.what() << '\n';
	}
	std::cout << gradedBureaucrat << std::endl << std::endl;

	std::cout << fullBureaucrat << std::endl;
	try
	{
		fullBureaucrat.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << '\n';
	}
	std::cout << fullBureaucrat << std::endl;
	try
	{
		fullBureaucrat.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "ERROR: " << e.what() << '\n';
	}
	std::cout << fullBureaucrat << std::endl << std::endl;
}