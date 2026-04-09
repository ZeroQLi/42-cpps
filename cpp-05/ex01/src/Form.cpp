#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

// constructors
Form::Form(void): name("G207"), gradeSign(50), gradeExec(25), isSigned(false)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name): name(name), gradeSign(50), gradeExec(25), isSigned(false)
{
	std::cout << "Form constructor with name " << name << " called" << std::endl;
}

Form::Form(int gradeSign, int gradeExec): name("G207"), gradeSign(gradeSign), gradeExec(gradeExec), isSigned(false)
{
	int	i;
	int	j;

	std::cout << "Form constructor with signed grade of " << gradeSign << " and execution grade of " << gradeExec << " called" << std::endl;
	i = this->getGradeSign();
	j = this->getGradeExec();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if (i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(std::string name, int gradeSign, int gradeExec): name(name), gradeSign(gradeSign), gradeExec(gradeExec), isSigned(false)
{
	int	j;
	int	i;

	std::cout << "Form constructor with name " << name << ", signed grade of " << gradeSign << " and execution grade of " << gradeExec << " called" << std::endl;
	i = this->getGradeSign();
	j = this->getGradeExec();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if (i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

// Copy constructor
Form::Form(const Form &other) : name(other.getName()), gradeSign(other.getGradeSign()), gradeExec(other.getGradeExec()), isSigned(other.getSign())
{
	std::cout << "Form copy constructor called" << std::endl;
}

// Assignment operator overload
Form &Form::operator=(const Form &other)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
		*this = other;
	return (*this);
}

// Destructor
Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;

}

// Getters
int	Form::getGradeSign(void) const
{
	return (this->gradeSign);
}

int	Form::getGradeExec(void) const
{
	return (this->gradeExec);
}
const std::string	Form::getName(void) const
{
	return (this->name);
}
bool	Form::getSign(void) const
{
	return (this->isSigned);
}

// Setters
void	Form::beSigned(Bureaucrat &signee)
{
	if (signee.getGrade() > this->getGradeSign())
		throw(GradeTooLowException());
	else if (!this->getSign())
	{
		this->isSigned = true;
		std::cout << "Form '" << this->getName() << "' was signed by bureaucrat " << signee.getName() << ".\n";
	}
	else
		std::cout << "Form '" << this->getName() << "' already signed\n";
}

const std::string	Form::getSignStatus(void) const
{
	if (this->isSigned)
		return ("✓ true");
	return ("✕ false");
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream	&operator<<(std::ostream &stream, const Form &form)
{
	stream << "Form '" << form.getName() << "' with sign grade of " << form.getGradeSign() << " and execution grade of " << form.getGradeExec() << ". signed status: " << form.getSignStatus() << ".";
	return (stream);
}