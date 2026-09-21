#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "No input file provided\n";
		return 1;
	}
	BitcoinExchange	bcex;
	bcex.apply(std::string(argv[1]));
	return 0;
}