#include <cctype>
#include <string>
#include <iostream>

namespace
{
	std::string	transformToUppercase(std::string str)
	{
		for (std::string::iterator it = str.begin(); it != str.end(); ++it)
			*it = std::toupper(static_cast<unsigned char>(*it));
		return str;
	}

	std::string	truncateSpaces(const std::string &str)
	{
		std::size_t	end;
		std::size_t	begin;

		if (str.empty())
			return "";
		for (begin = 0; str[begin] == ' '; ++begin)
			; // Get begin
		if (!str[begin])
			return std::string();
		for (end = str.size() - 1; str[end] == ' '; --end)
			; // Get end
		return str.substr(begin, end - begin + 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		bool	firstPrinted = false;
		for (int i = 1; i < argc; ++i)
		{
			std::string	str = transformToUppercase(argv[i]);
			str = truncateSpaces(str);
			if (!str.empty())
			{
				if (firstPrinted)
					std::cout << ' ';
				std::cout << str;
				firstPrinted = true;
			}
		}
		std::cout << '\n';
	}
}
