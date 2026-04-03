#include "PhoneBook.hpp"
#include <iostream>

int	main()
{
	PhoneBook	phonebook;
	std::string	input;
	std::cout << "Welcome to the 📞PhoneBook📖\nCommands: ADD, SEARCH, EXIT\n";
	while (std::cin >> input)
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
}
