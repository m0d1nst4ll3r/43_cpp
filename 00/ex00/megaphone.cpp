#include <cctype> // toupper
#include <string> // string type & methods
#include <iostream> // cout cin

namespace
{
	const std::string whitespace = " \t\n\r"; // Like a #define in C, but better

	std::string	transformToUppercase(std::string str)
	{
		// Iterator is just another way to iterate in a loop
		for (std::string::iterator it = str.begin(); it != str.end(); ++it)
			*it = std::toupper(static_cast<unsigned char>(*it)); // toupper needs unsigned char param
		return str;
	}

	std::string	trimSpaces(const std::string &str)
	{
		std::size_t start = str.find_first_not_of(whitespace);
		if (start == std::string::npos)
			return "";
		std::size_t end = str.find_last_not_of(whitespace);
		return str.substr(start, end - start + 1);
	}
}

int	main(int argc, char **argv)
{
	bool	firstPrinted = false;
	for (int i = 1; i < argc; ++i)
	{
		std::string	str = transformToUppercase(argv[i]);
		str = trimSpaces(str);
		if (!str.empty())
		{
			if (firstPrinted)
				std::cout << ' ';
			std::cout << str;
			firstPrinted = true;
		}
	}
	if (firstPrinted)
		std::cout << '\n';
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}
