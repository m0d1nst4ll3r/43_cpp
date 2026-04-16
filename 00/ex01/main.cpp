#include "PhoneBook.hpp"
#include <iostream>

int	main()
{
	PhoneBook	phonebook;
	std::string	input;
	std::cout << "\x1b[32m" << "Welcome to the 📞PhoneBook📖\nCommands: ADD, SEARCH, EXIT\n" << "\x1b[0m";
	while (std::getline(std::cin, input))
	{
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			if (!phonebook.add())
				break;
		}
		else if (input == "SEARCH")
		{
			if (!phonebook.search())
				break ;
		}
	}
	return 0;
}
