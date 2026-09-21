#include "BitcoinExchange.hpp"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>

namespace
{
	bool	isLeapYear(int y)
	{
		return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
	}

	// Checks for yyyy-mm-dd format, writes result into y, m, d
	// yyyy must be >= 2009 (bitcoin existence)
	// mm must be 01-12
	// dd must be 01-31
	// dd is also checked against month and year (leap year)
	bool	parseDate(const std::string& date, int& y, int& m, int& d)
	{
		// YYYY-DD-MM
		if (date.size() != 10
		|| !std::isdigit(date[0]) || !std::isdigit(date[1]) || !std::isdigit(date[2]) || !std::isdigit(date[3])
		|| date[4] != '-' || !std::isdigit(date[5]) || !std::isdigit(date[6])
		|| date[7] != '-' || !std::isdigit(date[8]) || !std::isdigit(date[9]))
			return false;
		y = std::atoi(date.c_str());
		m = std::atoi(date.c_str() + 5);
		d = std::atoi(date.c_str() + 8);
		// Y/M/D range
		if (y < 2009 || m < 1 || m > 12 || d < 1)
			return false;
		// Month-Day check
		static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int maxDay = daysInMonth[m - 1];
		if (m == 2 && isLeapYear(y))
			maxDay = 29;
		return d <= maxDay;
	}

	// Checks value format, writes result into out
	// Any int/float/double formatting is accepted (including scientific notation e.g 2e3)
	// There can not be any trailing characters
	bool	parseDBValue(const std::string& val, double& out)
	{
		return true;
	}

	// Checks value format, writes result into out
	// Value must be 0-1000
	// Only int formatting is accepted, no trailing characters
	bool	parseInputValue(const std::string& val, int& out)
	{
		return true;
	}

	// Parse line, writes result into map
	// Splits line by ','
	// Passes 1st string to parseDate
	// Passes 2nd string to parseDBValue
	// In case of error, prints a warning
	// Otherwise, adds date-double pair to map
	bool	parseDBLine(const std::string& line, std::map<std::string, double>& map)
	{
		return true;
	}

	// Parse line, writes result to cout/cerr
	// Splits line by '|'
	// Passes 1st string to parseDate
	// Passes 2nd string to parseInputValue
	// In case of error, prints an error to cerr
	// Otherwise, prints result to cout
	bool	parseInputLine(const std::string& line, std::map<std::string, double>& map)
	{
	}

	void	fillDatabase(std::ifstream& file, std::map<std::string, double>& db)
	{
		std::string line;
		while (std::getline(file, line))
		{
			std::cout << "Debug:" << line << "\n";
			parseDBLine(line, db);
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