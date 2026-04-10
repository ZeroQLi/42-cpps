#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>

class Bureaucrat;
class AForm;

class ShrubberyCreationForm: public AForm
{
	private:
		const std::string	target;

		ShrubberyCreationForm(void);
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		void		execute(Bureaucrat const &executor) const;

		std::string	getTarget(void) const;
};

std::ostream	&operator<<(std::ostream &stream, const ShrubberyCreationForm &form);

#endif

