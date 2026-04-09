#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			gradeSign;
		const int			gradeExec;
		bool				isSigned;
	public:
		Form(void);
		Form(std::string name);
		Form(int gradeSign, int gradeExec);
		Form(std::string name, int gradeSign, int gradeExec);

		Form(const Form& other);
		Form &operator=(const Form &other);
		~Form();

		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		const std::string	getSignStatus(void) const;
		const std::string	getName(void) const;
		bool				getSign(void) const;

		void				beSigned(Bureaucrat &signee);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, const Form &form);

#endif
