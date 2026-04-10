#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

// Default constructor
Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator overload
Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	return (*this);
}

// Setters
static AForm *pardonPresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *robotimize(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *growShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string form, const std::string target)
{
	AForm *(*allForms[])(const std::string target) = {&pardonPresident, &growShrubbery, &robotimize};
	std::string forms[] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};
	for (int i = 0; i < 3 ; i++)
	{
		if (forms[i] == form)
		{
			std::cout << "Intern creating Form '" << form << "'.\n";
			return (allForms[i](target));
		}
	}
	std::cout << "Intern failed to create Form '" << form << "'. Intern terminated\n";
	return (NULL);
}
// Destructor
Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

