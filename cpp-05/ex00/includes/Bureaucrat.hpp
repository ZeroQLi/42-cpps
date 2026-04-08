#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		const std::string	name;
		size_t				grade;
		void				setGrade(int num);

	public:
		Bureaucrat(void);
		Bureaucrat(size_t grade);
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, size_t grade);
		
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		size_t				getGrade(void) const;
		const std::string	getName(void) const;

		void				incrementGrade(void);
		void				decrementGrade(void);

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

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &employee);

#endif