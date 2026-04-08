#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
	Bureaucrat signer("Alice", 10);
	Form form("A16Z", 50, 25);

	std::cout << signer << std::endl;
	std::cout << form << std::endl;

	signer.signForm(form);
	std::cout << form << std::endl;
}