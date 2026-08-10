#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange(void)
{
	_dumpDatabase();
	return ;
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(*this) = other;
}

// Assignment operator overload
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		charts = other.charts;
	return (*this);
}

// Destructor
BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

const char *BitcoinExchange::FileError::what() const throw()
{
	return ("Could not open file.");
}

const char *BitcoinExchange::InvalidColumnFormat::what() const throw()
{
	return ("Invalid column format.");
}

const char *BitcoinExchange::InvalidDateFormat::what() const throw()
{
	return ("Invalid date format. Expected valid 'YYYY-MM-DD'");
}

const char *BitcoinExchange::InvalidPriceFormat::what() const throw()
{
	return ("Invalid price format. Expected number between 0.0 and 1000.0");
}

void BitcoinExchange::_dumpDatabase()
{
	std::ifstream	file("data.csv");
	std::string		line;

	if (!file.is_open())
		throw FileError();
	
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw InvalidColumnFormat();

	while (std::getline(file, line))
	{
		std::string	price;
		std::string date;

		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, price, ',');

		if (!_checkDate(date))
			throw InvalidDateFormat();
		double priceVal;
		std::stringstream ps(price);
		if (!(ps >> priceVal))
			throw InvalidPriceFormat();
		charts[date] = priceVal;
	}
	file.close();
}

void BitcoinExchange::readInput(const char *file)
{
	std::string line;

	std::ifstream	input(file);
	if (!input.is_open())
		throw FileError();

	std::getline(input, line);
	if (line != "date | value")
		throw InvalidColumnFormat();

	while (std::getline(input, line))
	{
		std::string	date;
		std::string	value;
		double	multiplier;

		std::stringstream	ss(line);
		std::getline(ss, date, '|');
		std::getline(ss, value, '|');

		if (!date.empty() && *(date.rbegin()) == ' ')
			date = date.erase(date.length() - 1);
		if (!_checkDate(date))
		{
			std::cerr << "input date error: " << date << "\n";
			continue ;
		}
		if (!value.empty() && value[0] == ' ')
			value = value.erase(0, 1);
		multiplier = _getValue(value);
		if (multiplier == -1)
			continue ;
		_printResult(date, multiplier);
	}
	input.close();
}

void BitcoinExchange::_printResult(const std::string &date, double multiplier)
{
	std::map<std::string, double>::iterator it;
	std::map<std::string, double>::iterator itl;

	it = charts.find(date);
	if (it != charts.end())
		std::cout << date << " => " << multiplier << " = " << multiplier * it->second << std::endl;
	else
	{
		itl = charts.lower_bound(date);
		if (itl == charts.begin())
			std::cerr << "Error: no historical data available for date " << date << std::endl;
		else
		{
			itl--;
			std::cout << date << " => " << multiplier << " = " << multiplier * itl->second << std::endl;
		}
	}
}

bool BitcoinExchange::_checkDate(const std::string &date)
{
	std::string yearStr, monthStr, dayStr;

	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	std::stringstream ss(date);

	std::getline(ss, yearStr, '-');
	std::getline(ss, monthStr, '-');
	std::getline(ss, dayStr, '-');

	std::stringstream yy(yearStr), mm(monthStr), dd(dayStr);
	int	year, month, day;

	yy >> year;
	mm >> month;
	dd >> day;

	bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	
	// Validate numeric ranges for month and day
	if (month < 1 || month > 12)
		return false;
	if (day < 1)
		return false;
	if (month == 2)
	{
		if (isLeap)
		{
			if (day > 29)
				return false;
		}
		else
		{
			if (day > 28)
				return false;
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
		return true;
	}
	if (day > 31)
		return false;
	return true;
}

double BitcoinExchange::_getValue(const std::string &value)
{
	std::stringstream ss(value);
	double		val;

	if (!(ss >> val))
	{
		std::cerr << "Error: bad value input\n";
		return (-1);
	}
	if (val < 0)
	{
		std::cerr << "Error: not a positive number => " << val << "\n";
		return (-1);
	}
	else if (val > 1000)
	{
		std::cerr << "Error: value too large => " << val << "\n";
		return (-1);
	}
	return (val);
}