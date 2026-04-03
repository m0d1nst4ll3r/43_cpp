#ifndef PHONEBOOK
# define PHONEBOOK
# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	// Private members
	Contact		contactList[8];
	int			numContacts = 0;
	void		display();
	std::string	promptUser();
	// Public members
	public:
	PhoneBook(); // Constructor
	bool		add();
	bool		search();
};

PhoneBook::PhoneBook()
{
}

void	PhoneBook::displayTruncated(std::string toDisplay)
{
	size_t	size = toDisplay.size();

	if (size <= 10)
	{
		for (size_t i = 10; i <)
	}
}

// Contents have to be displayed like
// |col|col|col|col|col|
// Each col is 10 chars wide, right aligned
// > 10 chars entries are truncated with '.' for last char
// Total width is 56
void	PhoneBook::display()
{
	std::cout << "/--------------------------------------------------------\\\n";
	std::cout << "|                   PHONEBOOK CONTENTS                   |\n";
	std::cout << "\\--------------------------------------------------------/\n";
	for (int i = 0; i < numContacts; ++i)
	{
		std::cout << "|       " << i;
		std::cout << "|";
		displayTruncated(contactList[i].getFirstName());
		std::cout << "|";
		displayTruncated(contactList[i].getLastName());
		std::cout << "|";
		displayTruncated(contactList[i].getNickName());
		std::cout << "|\n";
	}
}

std::string	PhoneBook::promptUser()
{
	std::string	input;
	while (std::cin >> input)
		if (!input.empty())
			return input;
	return "";
}

// Returns false if cin was closed
bool	PhoneBook::add()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	std::cout << "Please enter new contact info:\n";
	std::cout << "First Name: ";
	firstName = promptUser();
	if (firstName.empty())
		return (false);
	std::cout << "Last Name: ";
	lastName = promptUser();
	if (lastName.empty())
		return (false);
	std::cout << "Nickname: ";
	nickName = promptUser();
	if (nickName.empty())
		return (false);
	std::cout << "Phone Number: ";
	phoneNumber = promptUser();
	if (phoneNumber.empty())
		return (false);
	std::cout << "Darkest Secret: ";
	darkestSecret = promptUser();
	if (darkestSecret.empty())
		return (false);
	if (numContacts < 8)
		numContacts++;
	for (int i = 7; i > 0; --i) // Shift Phonebook
		contactList[i] = contactList[i - 1];
	Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	contactList[0] = newContact;
	std::cout << "Contact was added successfully\n";
	return (true);
}

bool	PhoneBook::search()
{
	display();
	std::cout << "SEARCH TBD\n";
	return true;
}

#endif
