#include "ScalarConverter.hpp"
#include <string>
#include <cstring>
#include <climits>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cmath>

namespace
{
	// Only display if val is in char range and printable
	void	displayChar(const double val)
	{
		char	toChar = static_cast<char>(val);
		std::cout << "char: ";
		if (val != val || val < CHAR_MIN || floor(val) > CHAR_MAX)
			std::cout << "impossible\n";
		else if (!isprint(toChar))
			std::cout << "non printable\n";
		else
			std::cout << toChar << "\n";
	}

	// Only display if val is in int range
	void	displayInt(const double val)
	{
		int		toInt = static_cast<int>(val);
		std::cout << "int: ";
		if (val != val || val < INT_MIN || floor(val) > INT_MAX)
			std::cout << "impossible\n";
		else
			std::cout << toInt << "\n";
	}

	// If val is a whole number, display the ".0", and always display 'f'
	void	displayFloat(const double val)
	{
		float	toFloat = static_cast<float>(val);
		if (toFloat == floor(toFloat))
		{
			std::ostringstream oss;
			oss << std::fixed << std::setprecision(1) << static_cast<float>(val);
			std::cout << "float: " << oss.str() << "f\n";
		}
		else
			std::cout << "float: " << toFloat << "f\n";
	}

	// If val is a whole number, display the ".0"
	void	displayDouble(const double val)
	{
		if (val == floor(val))
		{
			std::ostringstream oss;
			oss << std::fixed << std::setprecision(1) << val;
			std::cout << "double: " << oss.str() << "\n";
		}
		else
			std::cout << "double: " << val << "\n";
	}

	void	displayValue(const double val)
	{
		displayChar(val);
		displayInt(val);
		displayFloat(val);
		displayDouble(val);
	}

	void	displayImpossible()
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
}

// Converts a string to 4 types: char, int, float, double
//
// If string only contains 1 char that is not a digit, it is considered to be a char
// If string contains any float/double representation of a number, it is a number
// Int overflows are still valid in float/double
// Trailing characters are not accepted (must be clean number representation)
// Leading whitespaces are also not accepted
//
// Any impossible/non printable conversion (e.g int overflow, or nan/inf) simply state so
void	ScalarConverter::convert(const char* str)
{
	char	*trailingChars;
	int		strLen = strlen(str);

	if (strLen == 0) // Empty string -> invalid
		displayImpossible();
	if (strLen == 1 && !isdigit(str[0])) // Only 1 printable non-digit char -> char conversion
		displayValue(static_cast<double>(str[0]));
	else // Double conversion
	{
		double	num = strtod(str, &trailingChars);
		int		trailLen = strlen(trailingChars);
		if (!isspace(str[0]) && (trailLen == 0 || (trailLen == 1 && trailingChars[0] == 'f'))) // Clean number
			displayValue(num);
		else // Trailing char(s) or leading space -> invalid
			displayImpossible();
	}
}