#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	public:

	BitcoinExchange(); // Build database from data.csv - database will be empty if data.csv cannot be opened/is empty
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& toCopy);
	BitcoinExchange& operator=(const BitcoinExchange& op);

	void	apply(const std::string& input); // Apply input to database, printing to cout & cerr

	private:

	std::map<std::string, double>	_db;
};

#endif /* BITCOINEXCHANGE_HPP */