#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm constructor for target " << this->getTarget() << " called" << std::endl;
	return;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("RobotomyRequestForm", 72, 45), target(other.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

// Assignment operator overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm Deconstructor for target '" << this->getTarget() << "' called" << std::endl;
	return;
}

// getters

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

// setters
static int failure_rate = 0;

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSign() == false)
		throw(AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getGradeExec())
		throw(Bureaucrat::GradeTooLowException());
	else if (failure_rate++ % 2)
		std::cout << "BRRRRRRRRRRRRRR\n" << this->getTarget() << " was robotomized successfully." << std::endl;
	else
		std::cout << "BRRRRRRRRRRJWEIOFHEWUIFHWEUFW ZAAAA\n" <<  this->getTarget() << "'s robotmy failed." << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const RobotomyRequestForm &form)
{
	stream << "Form '" << form.getName() << "' with sign grade of " << form.getGradeSign() << " and execution grade of " << form.getGradeExec() << ". signed status: " << form.getSignStatus() << ".";
	return (stream);
}