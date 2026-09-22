#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "\033[31mError\033[0m: No argument provided\n";
		return 1;
	}
	if (argc > 2)
	{
		std::cout << "\033[31mError\033[0m: Too many arguments\n";
		return 1;
	}
	try
	{
		RPN	rpn(argv[1]);
		//rpn.display();
		std::cout << rpn.calculate() << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "\033[31mError\033[0m: " << e.what() << "\n";
	}
	return 0;
}
