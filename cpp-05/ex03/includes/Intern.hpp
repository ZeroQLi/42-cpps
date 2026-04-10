#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

class AForm;
class Bureaucrat;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class Intern
{
	private:

	public:
		Intern(void);
		Intern(const Intern& other);
		Intern &operator=(const Intern &other);
		~Intern();

		AForm	*makeForm(const std::string form, const std::string target);
};

#endif

