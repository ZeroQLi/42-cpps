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
};

#endif
