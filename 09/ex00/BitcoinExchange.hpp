#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	public:

	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& toCopy);
	BitcoinExchange& operator=(const BitcoinExchange& op);

	void	apply(const std::string& input);

	private:

	std::map<std::string, double>	_db;
};

#endif /* BITCOINEXCHANGE_HPP */