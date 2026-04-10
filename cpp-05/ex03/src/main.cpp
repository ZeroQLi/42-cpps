#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int	main(void)
{
	Intern	intern1;
	Intern	intern2;
	Intern	intern3;
	Intern	intern4;
	std::cout << std::endl;

	Bureaucrat boss("Super", 1);
	Bureaucrat manager("John", 6);
	std::cout << std::endl;

	AForm *shrub = intern1.makeForm("ShrubberyCreationForm", "garden");
	AForm *robot = intern2.makeForm("RobotomyRequestForm", "marvin");
	AForm *pardon = intern3.makeForm("PresidentialPardonForm", "Al Capone");
	AForm *fake = intern4.makeForm("fakeForm", "faker");

	if (shrub)
	{
		manager.signForm(*shrub);
		manager.executeForm(*shrub);
		delete shrub;
	}
	std::cout << std::endl;
	if (robot)
	{
		manager.signForm(*robot);
		manager.executeForm(*robot);
		delete robot;
	}
	std::cout << std::endl;
	if (pardon)
	{
		manager.signForm(*pardon);
		manager.executeForm(*pardon);
		boss.executeForm(*pardon);
		delete pardon;
	}
	std::cout << std::endl;
	if (fake)
	{
		boss.executeForm(*fake);
		boss.executeForm(*fake);
	}

	return 0;
}