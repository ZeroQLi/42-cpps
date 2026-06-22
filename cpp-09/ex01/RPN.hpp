#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <cctype>
# include <stack>

class RPN
{
	private:
		std::stack<double> _stack;
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
				virtual const char *what() const throw()
				{
					return ("Invalid expression");
				}
		};

		class DivisionByZero : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Divide by zero");
				}
		};

		class EmptyStack : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid expression: Stack Empty");
				}
		};

		class MultiStack : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid expression: Multiple items in stack");
				}
		};
};

#endif

