#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor for target " << this->getTarget() << " called" << std::endl;
	return;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm("ShrubberyCreationForm", 145, 137), target(other.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

// Assignment operator overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Deconstructor for target '" << this->getTarget() << "' called" << std::endl;
	return ;
}

// getters

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

// setters

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSign() == false)
		throw(AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getGradeExec())
		throw(Bureaucrat::GradeTooLowException());
	else
	{
		std::ofstream outfile(this->getTarget().append("_shrubbery").c_str());
		if (!outfile)
			return;
		outfile << "                                                             &&& &&  & &&" << std::endl
				<< "             ccee88oo              oxoxoo    ooxoo      && &\\/&\\|& ()|/ @, &&" << std::endl
				<< "          C8O8O8Q8PoOb o8oo      ooxoxo oo  oxoxooo     &\\/(/&/&||/& /_/)_&/_&" << std::endl
				<< "         dOB69QO8PdUOpugoO9bD   oooo xxoxoo ooo ooox  &() &\\/&|()|/&\\/ '%\" & ()" << std::endl
				<< "        CgggbU8OU qOp qOdoUOdcb oxo o oxoxo  xoxxoxo &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl
				<< "            6OuU  /p u gcoUodpP  oxo xooxoooo o ooo &&   && & &| &| /& & % ()& /&&" << std::endl
				<< "              \\\\\\//  /douUP        ooo\\oo\\  /o/o     ()&_---()&\\&\\|&&-&&--%---()~" << std::endl
				<< "                \\\\\\////                \\  \\/ /           &&     \\|||" << std::endl
				<< "                 |||/\\                  |   /                    |||" << std::endl
				<< "                 |||\\/                  |  |                     |||" << std::endl
				<< "                 |||||                  | D|                     |||" << std::endl
				<< "           .....//||||\\....             |  |               , -=-~  .-^- _" << std::endl
				<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ /~~\\ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		outfile.close();
	}
}

std::ostream	&operator<<(std::ostream &stream, const ShrubberyCreationForm &form)
{
	stream << "Form '" << form.getName() << "' with sign grade of " << form.getGradeSign() << " and execution grade of " << form.getGradeExec() << ". signed status: " << form.getSignStatus() << ".";
	return (stream);
}