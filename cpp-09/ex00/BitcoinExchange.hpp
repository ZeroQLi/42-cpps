#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

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
				virtual const char *what() const throw()
				{
					return ("Could not open file.");
				}
		};

		class InvalidColumnFormat : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return ("Invalid column format.");
			}
		};

		class InvalidDateFormat : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return ("Invalid date format. Expected valid 'YYYY-MM-DD'");
			}
		};

		class InvalidPriceFormat : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return ("Invalid price format. Expected number between 0.0 and 1000.0");
			}
		};
};

#endif
