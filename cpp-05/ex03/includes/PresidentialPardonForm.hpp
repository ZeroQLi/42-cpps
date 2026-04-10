#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm
{
private:
	const std::string target;

	PresidentialPardonForm(void);

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const;

	std::string getTarget(void) const;
};

std::ostream &operator<<(std::ostream &stream, const PresidentialPardonForm &form);

#endif
