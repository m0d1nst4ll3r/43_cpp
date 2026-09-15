#include "ScalarConverter.hpp"
#include <string>

int	main(int argc, char **argv)
{
	if (argc > 1)
		ScalarConverter::convert(std::string(argv[1]));
	return 0;
}