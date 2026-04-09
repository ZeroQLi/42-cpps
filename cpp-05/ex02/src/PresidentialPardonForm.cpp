#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), target("default")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm constructor for target " << this->getTarget() << " called" << std::endl;
	return;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("PresidentialPardonForm", 25, 5), target(other.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

// Assignment operator overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm Deconstructor for target '" << this->getTarget() << "' called" << std::endl;
	return;
}

// getters

std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

// setters
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSign() == false)
		throw(AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getGradeExec())
		throw(Bureaucrat::GradeTooLowException());
	else
	{
		std::cout << "By the order of Zaphod Beeblebrox!!!!!!\n"
		<< this->getTarget() << " has been pardoned.";
	}
}

std::ostream &operator<<(std::ostream &stream, const PresidentialPardonForm &form)
{
	stream << "Form '" << form.getName() << "' with sign grade of " << form.getGradeSign() << " and execution grade of " << form.getGradeExec() << ". signed status: " << form.getSignStatus() << ".";
	return (stream);
}