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

void RPN::calc(const std::string &expr)
{
	std::stringstream ss(expr);
	std::string token;
	double num;

	while (std::getline(ss, token, ' '))
	{
		if (isdigit(token[0]))
		{
			std::stringstream tokenStream(token);
			tokenStream >> num;
			if (tokenStream.fail() || !tokenStream.eof())
				throw InvalidExpr();
			_stack.push(num);
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			double a;
			double b;

			if (_stack.size() < 2)
				throw EmptyStack();

			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			_stack.push(execOperation(a, b, token));
		}
		else
			throw InvalidExpr();
	}
}

double RPN::execOperation(double a, double b, const std::string &op)
{
	if (op == "+")
		return _add(a, b);
	else if (op == "-")
		return _subtract(a, b);
	else if (op == "*")
		return _multiply(a, b);
	else if (op == "/")
		return _divide(a , b);
	throw InvalidExpr();
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
		throw DivisionByZero();
	return (b / a);
}

double RPN::getResult() const
{
	if (_stack.empty())
		throw EmptyStack();
	else if (_stack.size() > 1)
		throw MultiStack();
	return (_stack.top());
}