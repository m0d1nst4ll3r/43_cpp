#include "BitcoinExchange.hpp"
#include <string>
#include <map>
#include <iostream>
#include <fstream>

namespace
{
	// Checks for yyyy-dd-mm format, writes result into y, m, d
	// yyyy must be >= 2009 (bitcoin existence)
	// dd must be 01-31
	// mm must be 01-12
	// dd is also checked against month and year (leap year)
	bool	parseDate(const std::string& date, int& y, int& m, int& d)
	{
		return true;
	}

	// Checks value format, writes result into out
	// Any int/float/double formatting is accepted (including scientific notation e.g 2e3)
	// There can not be any trailing characters (garbage)
	bool	parseValue(const std::string& val, double& out)
	{
		return true;
	}

	// Parse line, writes result into map
	// Splits line by ','
	// Passes 1st string to parseDate
	// Passes 2nd string to parseValue
	// In case of error, prints a warning
	// Otherwise, adds date-double pair to map
	bool	parseLine(const std::string& line, std::map<std::string, double> map)
	{
		return true;
	}

	void	fillDatabase(std::ifstream& file, std::map<std::string, double> db)
	{
		std::string line;
		while (std::getline(file, line))
		{
			std::cout << "Debug:" << line << "\n";
			parseLine(line, db);
		}
	}
}

// 1. Attempt to open data.csv (if not, db is empty)
// 2. If successful, parse data.csv, adding correct lines
//    Incorrect lines print a WARNING to cerr
BitcoinExchange::BitcoinExchange()
{
	std::ifstream file;
	file.open("data.csv");
	if (!file)
		std::cerr << "WARNING: database file 'data.csv' could not be opened\n";
	else
		fillDatabase(file, _db);
	if (_db.size() == 0)
		std::cerr << "WARNING: database is empty\n";
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

// 1. Attempt to open input file (if not, print error)
// 2. For each line, either print result to cout, or print error to cerr
//    If db is empty, lines are still parsed, just that there is no print for valid lines (errors are still detected)
void	BitcoinExchange::apply(const std::string& input)
{
	(void)input;
}