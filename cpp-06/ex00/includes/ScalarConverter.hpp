#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <limits>
# include <iomanip>

# define INT_MIN std::numeric_limits<int>::min()
# define INT_MAX std::numeric_limits<int>::max()
# define FLOAT_MIN -std::numeric_limits<float>::max()
# define FLOAT_MAX std::numeric_limits<float>::max()
# define DOUBLE_MIN -std::numeric_limits<double>::max()
# define DOUBLE_MAX std::numeric_limits<double>::max()

enum	e_type {
	EDGE = 0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	INVALID = -1
};

class	ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
	public:
		static void convert(const std::string &str);
};

e_type	checkType(const std::string &str, int &len);
void	printEdge(const std::string &str);
void	printChar(const std::string &str, int &len);
void	printInt(const std::string &str);
void	printFloat(const std::string &str);
void	printDouble(const std::string &str);

#endif

