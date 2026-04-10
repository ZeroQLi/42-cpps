#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <fstream>

class Bureaucrat;
class AForm;

class RobotomyRequestForm: public AForm
{
	private:
		const std::string	target;

		RobotomyRequestForm(void);
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		void		execute(Bureaucrat const &executor) const;

		std::string	getTarget(void) const;
};

std::ostream	&operator<<(std::ostream &stream, const RobotomyRequestForm &form);

#endif

