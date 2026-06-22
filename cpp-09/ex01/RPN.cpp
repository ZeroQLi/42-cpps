#include "RPN.hpp"

// Default constructor
RPN::RPN(void)
{
}

// Copy constructor
RPN::RPN(const RPN &other)
{
	(*this) = other;
}

// Assignment operator overload
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

// Destructor
RPN::~RPN(void)
{
	return ;
}

double RPN::calc(const std::string &expr)
{
	for (size_t i = 0; i < expr.length(); i++)
	{
		if (!isdigit(expr[i]))
		{
			if (expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/' && expr[i] != ' ')
				throw RPN::InvalidExpr();
		}
	}
	std::stringstream ss(expr);
	std::string token;
	double num;

	while (std::getline(ss, token, ' '))
	{
		if (isdigit(token[0]))
		{
			std::stringstream(token) >> num;
			_stack.push(num);
		}
		else
		{
			double a;
			double b;

			if (_stack.size() < 2)
				throw emptyStack();

			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			_stack.push(execOperation(a, b, token));
		}
	}
	return 0;
}

double RPN::execOperation(double a, double b, const std::string &op)
{
	if (op == "+")
		return _add(a, b);
	else if (op == "-")
		return _subtract(a, b);
	else if (op == "*")
		return _multiply(a, b);
	return _divide(a , b);
}

double RPN::_add(double a, double b)
{
	return (b + a);
}

double RPN::_subtract(double a, double b)
{
	return (b - a);
}

double RPN::_multiply(double a, double b)
{
	return (b * a);
}

double RPN::_divide(double a, double b)
{
	if (a == 0)
		throw DivsionByZero();
	return (b / a);
}

double RPN::getResult() const
{
	if (_stack.empty())
		throw emptyStack();
	// else if (_stack.size() > 1)
	// 	throw RPN::invalidArgument("Invalid argument");
	return (_stack.top());
}