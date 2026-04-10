#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const int			gradeSign;
		const int			gradeExec;
		bool				isSigned;
	public:
		AForm(void);
		AForm(std::string name);
		AForm(int gradeSign, int gradeExec);
		AForm(std::string name, int gradeSign, int gradeExec);

		AForm(const AForm& other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		const std::string	getSignStatus(void) const;
		const std::string	getName(void) const;
		bool				getSign(void) const;

		void				beSigned(Bureaucrat &signee);
		virtual void		execute(Bureaucrat const &executor) const = 0;

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
		class FormNotSignedException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, const AForm &form);

#endif
