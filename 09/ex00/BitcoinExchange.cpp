#include "BitcoinExchange.hpp"
#include <string>
#include <map>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
	// 1. Attempt to open data.csv (if not, db is empty)
	// 2. If successful, parse data.csv, adding correct lines
	//    Incorrect lines print a WARNING to cerr
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& toCopy) : _db(toCopy._db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& op)
{
	if (this != &op)
	{
		_db = op._db;
	}
	return *this;
}

void	BitcoinExchange::apply(const std::string& input)
{
	// 1. Attempt to open input file (if not, print error)
	// 2. For each line, either print result to cout, or print error to cerr
	//    If db is empty, lines are still parsed, just that there is no print for valid lines (errors are still detected)
}