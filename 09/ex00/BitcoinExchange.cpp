#include "BitcoinExchange.hpp"
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <limits>

namespace
{
	std::string	trim(const std::string& s)
	{
		std::string::size_type posLeft = s.find_first_not_of(" ");
		if (posLeft == std::string::npos)
			return "";
		std::string::size_type posRight = s.find_last_not_of(" ");
		return s.substr(posLeft, posRight + 1 - posLeft);
	}

	bool	isLeapYear(int y)
	{
		return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
	}

	void	parseDate(const std::string& date)
	{
		if (date.empty())
			throw std::runtime_error("missing date");
		// YYYY-MM-DD
		if (date.size() != 10
		|| !std::isdigit(date[0]) || !std::isdigit(date[1]) || !std::isdigit(date[2]) || !std::isdigit(date[3])
		|| date[4] != '-' || !std::isdigit(date[5]) || !std::isdigit(date[6])
		|| date[7] != '-' || !std::isdigit(date[8]) || !std::isdigit(date[9]))
			throw std::runtime_error("'" + date + "': bad date format (yyyy-mm-dd)");
		int y = std::atoi(date.c_str());
		int m = std::atoi(date.c_str() + 5);
		int d = std::atoi(date.c_str() + 8);
		// Y/M range
		if (y < 2009)
			throw std::runtime_error("'" + date + "': year predates bitcoin");
		if (m < 1 || m > 12)
			throw std::runtime_error("'" + date + "': bad month");
		// D check
		static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int maxDay = daysInMonth[m - 1];
		if (m == 2 && isLeapYear(y))
			maxDay = 29;
		if (d < 1 || d > maxDay)
			throw std::runtime_error("'" + date + "': bad day");
	}

	void	parseValue(const std::string& val, double& out, double max)
	{
		if (val.empty())
			throw std::runtime_error("missing value");
		if (!std::isdigit(val[0]))
			throw std::runtime_error("'" + val + "': not a positive number");
		char	*trail;
		out = std::strtod(val.c_str(), &trail);
		if (trail[0])
			throw std::runtime_error("'" + val + "': not a positive number");
		if (out > max)
			throw std::runtime_error("'" + val + "': too large a number (max 1000)");
	}

	void	parseDBLine(const std::string& line, std::map<std::string, double>& db)
	{
		try
		{
			std::stringstream	ss(line);
			std::string			token1;
			std::string			token2;
			double				d;
			getline(ss, token1, ',');
			getline(ss, token2);
			parseDate(token1);
			parseValue(token2, d, std::numeric_limits<double>::max());
			if (db.find(token1) != db.end())
				throw std::runtime_error("'" + token1 + "': duplicate date");
			db[token1] = d;
		}
		catch (const std::exception& e)
		{
			std::cerr << "\033[33mWarning\033[0m: " << e.what() << "\n";
		}
	}

	void	parseInputLine(const std::string& line, std::map<std::string, double>& db)
	{
		try
		{
			std::stringstream	ss(line);
			std::string			token1;
			std::string			token2;
			double				d;
			getline(ss, token1, '|');
			getline(ss, token2);
			token1 = trim(token1);
			token2 = trim(token2);
			parseDate(token1);
			parseValue(token2, d, 1000);
			std::map<std::string, double>::iterator it = db.upper_bound(token1);
			if (it != db.begin())
			{
				it--;
				std::cout << it->first << " => " << d << " = \033[36m" << d * it->second << "\033[0m\n";
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << "\033[31mError\033[0m: " << e.what() << "\n";
		}
	}

	void	fillDatabase(std::ifstream& file, std::map<std::string, double>& db)
	{
		std::string line;
		int			i = 0;
		while (std::getline(file, line))
		{
			if (!line.empty() && (i != 0 || line != "date,exchange_rate"))
				parseDBLine(line, db);
			i++;
		}
	}
}

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file;
	file.open("data.csv");
	if (!file)
		std::cerr << "\033[33mWarning\033[0m: database file 'data.csv' could not be opened\n";
	else
		fillDatabase(file, _db);
	if (_db.size() == 0)
		std::cerr << "\033[33mWarning\033[0m: database is empty\n";
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& toCopy) : _db(toCopy._db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& op)
{
	if (this != &op)
		_db = op._db;
	return *this;
}

void	BitcoinExchange::apply(const std::string& input)
{
	std::ifstream	file;
	file.open(input.c_str());
	if (!file)
		std::cerr << "\033[31mError\033[0m: input file '" << input << "' could not be opened\n";
	else
	{
		std::string line;
		int			i = 0;
		while (std::getline(file, line))
		{
			if (!line.empty() && (i != 0 || line != "date | value"))
				parseInputLine(line, _db);
			i++;
		}
	}
}