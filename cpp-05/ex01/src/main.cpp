#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int	main(void)
{
	Bureaucrat signer("Alice", 10);
	Bureaucrat failure("Janice", 51);
	Form form("A16Z", 50, 25);
	Form contract;

	std::cout << signer << std::endl;

	std::cout << std::endl;
	std::cout << form << std::endl;
	signer.signForm(form);
	std::cout << form << std::endl;
	signer.signForm(form);
	std::cout << std::endl;

	std::cout << failure << std::endl << contract << std::endl;
	failure.signForm(contract);
	failure.incrementGrade();
	failure.signForm(contract);
	std::cout << failure << std::endl << contract << "\n\n";

	try
	{
		Form failed(-1, 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Form creation failed. " << e.what() << '\n';
	}
	std::cout << std::endl;
}