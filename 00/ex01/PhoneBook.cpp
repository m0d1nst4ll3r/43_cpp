#include "PhoneBook.hpp"

namespace
{
	const std::string	whitespace = " \t\n\r";

	// Trim input of whitespaces, reject blank input
	bool	trimAndValidate(std::string &entry)
	{
		std::size_t start = entry.find_first_not_of(whitespace);
		if (start == std::string::npos)
			return false; // Reject blank input
		std::size_t end = entry.find_last_not_of(whitespace);
		entry = entry.substr(start, end - start + 1);
		return true;
	}

	// Display single entry, no more than 10 chars, if > 10, truncate with '.'
	void	displayTruncated(const std::string &toDisplay)
	{
		size_t	size = toDisplay.size();

		if (size <= 10)
		{
			for (; size < 10; ++size)
				std::cout << ' ';
			std::cout << toDisplay;
		}
		else
			std::cout << toDisplay.substr(0, 9) << '.';
	}

	// Doesn't accept empty strings
	bool	promptUser(const std::string &prompt, std::string &entry)
	{
		std::cout << "\x1b[33m" << prompt << "\x1b[0m";
		while (std::getline(std::cin, entry))
			if (trimAndValidate(entry))
				return true;
		return false;
	}

	bool	promptNewContact(std::string &firstName, std::string &lastName, std::string &nickName, std::string &phoneNumber, std::string &darkestSecret)
	{
		if (!promptUser("First Name: ", firstName))
			return false;
		if (!promptUser("Last Name: ", lastName))
			return false;
		if (!promptUser("Nickname: ", nickName))
			return false;
		if (!promptUser("Phone Number: ", phoneNumber))
			return false;
		if (!promptUser("Darkest Secret: ", darkestSecret))
			return false;
		return true;
	}
}

PhoneBook::PhoneBook()
{
	numContacts = 0;
}

void	PhoneBook::addContact(const std::string &firstName, const std::string &lastName, const std::string &nickName, const std::string &phoneNumber, const std::string &darkestSecret)
{
	Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	contactList[0] = newContact;
}

// [0 -> 1], [1 -> 2], etc...
void	PhoneBook::shiftContacts()
{
	for (int i = 7; i > 0; --i)
		contactList[i] = contactList[i - 1];
}

void	PhoneBook::incrementContacts()
{
	if (numContacts < 8)
		numContacts++;
}

// Display all contacts
void	PhoneBook::display()
{
	std::cout << "\x1b[36m";
	std::cout << "/-------------------------------------------\\\n";
	std::cout << "|             PHONEBOOK CONTENTS            |\n";
	std::cout << "|                                           |\n";
	if (!numContacts)
		std::cout << "|           (Phonebook is empty!)           |\n";
	else
		std::cout << "|     Index|First Name| Last Name|   Surname|\n"
		<< "|----------|----------|----------|----------|\n";
	for (int i = 0; i < numContacts; ++i)
	{
		std::cout << "|         " << i + 1;
		std::cout << "|";
		displayTruncated(contactList[i].getFirstName());
		std::cout << "|";
		displayTruncated(contactList[i].getLastName());
		std::cout << "|";
		displayTruncated(contactList[i].getNickName());
		std::cout << "|\n";
	}
	std::cout << "\\-------------------------------------------/\n";
	std::cout << "\x1b[0m";
}

// Returns false if cin was closed (Ctrl+D)
bool	PhoneBook::add()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	std::cout << "\x1b[32m" << "Please enter new contact info:\n" << "\x1b[0m";
	if (!promptNewContact(firstName, lastName, nickName, phoneNumber, darkestSecret))
		return false;
	incrementContacts();
	shiftContacts();
	addContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	std::cout << "\x1b[32m" << "Contact was added successfully\n" << "\x1b[0m";
	return true;
}

// Returns false if cin was closed (Ctrl+D)
bool	PhoneBook::search()
{
	int	index;
	display();
	if (!numContacts)
		return true;
	std::cout << "\x1b[32m" << "Please enter contact index: " << "\x1b[0m";
	while (1)
	{
		if (!(std::cin >> index))
		{
			if (std::cin.eof())
				return false;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\x1b[33m" << "Not a number, try again: " << "\x1b[0m";
		}
		else
		{
			if (index < 1 || index > numContacts)
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\x1b[33m" << "Index is out of bounds, try again: " << "\x1b[0m";
			}
			else
			{
				std::cout << "\x1b[32m" << "Contact #" << index << " info:\n" << "\x1b[0m";
				contactList[index - 1].display();
				return true;
			}
		}
	}
}
