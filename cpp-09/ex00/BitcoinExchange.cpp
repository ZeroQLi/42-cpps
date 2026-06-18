#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange(void)
{
	dumpDatabase();
	return ;
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void) other;
	return ;
}

// Assignment operator overload
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void) other;
	return (*this);
}

// Destructor
BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

void BitcoinExchange::dumpDatabase()
{
	std::ifstream	file("data.csv");
	std::string		line;

	if (!file.is_open())
		return ; // error
	
	std::getline(file, line);
	if (line != "date,exchange_rate")
		return ; // exaact match error
	while (std::getline(file, line))
	{
		std::string	price;
		std::string date;

		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, price, ',');

		double priceVal;
		std::stringstream ps(line);
		if (!(ps >> priceVal))
			return ; // price value invalid error
		charts[date] = priceVal;
	}
	file.close();
}