#include "Harl.hpp"
#include <iostream>

int	main()
{
	Harl	harl;

	std::cout << "Debug:\n";
	harl.complain("DEBUG");
	std::cout << "Info:\n";
	harl.complain("INFO");
	std::cout << "Warning:\n";
	harl.complain("WARNING");
	std::cout << "Error:\n";
	harl.complain("ERROR");
}
