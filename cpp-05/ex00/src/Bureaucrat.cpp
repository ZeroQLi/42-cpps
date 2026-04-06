#include "../includes/Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat(void): name("Bob"), grade(75)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(75)
{
	std::cout << "Bureaucrat constructor with name " << name << " called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(size_t grade): name("Bob")
{
	std::cout << "Bureaucrat constructor with grade " << grade << " called" << std::endl;
	try
	{
		this->setGrade(grade);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "ERROR: " << e.what() << '\n' << "Default grade set\n";
		this->setGrade(75);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "ERROR: " << e.what() << '\n' << "Default grade set\n";
		this->setGrade(75);
	}
	return;
}

Bureaucrat::Bureaucrat(std::string name, size_t grade) : name(name)
{
	std::cout << "Bureaucrat constructor with name " << name << " and grade " << grade << " called" << std::endl;
	try
	{
		this->setGrade(grade);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "ERROR: " << e.what() << '\n'
				  << "Default grade set\n";
		this->setGrade(75);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "ERROR: " << e.what() << '\n'
				  << "Default grade set\n";
		this->setGrade(75);
	}
	return;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.getName()), grade(other.getGrade())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	return ;
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
	return ;
}

// Getters
size_t Bureaucrat::getGrade(void) const
{
	return (this->grade);
}
const std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

void Bureaucrat::setGrade(int num)
{
	if (num > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (num < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = num;
}

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
	try
	{
		std::cout << "incrementing grade for " << this->getName() << std::endl;
		this->setGrade(this->getGrade() - 1);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "ERROR: " << e.what() << '\n';
	}
	
}

void Bureaucrat::decrementGrade(void)
{
	try
	{
		std::cout << "decrementing grade for " << this->getName() << std::endl;
		this->setGrade(this->getGrade() + 1);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "ERROR: " << e.what() << '\n';
	}
	
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &employee)
{
	stream << employee.getName() << ", bureaucrat grade " << employee.getGrade() << ".";
	return (stream);
}