#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <cctype>
# include <list>
# include <string>

class RPN
{
	private:
		std::list<double> _stack;
		double execOperation(double a, double b, const std::string &op);

		double	_add(double a, double b);
		double	_subtract(double a, double b);
		double	_multiply(double a, double b);
		double	_divide(double a, double b);

	public:
		RPN(void);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void calc(const std::string &expr);
		double getResult() const;
		class InvalidExpr : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class DivisionByZero : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class EmptyStack : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class MultiStack : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif