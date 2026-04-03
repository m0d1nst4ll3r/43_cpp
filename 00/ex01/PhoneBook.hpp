#ifndef PHONEBOOK
# define PHONEBOOK
# include <iostream>
# include <limits>
# include "Contact.hpp"

class PhoneBook
{
	// Private by default
	Contact		contactList[8];
	int			numContacts = 0;
	void		displayTruncated(std::string toDisplay);
	void		display();
	void		incrementContacts();
	void		shiftContacts();
	bool		promptUser(std::string prompt, std::string &entry);
	bool		promptNewContact(std::string &firstName, std::string &lastName, std::string &nickName, std::string &phoneNumber, std::string &darkestSecret);
	void		addContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
	std::string	promptUser();
	public:
	PhoneBook(){}; // Empty constructor
	bool		add();
	bool		search();
};

// Display single entry, no more than 10 chars, if > 10, truncate with '.'
void	PhoneBook::displayTruncated(std::string toDisplay)
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

// Display all contacts
void	PhoneBook::display()
{
	std::cout << "\x1b[36m";
	std::cout << "/-------------------------------------------\\\n";
	std::cout << "|             PHONEBOOK CONTENTS            |\n";
	std::cout << "|                                           |\n";
	if (!numContacts)
		std::cout << "|           (Phonebook is empty!)           |\n";
	for (int i = 0; i < numContacts; ++i)
	{
		std::cout << "|         " << i;
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

// Doesn't accept empty strings
bool	PhoneBook::promptUser(std::string prompt, std::string &entry)
{
	std::cout << "\x1b[33m" << prompt << "\x1b[0m";
	while (std::cin >> entry)
		if (!entry.empty())
			return true;
	return false;
}

bool	PhoneBook::promptNewContact(std::string &firstName, std::string &lastName, std::string &nickName, std::string &phoneNumber, std::string &darkestSecret)
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

void	PhoneBook::addContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	contactList[0] = newContact;
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
			if (index < 0 || index >= numContacts)
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\x1b[33m" << "Index is out of bounds, try again: " << "\x1b[0m";
			}
			else
			{
				std::cout << "\x1b[32m" << "Contact #" << index << " info:\n" << "\x1b[0m";
				contactList[index].display();
				return true;
			}
		}
	}
}

#endif
