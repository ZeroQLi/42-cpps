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
	std::string		inputFile;
	inputFile = file;
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
			std::cout << "input date error: " << date << "\n";
			continue ;
		}
		if (!value.empty())
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
		// std::cout << date << " | " << multiplier << " | " << it->second << " | " << multiplier * it->second << std::endl;
		std::cout << date << " => " << multiplier << " = " << multiplier * it->second << std::endl;
	else
	{
		itl = charts.lower_bound(date);
		if (itl == charts.begin())
			std::cout << date << " => " << multiplier << " = " << multiplier * itl->second << std::endl;
		else
		{
			itl--;
			std::cout << date << " => " << multiplier << " = " << multiplier * itl->second << std::endl;
		}
	}
}

bool BitcoinExchange::_checkDate(const std::string &date)
{
	std::string year;
	std::string month;
	std::string day;

	if (date.length() != 10)
		return false; // not 10chars long
	if (date[4] != '-' || date[7] != '-')
		return false; // doens't have a dash to seperate year/day/month

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	std::stringstream ss(date);

	std::getline(ss, year, '-');
	std::getline(ss, month, '-');
	std::getline(ss, day, '-');

	if (month[0] == '0' && month[1] == '0')
		return false;
	if ((month[0] == '1' && month[1] > '2') || month[0] > '1')
		return false;
	if (day[0] == '0' && day[1] == '0')
		return false;
	if ((day[0] == '3' && day[1] > '1') || day[0] > '3')
		return (false);
	return true;
}

double BitcoinExchange::_getValue(const std::string &value)
{
	std::stringstream ss(value);
	double		val;

	if (!(ss >> val))
	{
		std::cout << "Error: bad value input => " << val << "\n";
		return (-1);
	}
	if (val < 0)
	{
		std::cout << "Error: not a positive number => " << val << "\n";
		return (-1);
	}
	else if (val > 1000)
	{
		std::cout << "Error: value too large => " << val << "\n";
		return (-1);
	}
	return (val);
}