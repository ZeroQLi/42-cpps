#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

// Default constructor
Bureaucrat::Bureaucrat(void) : name("Bob"), grade(75)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(75)
{
	std::cout << "Bureaucrat constructor with name " << name << " called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : name("Bob")
{
	std::cout << "Bureaucrat constructor with grade " << grade << " called" << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	std::cout << "Bureaucrat constructor with name " << name << " and grade " << grade << " called" << std::endl;
	this->setGrade(grade);
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()), grade(other.getGrade())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &other)
		this->grade = other.getGrade();
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << name << " terminated" << std::endl;
}

// Getters
int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}
const std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

// Setters
void Bureaucrat::setGrade(int num)
{
	if (num > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (num < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = num;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		std::cerr << "SIGNING FAILED: " << e.what() << '\n';
	}
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
	}
	catch (const std::exception &e)
	{
		std::cerr << "EXECUTION FAILED: " << e.what() << '\n';
	}
}

// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void Bureaucrat::incrementGrade(void)
{
	this->setGrade(this->getGrade() - 1);
}

void Bureaucrat::decrementGrade(void)
{
	this->setGrade(this->getGrade() + 1);
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &employee)
{
	stream << employee.getName() << ", bureaucrat grade " << employee.getGrade() << ".";
	return (stream);
}