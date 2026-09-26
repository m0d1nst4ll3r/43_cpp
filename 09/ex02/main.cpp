#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	(void)argc;
	try
	{
		PmergeMe	obj(argv + 1);
		obj.sort();
	}
	catch (const std::exception& e)
	{
		std::cerr << "\033[31mError\033[0m: " << e.what() << "\n";
	}
}
