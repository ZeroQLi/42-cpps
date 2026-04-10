#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

// constructors
AForm::AForm(void): name("G207"), gradeSign(50), gradeExec(25), isSigned(false)
{
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(std::string name): name(name), gradeSign(50), gradeExec(25), isSigned(false)
{
	std::cout << "AForm constructor with name " << name << " called" << std::endl;
}

AForm::AForm(int gradeSign, int gradeExec): name("G207"), gradeSign(gradeSign), gradeExec(gradeExec), isSigned(false)
{
	int	i;
	int	j;

	std::cout << "AForm constructor with signed grade of " << gradeSign << " and execution grade of " << gradeExec << " called" << std::endl;
	i = this->getGradeSign();
	j = this->getGradeExec();
	if (i > 150 || j > 150)
		throw(AForm::GradeTooLowException());
	else if (i < 1 || j < 1)
		throw(AForm::GradeTooHighException());
}

AForm::AForm(std::string name, int gradeSign, int gradeExec): name(name), gradeSign(gradeSign), gradeExec(gradeExec), isSigned(false)
{
	int	j;
	int	i;

	std::cout << "AForm constructor with name " << name << ", signed grade of " << gradeSign << " and execution grade of " << gradeExec << " called" << std::endl;
	i = this->getGradeSign();
	j = this->getGradeExec();
	if (i > 150 || j > 150)
		throw(AForm::GradeTooLowException());
	else if (i < 1 || j < 1)
		throw(AForm::GradeTooHighException());
}

// Copy constructor
AForm::AForm(const AForm &other): name(other.getName()), gradeSign(other.getGradeSign()), gradeExec(other.getGradeExec()), isSigned(other.getSign())
{
	std::cout << "AForm copy constructor called" << std::endl;
}

// Assignment operator overload
AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

// Destructor
AForm::~AForm(void)
{
	std::cout << "AForm Deconstructor for " << this->getName() << " called" << std::endl;
}

// Getters
int	AForm::getGradeSign(void) const
{
	return (this->gradeSign);
}

int	AForm::getGradeExec(void) const
{
	return (this->gradeExec);
}
const std::string	AForm::getName(void) const
{
	return (this->name);
}
bool	AForm::getSign(void) const
{
	return (this->isSigned);
}

// Setters
void	AForm::beSigned(Bureaucrat &signee)
{
	if (signee.getGrade() > this->getGradeSign())
		throw(GradeTooLowException());
	else if (!this->getSign())
	{
		this->isSigned = true;
		std::cout << "AForm '" << this->getName() << "' was signed by bureaucrat " << signee.getName() << ".\n";
	}
	else
		std::cout << "AForm '" << this->getName() << "' already signed\n";
}

const std::string	AForm::getSignStatus(void) const
{
	if (this->isSigned)
		return ("✓ true");
	return ("✕ false");
}

void	AForm::execute(Bureaucrat const &executor) const
{
	(void) executor;
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

std::ostream	&operator<<(std::ostream &stream, const AForm &form)
{
	stream << "AForm '" << form.getName() << "' with sign grade of " << form.getGradeSign() << " and execution grade of " << form.getGradeExec() << ". signed status: " << form.getSignStatus() << ".";
	return (stream);
}