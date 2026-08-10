#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <cctype>
# include <string>
# include <map>
# include <stdexcept>
# include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	charts;
		void	_dumpDatabase();
		bool _checkDate(const std::string &date);
		double	_getValue(const std::string &value);
		void	_printResult(const std::string &date, double multiplier);

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	readInput(const char *file);

		class FileError : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InvalidColumnFormat : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class InvalidDateFormat : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class InvalidPriceFormat : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

#endif
