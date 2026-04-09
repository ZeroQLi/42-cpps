#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int	main(void)
{
	ShrubberyCreationForm normal("home");
	Bureaucrat subject("Bob", 146);

	std::cout << normal << std::endl << subject << std::endl;
	subject.executeForm(normal);
	std::cout << std::endl;

	subject.signForm(normal);
	subject.incrementGrade();
	subject.signForm(normal);

	subject.executeForm(normal);
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
		subject.incrementGrade();
	std::cout << subject << std::endl;

	subject.executeForm(normal);

	std::cout << std::endl;

	Bureaucrat	dummy("spoon", 20);
	RobotomyRequestForm robot("potato");
	std::cout << dummy << std::endl << robot << std::endl;

	dummy.signForm(robot);

	std::cout << std::endl;
	dummy.executeForm(robot);
	dummy.executeForm(robot);
	dummy.executeForm(robot);
	std::cout << std::endl;

	Bureaucrat criminal("dexter", 2);
	PresidentialPardonForm contract("joker");
	std::cout << criminal << std::endl
			  << contract << std::endl;

	criminal.signForm(contract);

	std::cout << std::endl;
	criminal.executeForm(contract);
	std::cout << "\n\n";
	
	return 0;
}