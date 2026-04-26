#include "../includes/ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "ScalarConverter assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

// Check Functions
static int	isSpecial(const std::string &str)
{
	if (str == "nanf" || str == "nan" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return (1);
	return (0);
}

static int isChar(const std::string &str, int &len)
{
	if (len == 1 && !isdigit(str[0]))
		return (1);
	else if (len == 3 && str[0] == '\'' && str[2] == '\'')
		return (1);
	return (0);
}

static int isInt(const std::string &str, int &len)
{
	int flag = 0;
	int i = 0;
	if (str[0] == '-' || str[0] == '+')
		flag = 1;
	while ((str[i] && len > 0 && len < 12) || (str[i] && !flag && len > 0 && len < 11))
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);

}

static int isFloat(const std::string &str, int &len, int dot)
{
	int i = 0;
	int fKey = str.find('f');
	if (fKey == (int) std::string::npos || fKey != len - 1)
		return (0);
	if (dot == (int) std::string::npos || dot == 0 || dot == len - 2)
		return (0);
	if (str[0] == '+' || str[0] == '-')
	{
		i = 1;
		if (dot == 1)
			return (0);
	}
	i = dot + 1;
	while (i < dot)
	{
		if (!isdigit(str[i++]))
			return (0);
	}
	while (i < fKey)
	{
		if (!isdigit(str[i++]))
			return (0);
	}
	return (1);
}

e_type	checkType(const std::string &str, int &len)
{
	size_t	dot = str.find('.');
	size_t	fKey = str.find('f');
	if (dot == std::string::npos)
	{
		if (isSpecial(str))
			return EDGE;
		if (isChar(str, len))
			return CHAR;
		if (isInt(str, len))
			return INT;
	}
	if (dot != std::string::npos)
	{
		if (fKey != std::string::npos)
		{
			if (isFloat(str, len, dot))
				return FLOAT;
		}
		else if (fKey == std::string::npos)
			return DOUBLE;
		
	}
	return INVALID;
}
// print Functions

void	printEdge(const std::string &str)
{
	if (str == "nanf" || str == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	printChar(const std::string &str, int &len)
{
	char c;
	if (len == 1)
		c = str[0];
	else
		c = str[1];
	if (isprint(c))
	{
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
}

void	printInt(const std::string &str)
{
	long i = std::atol(str.c_str());
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(i))
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (i < INT_MIN || i > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}


void	printFloat(const std::string &str)
{
	float f = std::atof(str.c_str());
	if (f < 0 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(f))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (f < INT_MIN || f > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	if (f < FLOAT_MIN || f > FLOAT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	printDouble(const std::string &str)
{
	double d = std::atof(str.c_str());
	if (d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(d))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d < FLOAT_MIN || d > FLOAT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
// Main function
void	ScalarConverter::convert(const std::string &str)
{
	int len = (int) str.length();
	e_type type = checkType(str, len);
	switch (type)
	{
	case INVALID:
		std::cerr << "ERROR: Invalid input" << std::endl;
		break;
	case EDGE:
		printEdge(str);
		break;
	case CHAR:
		printChar(str, len);
		break;
	case INT:
		printInt(str);
		break;
	case FLOAT:
		printFloat(str);
		break;
	case DOUBLE:
		printDouble(str);
		break;
	break;
	}
}